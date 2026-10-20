const fastify = require('fastify')({logger: false});
const oauthPlugin = require('@fastify/oauth2');
const path = require('path');
const {getEnvFromVault} = require('./utils/vault');
// const { Server } = require('socket.io');
require('dotenv').config();

let envVars = {};


fastify.register(require('@fastify/cors'), {
	origin:
	[
		"https://accounts.google.com",
		"http://localhost"
	],
	allowedHeaders: ["Content-Type", "Authorization"],
	methods: ["GET", "POST", "PUT", "DELETE", "OPTIONS"],
	credentials: true,
});


fastify.register(require('@fastify/cookie'));

fastify.register(require('@fastify/multipart'), {
	limits: {
		fileSize: 2 * 1024 * 1024, // 2 MB max
	},
});

fastify.register(require('@fastify/static'), {
	root: path.join(__dirname, 'uploads'),
	prefix: '/uploads/',
	decorateReply: false // decorateReply: true (default) → adds a shortcut method: reply.sendFile('avatar.png') decorateReply: false → no shortcut.
});

fastify.register(require('./plugins/authPlugin'));

// Register unified socket service (handles both chat and game)
fastify.register(require('./socket'));
fastify.register(require('./chat/socket'));
fastify.register(require('./game/socket'));
// Remove the separate game socket registration since we'll use namespaces


// Routes
fastify.register(require('./routes/authRoutes'), {prefix: '/api/auth'});
fastify.register(require('./routes/userRoutes'), {prefix: '/api'});
fastify.register(require('./routes/notificationRoutes'), {prefix: '/api'});

const start = async function () {
	try {
		envVars = await getEnvFromVault()

		fastify.register(oauthPlugin, {
			name: 'googleOAuth2',
			scope: ['openid', 'email', 'profile'],
			credentials: {
			client: {
				id: envVars.GOOGLE_CLIENT_ID,
				secret: envVars.GOOGLE_CLIENT_SECRET
			},
			auth: require('@fastify/oauth2').GOOGLE_CONFIGURATION
			},
			startRedirectPath: '/api/login/google',
			callbackUri: (request) => {
				return `https://ft-transcendence.42.fr/api/auth/login/google/callback`;
			},
			cookie: {
				secure: true, // Set to true in production with HTTPS
				sameSite: 'lax', // 'lax' is often better for OAuth redirects than 'strict'
				path: '/'
			}
		});


		const address = await fastify.listen({ port: envVars.PORT, host: envVars.HOST })
		fastify.log.info(`Server listening at ${address}`)
	} catch (error) {
		fastify.log.error(error);
		process.exit(1);
	}
}

start();
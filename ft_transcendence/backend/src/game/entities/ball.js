const { Point, randomrange } = require("./point");

class Ball {
    constructor( position, radius ) {
        this.position = position;
        this.radius = radius;
        this.direction = new Point( -1, 1 );
        // this.direction = new Point( randomrange(-1, 1), randomrange(-1, 1) );
        // let length = Math.sqrt(this.direction.x**2 + this.direction.y**2);
        // this.direction.x /= length;
        // this.direction.y /= length;
        this.speed = 8;
        this.velocity = new Point( this.direction.x * this.speed, this.direction.y * this.speed );
    }
}

module.exports = { Ball };
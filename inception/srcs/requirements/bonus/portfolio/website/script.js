var currYear = new Date();
document.getElementById("cpr").innerText = "All rights reserved © Aissam " + currYear.getFullYear();
fetch('skills.json').then(response => response.json()).then(json => {
	const template = document.getElementById("skillsTemplate");
	const templateContent = template.content;
	const card = templateContent.querySelector(".skillCard");
	const skillsSection = document.getElementById("skills");
	for (let data of json) {
		card.querySelector(".icon").src = data.icon;
		// card.querySelector(".progress").value = data.percentage;
		// const progress = card.querySelector(".progress");
		// progress.value = data.percentage;
		// progress.style.color = 'red';
		// const percentage = card.querySelector('.percentage');
		// percentage.textContent = data.percentage + "%";

		const clonedContent = document.importNode(templateContent, true);

		const clonedCard = clonedContent.querySelector(".skillCard");
		clonedCard.addEventListener('click', () => {
			window.open (data.link, '_blank');
		});
		skillsSection.appendChild(clonedContent);
	}
});

const twitter = document.getElementById('twitter');
twitter.addEventListener('click', function () {
	window.open ('https://twitter.com/aabouqas', '_blank');
});

const threads = document.getElementById('threads');
threads.addEventListener('click', function () {
	window.open ('https://www.threads.net/@aabouqas', '_blank');
});

document.getElementById('github').addEventListener('click', function () {
	window.open ('https://github.com/aabouqas', '_blank');
});

const fb = document.getElementById('fb');
fb.addEventListener('click', function () {
	window.open ('https://www.facebook.com/el.qassimi.54', '_blank');
});


const sections = document.querySelectorAll('section');

sections.forEach ((sections, index) => {
	if (index % 2)
		sections.style.backgroundColor = '#1B1B1B'
});

fetch('projects/projects.json').then(response => response.json()).then(json => {
	const template = document.getElementById("projectTemplate");
	const templateContent = template.content;
	const card = templateContent.querySelector(".projectCard");
	for (data of json) {
		card.querySelector(".projectName").textContent = data.name;
		card.querySelector(".projectDescription").textContent = data.description;
		// card.querySelector(".projectCover").src = data.cover;
		card.querySelector(".projectEvent").href = data.link;
		// let projectCover = card.querySelector(".projectCard");
		card.style.backgroundImage = `linear-gradient(to bottom, transparent 0%, black 95%), url('${data.cover}')`;
		card.style.backgroundSize = "100% 60%";
		card.style.backgroundRepeat = "no-repeat";
		card.style.backgroundPosition = "top";
		const clonedContent = document.importNode(templateContent, true);
		const projectsSection = document.getElementById("projects");
		projectsSection.appendChild(clonedContent);
	}
});

const bioData = [
	{text: "Hey! my name is ", link: null},
	{text: "Aissam Abouqassime-Eledrissi", link: "#"},
	{text: ". I am a student in ", link: null},
	{text: "computer science", link: "https://en.wikipedia.org/wiki/Computer_science"},
	{text: " at ", link: null },
	{text: "1337", link: "https://1337.ma/en/" },
	{text: " Coding School, I enjoy building mobile apps and continuously improving my skills. Currently, I'm working on ", link: null },
	{text: "Volern", link: "#projects" },
	{text: ", an app that helps Arabic speakers expand their English vocabulary.", link: null }
]

const bioElement = document.getElementById("bio")

for (const item of bioData) {
	const span = document.createElement(item.link != null ? "a" : "span");
	span.textContent = item.text;
	if (item.link != null) {
		span.href = item.link;
		span.classList.add("link");
		if (item.text != "Aissam Abouqassime-Eledrissi" && item.text != "Volern")
			span.target = "_blank";
	}
	bioElement.appendChild(span)
}

const explore = document.getElementById("explore");
explore.addEventListener('click', function () {
	window.open ("#projectsSection", "_self");
});
const fileContent = document.getElementById("fileContent");
fetch("BirthdaysPrivacyPolicy.txt").then((res) => res.text()).then((text) => {
	fileContent.textContent = text;
}).catch((e) => console.error(e));
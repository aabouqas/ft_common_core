const fileContent = document.getElementById("fileContent");
fetch("content.json").then((res) => res.text()).then((text) => {
	const json = JSON.parse(text);
	// json.priva
	// console.log(json.privacy_policy);
	const privacy_policy = json["privacy_policy"];
	const sections = privacy_policy.sections
	let content = "";
	content += `<header>Volern Privacy Policy</header>`
	content += `<h5 id="intro">${privacy_policy["introduction"]}</h5>`
	for (let i = 0; i < sections.length; i++) {
		if (i === 0) {
			// const span = sections[i]["content"].at()
			const link = "https://payments.google.com/payments/apis-secure/u/0/get_legal_document?ldo=0&ldt=privacynotice&ldl=en-GB"
			content += `<section>\
				<h3>${sections[i]["title"]}</h3>\
				<h5>${sections[i]["content"]}  Please refer to the <a href="${link}" target="_blank">privacy policy </a> of the payment provider for more information.</h5>\
			</section>`;
		} else if (i === (sections.length - 1)) {
			const link = "mailto:abouqassimeledrissi@gmail.com"
			content += `<section>\
				<h3>${sections[i]["title"]}</h3>\
				<h5>${sections[i]["content"]} <a href="${link}" target="_blank">abouqassimeledrissi@gmail.com</a></h5>\
			</section>`;
		} else {
			content += `<section>\
				<h3>${sections[i]["title"]}</h3>\
				<h5>${sections[i]["content"]}</h5>\
			</section>`;
		}
	}
	content += `<footer>Last modified : ${privacy_policy["modification_date"]}</footer>`
	fileContent.innerHTML = content

}).catch((e) => console.error(e));
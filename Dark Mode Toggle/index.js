const inputEl = document.querySelector(".input");
const bodyEl = document.querySelector("body");

inputEl.checked = JSON.parse(localStorage.getItem("mode"));

updateBody();

function updateBody() {
    if (inputEl.checked) {
        bodyEl.classList.remove("light-mode");
        bodyEl.classList.add("dark-mode");
    } else {
        bodyEl.classList.remove("dark-mode");
        bodyEl.classList.add("light-mode");
    }
}

inputEl.addEventListener("input", () => {
    updateBody();
    updateLocalStorage();
});

function updateLocalStorage() {
    localStorage.setItem("mode", JSON.stringify(inputEl.checked));
}
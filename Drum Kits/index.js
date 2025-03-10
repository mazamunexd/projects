const kits = [
    "crash",
    "kick",
    "snare",
    "tom",
    "bass-drum",
    "ride-cymbal",
    "hi-hat",
  ];
  
  const containerEl = document.querySelector(".container");
  
  kits.forEach((kit) => {
    const btnEl = document.createElement("button");
    btnEl.classList.add("btn");
    btnEl.innerText = kit.replace(/-/g, " ");
    btnEl.style.backgroundImage = `url(images/${kit}.png)`;
    containerEl.appendChild(btnEl);
  
    const audioEl = document.createElement("audio");
    audioEl.src = `sounds/${kit}.mp3`;
    containerEl.appendChild(audioEl);
  
    btnEl.addEventListener("click", () => {
      audioEl.currentTime = 0;
      audioEl.play();
    });
  
    window.addEventListener("keydown", (event) => {
      if (event.key === kit.slice(0, 1)) {
        audioEl.currentTime = 0;
        audioEl.play();
        btnEl.style.transform = "scale(0.9)";
        setTimeout(() => {
          btnEl.style.transform = "";
        }, 100);
      }
    });
  });
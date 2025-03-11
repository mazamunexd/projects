const nextEl = document.querySelector(".next");
const prevEl = document.querySelector(".prev");
const imageContainerEl = document.querySelector(".image-container");

let currentImg = 1;
let timeout;
let images = [];

// Generate 1000 random images
for (let i = 0; i < 1000; i++) {
  const img = document.createElement("img");
  img.src = `https://picsum.photos/500/300?random=${i}`;
  imageContainerEl.appendChild(img);
  images.push(img);
}

nextEl.addEventListener("click", () => {
  currentImg++;
  clearTimeout(timeout);
  updateImg();
});

prevEl.addEventListener("click", () => {
  currentImg--;
  clearTimeout(timeout);
  updateImg();
});

updateImg();

function updateImg() {
  if (currentImg > images.length) {
    currentImg = 1;
  } else if (currentImg < 1) {
    currentImg = images.length;
  }
  imageContainerEl.style.transform = `translateX(-${(currentImg - 1) * 500}px)`;
  timeout = setTimeout(() => {
    currentImg++;
    updateImg();
  }, 3000);
}
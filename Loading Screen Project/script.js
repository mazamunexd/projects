let images = [
    "images/1.jpg",
    "images/2.jpg",
    "images/3.jpg",
    "images/4.jpg",
    "images/5.jpg"
];

let currentImageIndex = 0;
let loadingImage = document.getElementById("loading-image");
let backgroundMusic = document.getElementById("background-music");
let loadingText = document.getElementById("loading-text");

function showImage() {
    loadingImage.src = images[currentImageIndex];
    loadingImage.style.display = "block";
    loadingImage.style.opacity = 0;
    setTimeout(() => {
        loadingImage.style.opacity = 1;
    }, 0);
    setTimeout(() => {
        loadingImage.style.opacity = 0;
        currentImageIndex = (currentImageIndex + 1) % images.length;
        showImage();
    }, 4000);
}

showImage();

// Play the music muted initially
backgroundMusic.play().catch(error => {
    console.error("Autoplay was prevented:", error);
});

// Add click event to loading text to play audio
loadingText.addEventListener('click', () => {
    backgroundMusic.muted = false; // Unmute the music
    backgroundMusic.play().catch(error => {
        console.error("Playback failed:", error);
    });
});
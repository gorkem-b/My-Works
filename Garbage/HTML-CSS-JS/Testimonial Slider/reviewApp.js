document.addEventListener('DOMContentLoaded', () => {
    // DOM Elements
    const mainImage = document.getElementById('img');
    const authorElem = document.getElementById('author');
    const jobElem = document.getElementById('job');
    const textElem = document.getElementById('text');
    const prevBtn = document.getElementById('prev-btn');
    const nextBtn = document.getElementById('next-btn');
    const randomBtn = document.getElementById('random-btn');

    // Guard clause: exit if any element is missing
    if (![mainImage, authorElem, jobElem, textElem, prevBtn, nextBtn, randomBtn].every(Boolean)) {
        console.error('One or more required DOM elements are missing. Please check your HTML IDs.');
        return;
    }

    let currentIndex = 0;

    // Render review at given index
    function renderReview(index) {
        const { img, author, job, text } = reviews[index];
        mainImage.src = img;
        authorElem.textContent = author;
        jobElem.textContent = job;
        textElem.textContent = text;
    }

    // Initial render
    renderReview(currentIndex);

    // Event listeners
    nextBtn.addEventListener('click', () => {
        currentIndex = (currentIndex + 1) % reviews.length;
        renderReview(currentIndex);
    });

    prevBtn.addEventListener('click', () => {
        currentIndex = (currentIndex - 1 + reviews.length) % reviews.length;
        renderReview(currentIndex);
    });

    randomBtn.addEventListener('click', () => {
        let randomIndex;
        do {
            randomIndex = Math.floor(Math.random() * reviews.length);
        } while (randomIndex === currentIndex && reviews.length > 1);
        currentIndex = randomIndex;
        renderReview(currentIndex);
    });
});
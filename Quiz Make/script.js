// Select all elements for wrong and right answers
const wrongAnswerBoxes = document.querySelectorAll('.box');
const rightAnswerBoxes = document.querySelectorAll('.rightBox');

// Add click event to mark wrong answers
wrongAnswerBoxes.forEach(box => {
    box.addEventListener('click', () => {
        box.classList.add('wrong');
    });
});

// Add click event to mark right answers
rightAnswerBoxes.forEach(box => {
    box.addEventListener('click', () => {
        box.classList.add('right');
    });
});

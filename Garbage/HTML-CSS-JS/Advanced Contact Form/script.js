// Get DOM elements
const closeBtn = document.getElementById('close');
const alertBox = document.getElementById('alertBox');
const form = document.getElementById('form');
const confirmBtn = document.getElementById('confirm');
const inputFields = document.querySelectorAll('.inputField');

// Show alert box on form submit
form.addEventListener('submit', (event) => {
    event.preventDefault();
    alertBox.style.display = 'block';
});

// Hide alert box when close button is clicked
closeBtn.addEventListener('click', () => {
    alertBox.style.display = 'none';
});

// Hide alert box and disable input fields on confirm
confirmBtn.addEventListener('click', () => {
    alertBox.style.display = 'none';
    inputFields.forEach((field) => {
        field.classList.add('disabled');
    });
});
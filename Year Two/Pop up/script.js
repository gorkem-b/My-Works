const submitBtn = document.getElementById('submit');
const closeBtn = document.getElementById('close');
const popup = document.querySelector('.popupContainer');

const openPopup = () => {
    popup.classList.add('popupActive');
};

const closePopup = () => {
    popup.classList.remove('popupActive');
};

submitBtn.addEventListener('click', openPopup);
closeBtn.addEventListener('click', closePopup);
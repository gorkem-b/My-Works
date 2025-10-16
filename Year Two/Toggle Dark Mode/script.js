const btn = document.querySelector('.toggleBtn');
const moveBtn = document.querySelector('.bgMove');
const fa = document.querySelector('.fa-solid');
const faMoon = document.querySelector('.fa-moon');

btn.addEventListener('click', () => {
    const isActive = moveBtn.classList.toggle('active');
    fa.classList.toggle('dark');
    faMoon.classList.toggle('active');

    faMoon.classList.toggle('moon-active', isActive);
    document.body.classList.toggle('dark', isActive);
});

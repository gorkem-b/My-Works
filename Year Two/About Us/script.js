const hamBurgerBtn = document.getElementById('hamBurger');
const responsiveRight = document.querySelector('.responsive');

if (hamBurgerBtn && responsiveRight) {
    hamBurgerBtn.addEventListener('click', () => {
        const isActive = hamBurgerBtn.classList.toggle('active');
        responsiveRight.classList.toggle('active', isActive);
    });
}

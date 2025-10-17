function scrollToTop() {
    location.href = '#home';
}

const contactForm = document.getElementById('contactForm');
contactForm.addEventListener('submit', function(e) {
    e.preventDefault();
    alert('Sorry, request cannot be accepted due to some technical errors.');
});
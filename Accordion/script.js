const accordionHeaders = document.querySelectorAll('.accordionTop');
const accordionContainer = document.querySelector('.accordion');

accordionHeaders.forEach(header => {
    header.addEventListener('click', event => {
        // Add smooth transition to the accordion container
        accordionContainer.style.transition = "all 0.3s";
        
        // Toggle 'active' class on the clicked accordion section
        const section = event.target.parentElement;
        section.classList.toggle('active');
    });
});
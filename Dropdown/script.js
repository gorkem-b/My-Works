const dropBtn = document.getElementById('dropdown');

if (dropBtn) {
    dropBtn.addEventListener('click', function () {
        const toggleElement = document.querySelector('.toggle');
        
        if (toggleElement) {
            toggleElement.classList.toggle('active');
        }
    });
}
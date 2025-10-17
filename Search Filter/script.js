const searchInput = document.getElementById('searchInput');
const courseList = document.getElementById('courses-lists');
const listItems = courseList.getElementsByTagName('li');

searchInput.addEventListener('input', () => {
    const query = searchInput.value.toLowerCase();

    Array.from(listItems).forEach(li => {
        const link = li.querySelector('a');
        const text = link ? link.textContent.toLowerCase() : '';
        li.style.display = text.includes(query) ? 'block' : 'none';
    });
});

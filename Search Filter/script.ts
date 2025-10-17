const searchInput = document.getElementById('searchInput');
searchInput.addEventListener('keydown', () => {
    let input, lowerCase, li, a, i, searchInputValue;
    input = document.getElementById('searchInput');
    lowerCase = input.value.toLowerCase();
    courseLis = document.getElementById('courses-lists');
    li = courseLis.getElementsByTagName('li');
    for(i=0; i<li.length; i++){
        a = li[i].getElementsByTagName('a')[0];
        searchInputValue = a.textContent || a.innerText;
        if(searchInputValue.toLowerCase().indexOf(lowerCase) > -1){
            li[i].style.display = 'block';
        } else {
            li[i].style.display = 'none';
        }
    }
});
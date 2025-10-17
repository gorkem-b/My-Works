// Show notes on page load
showNotes();

// Add note event
const addBtn = document.getElementById('addBtn');
addBtn.addEventListener('click', function () {
    const addTxt = document.getElementById('addTxt');
    let notes = localStorage.getItem('notes');
    let notesArray = notes ? JSON.parse(notes) : [];

    // Add new note
    notesArray.push(addTxt.value);
    localStorage.setItem('notes', JSON.stringify(notesArray));
    addTxt.value = '';
    showNotes();
});

// Display notes
function showNotes() {
    let notes = localStorage.getItem('notes');
    let notesArray = notes ? JSON.parse(notes) : [];

    let html = "";
    notesArray.forEach(function (note, index) {
        html += `
        <div class="noteCard">
            <div class="card-body">
                <h5 class="card-title">Note ${index + 1}</h5>
                <p class="card-text">${note}</p>
                <button class="delete-btn" id="${index}" onclick="deleteNote(this.id)">Delete Note</button>
            </div>
        </div>`;
    });

    const notesElm = document.getElementById('notes');
    notesElm.innerHTML = notesArray.length
        ? html
        : `No notes! Click on Add Note Section to add Notes!`;
}

// Delete a note
function deleteNote(index) {
    let notes = localStorage.getItem('notes');
    let notesArray = notes ? JSON.parse(notes) : [];
    notesArray.splice(index, 1);
    localStorage.setItem('notes', JSON.stringify(notesArray));
    showNotes();
}

// Search notes
const searchInput = document.getElementById('searchTxt');
searchInput.addEventListener('input', function () {
    const inputVal = searchInput.value.toLowerCase();
    const noteCards = document.getElementsByClassName('noteCard');

    Array.from(noteCards).forEach(function (card) {
        const cardText = card.getElementsByTagName('p')[0].innerText.toLowerCase();
        card.style.display = cardText.includes(inputVal) ? "block" : "none";
    });
});

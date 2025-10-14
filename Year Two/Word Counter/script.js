const userText = document.getElementById('inputText');
const characters = document.getElementById('char');
const totalWords = document.getElementById('words');

userText.addEventListener('input', function () {
    // Update character count
    const charCount = userText.value.length;
    characters.innerHTML = `${charCount} Characters`;
    
    // Update word count
    const trimmedText = userText.value.trim();
    const wordCount = trimmedText === '' ? 0 : trimmedText.split(/\s+/).length;
    totalWords.innerHTML = `${wordCount} Words`;
});
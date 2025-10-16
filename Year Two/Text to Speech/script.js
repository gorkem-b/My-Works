const userTextInput = document.getElementById('inputText');
const speechButton = document.getElementById('speech');

speechButton.addEventListener('click', () => {
    const textToSpeak = userTextInput.value;
    const utterance = new SpeechSynthesisUtterance(textToSpeak);
    speechSynthesis.speak(utterance);
});

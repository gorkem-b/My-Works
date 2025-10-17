// List of available emojis
const emojis = [
    "😮", "😲", "😴", "🤤", "😪", "😵", "🤐", "🥴", "🤢", "🤮", "🤕", "🥳",
    "😷", "🤒", "🤕", "🤑", "🤠", "😈", "👿", "👹", "👺", "😿", "😾", "😀",
    "😃", "😄", "😁", "😆", "😅", "🤣", "😂", "🙂", "💀", "👻", "👽", "🤖",
    "💩", "😺", "😸", "😹", "😻", "😼", "🤭", "🤫", "🤥", "😶", "😐", "😑",
    "😬", "🙄", "😯", "😦", "😧"
];

// Get DOM elements
const generateBtn = document.getElementById('btn');
const emojiContainer = document.getElementById("emoji-container");

// Show the first emoji by default
emojiContainer.textContent = emojis[0];

// Generate a random emoji and display it
function showRandomEmoji() {
    const randomIndex = Math.floor(Math.random() * emojis.length);
    emojiContainer.textContent = emojis[randomIndex];
}

// Add event listener to the button
generateBtn.addEventListener('click', showRandomEmoji);
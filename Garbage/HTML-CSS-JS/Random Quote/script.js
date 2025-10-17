const nextBtn = document.getElementById('nextQuote');
const quoteElem = document.getElementById('quote');
const authorElem = document.getElementById('author');

const quotes = [
    {
        quote: 'You can get everything in life you want if you will just help enough other people get what they want',
        author: 'Zig Ziglar'
    },
    {
        quote: 'Inspiration does exist, but it must find you working.',
        author: 'Pablo Picasso'
    },
    {
        quote: 'Don\'t settle for average. Bring your best to the moment. Then, whether it fails or succeeds, at least you know you gave all you had.',
        author: 'Angela Bassett'
    },
    {
        quote: 'Show up, show up, show up, and after a while the muse shows up, too.',
        author: 'Isabel Allende'
    },
    {
        quote: 'Don\'t bunt. Aim out of the ballpark. Aim for the company of immortals',
        author: 'David Ogilvy'
    },
    {
        quote: 'I have stood on a mountain of no’s for one yes.',
        author: 'Barbara Elaine Smith'
    },
    {
        quote: 'If you believe something needs to exist, if it\'s something you want to use yourself, don\'t let anyone ever stop you from doing it',
        author: 'Tobias Lütke'
    }
];

// Display the first quote initially
displayQuote(0);

// Event listener for the next quote button
nextBtn.addEventListener('click', showRandomQuote);

// Function to display a quote by index
function displayQuote(index) {
    quoteElem.innerHTML = quotes[index].quote;
    authorElem.innerHTML = quotes[index].author;
}

// Function to show a random quote
function showRandomQuote() {
    // Generate a random index different from the currently displayed quote
    let currentIndex = quotes.findIndex(q => q.quote === quoteElem.innerHTML);
    let randomIndex;
    do {
        randomIndex = Math.floor(Math.random() * quotes.length);
    } while (randomIndex === currentIndex && quotes.length > 1);

    displayQuote(randomIndex);
}

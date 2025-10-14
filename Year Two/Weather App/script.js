// DOM Elements
const cityName = document.querySelector('#weatherInput');
const form = document.getElementById('weatherForm');
const myCity = document.getElementById('city');
const image = document.getElementById('weatherImage');
const weather = document.getElementById('weatherMain');
const temp = document.querySelector('.temp');
const dates = document.querySelector('.todayDates');
const times = document.getElementById('todayTime');
const myWeatherContainer = document.querySelector('.weatherContainer');

// Timer variable
let timeInterval = null;

// Constants
const API_KEY = '931f131dde3f4ae2fcbc3289fc646471';
const MONTHS = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sept.', 'Oct.', 'Nov', 'Dec'];

const WEATHER_CONFIG = {
    Clear: { image: './Images/sunny.png', color: '#ec6e4c' },
    Clouds: { image: './Images/clouds.png', color: '#86d3d3' },
    Rain: { image: './Images/Rain.png', color: '#494bcf' },
    Drizzle: { image: './Images/Drizzle.png', color: '#8ecfcf' },
    Haze: { image: './Images/Drizzle.png', color: '#d8ced2' }
};

// Update weather UI
function updateWeatherUI(data) {
    const tempValue = Math.round(data.main.temp);
    const weatherMain = data.weather[0].main;
    const city = cityName.value;

    myCity.innerHTML = city;
    temp.innerHTML = `${tempValue}<span><sup>o</sup>C</span>`;
    weather.innerHTML = weatherMain;

    // Update weather image and background
    const config = WEATHER_CONFIG[weatherMain];
    if (config) {
        image.src = config.image;
        myWeatherContainer.style.backgroundColor = config.color;
    }
}

// Update date display
function updateDate() {
    const date = new Date();
    const month = MONTHS[date.getMonth()];
    dates.innerHTML = `${date.getDate()}, ${month}`;
}

// Update time display
function updateTime() {
    const now = new Date();
    let hours = now.getHours();
    const minutes = now.getMinutes();
    const seconds = now.getSeconds();

    if (hours === 0) hours = 12;
    if (hours > 12) hours -= 12;

    const formattedTime = `${hours.toString().padStart(2, '0')}:${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
    times.innerHTML = formattedTime;
}

// Fetch weather data
async function fetchWeather(city) {
    try {
        const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=${API_KEY}`;
        const response = await fetch(url);
        if (!response.ok) throw new Error('City not found');
        return response.json();
    } catch (error) {
// Form submit handler
form.addEventListener('submit', async function (e) {
    e.preventDefault();

    try {
        const data = await fetchWeather(cityName.value);
        updateWeatherUI(data);
        updateDate();
        
        if (timeInterval) clearInterval(timeInterval);
        timeInterval = setInterval(updateTime, 1000);
        updateTime();
    } catch (error) {
        console.error('Error:', error);
        alert('City not found. Please try again.');
    }
});
    updateWeatherUI(data);
    updateDate();
    setInterval(updateTime, 1000);
    updateTime();
    }

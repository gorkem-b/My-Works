const TARGET_DATE = new Date("Jan 01, 2032 12:00:00").getTime();
const MS_PER_SECOND = 1000;
const MS_PER_MINUTE = MS_PER_SECOND * 60;
const MS_PER_HOUR = MS_PER_MINUTE * 60;
const MS_PER_DAY = MS_PER_HOUR * 24;

function updateTimer() {
    const now = new Date().getTime();
    const timeRemaining = TARGET_DATE - now;

    if (timeRemaining < 0) {
        clearInterval(timerInterval);
        return;
    }

    const days = Math.floor(timeRemaining / MS_PER_DAY);
    const hours = Math.floor((timeRemaining % MS_PER_DAY) / MS_PER_HOUR);
    const minutes = Math.floor((timeRemaining % MS_PER_HOUR) / MS_PER_MINUTE);
    const seconds = Math.floor((timeRemaining % MS_PER_MINUTE) / MS_PER_SECOND);

    document.getElementById('days').innerHTML = days;
    document.getElementById('hours').innerHTML = hours;
    document.getElementById('minutes').innerHTML = minutes;
    document.getElementById('seconds').innerHTML = seconds;
}

const timerInterval = setInterval(updateTimer, 1000);
updateTimer(); // Run immediately on load

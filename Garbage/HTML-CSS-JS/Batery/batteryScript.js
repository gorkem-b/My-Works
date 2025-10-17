const batteryStatusText = document.querySelector('#batteryStatus');
const batteryBar = document.getElementById('batter-per');

navigator.getBattery().then(battery => {
    updateBatteryStatus(battery);
    setInterval(() => updateBatteryStatus(battery), 2000);
});

function updateBatteryStatus(battery) {
    const percent = Math.round(battery.level * 100);
    batteryStatusText.textContent = `${percent}%`;

    // Set battery bar width as a percentage string (e.g., "75%")
    batteryBar.style.width = `${percent}%`;

    // Optionally, you can add a class or color based on charging status
    // battery.charging ? batteryBar.classList.add('charging') : batteryBar.classList.remove('charging');
}

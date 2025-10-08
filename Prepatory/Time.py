from datetime import datetime

now = datetime.now()

currentTime = now.strftime("%H:%M:%S")
print("Current Time =", currentTime)
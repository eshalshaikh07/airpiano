🎹 Ultrasonic Piano using ESP32
A gesture-controlled piano that uses an ultrasonic sensor and ESP32 to detect hand distance and play corresponding piano notes on a computer via Python.

🔧 Components
ESP32

HC-SR04 Ultrasonic Sensor

Python with pyserial, pygame

Piano note .wav files

⚙️ Working
ESP32 measures hand distance using ultrasonic sensor

Sends note ID over serial

Python script receives data and plays piano sound

📏 Note Mapping (Example)
0–10 cm → C

10–20 cm → D

... up to B


import serial
import simpleaudio as sa
import numpy as np

frequencies = {
    "C4": 261.63,
    "D4": 293.66,
    "E4": 329.63,
    "F4": 349.23,
    "G4": 392.00,
    "A4": 440.00
}

def play_note(freq, duration=0.3):
    fs = 44100
    t = np.linspace(0, duration, int(fs * duration), False)
    wave = np.sin(freq * t * 2 * np.pi)
    audio = (wave * 32767).astype(np.int16)
    sa.play_buffer(audio, 1, 2, fs).wait_done()

ser = serial.Serial('COM9', 115200)  # Replace with your actual COM port

while True:
    try:
        line = ser.readline().decode().strip()
        if line in frequencies:
            print(f"Playing: {line}")
            play_note(frequencies[line])
    except Exception as e:
        print("Error:", e)

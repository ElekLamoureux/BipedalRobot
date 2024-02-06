#pip install keyboard
import keyboard
import os
import serial
import time
import pygame
from serial.tools import list_ports

def detect_arduino_port():
    ports = list(list_ports.comports())
    for port in ports:
        if "Arduino" in port.description:
            print(port.device)
            return port.device
    return None
arduino_port = detect_arduino_port()
    
    
    
print(f"Opening serial port {arduino_port}");
ser = serial.Serial(arduino_port, 9600, timeout=1)

# Load pre-trained classifier


# Open video capture


while True:

    
        if keyboard.is_pressed("w"):
            print("forward")
            dataToSend = ('FB1Z').encode('utf-8')
            ser.write(dataToSend)
            #print(dataToSend)
            
        if keyboard.is_pressed("s"):
            print("backward")
            dataToSend = ('FB-1Z').encode('utf-8')
            ser.write(dataToSend)
            #print(dataToSend)

        time.sleep(0.1)
        





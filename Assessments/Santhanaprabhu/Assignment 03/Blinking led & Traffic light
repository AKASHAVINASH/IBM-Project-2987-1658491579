import time
import RPi.GPIO as GPIO
from gpiozero import Button, TrafficLights, Buzzer

GPIO.setmode(GPIO.BOARD)
GPIO.setup(13, GPIO.OUT)

while True:
    GPIO.output(13,True)
    time.sleep(3)
    GPIO.output(13,False)
    time.sleep(3)

buzzer = Buzzer(15)
button = Button(21)
lights = TrafficLights(25, 8, 7)

while True:
    #Traffic Signal Sequence
    button.wait_for_press()
    light.green.on()
    sleep(3)
    lights.amber.on()
    sleep(3)
    lights.red.on()
    sleep(3)
    lights.off()

    #Pedestrian Crossing Buzzer
    buzzer.on()
    sleep(3)
    buzzer.off()

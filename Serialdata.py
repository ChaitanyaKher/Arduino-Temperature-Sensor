import serial
import time
import matplotlib.pyplot as plt
import numpy as np

ardbaud=9600
ardport= '/dev/ttyACM0'
ardserial=serial.Serial(port=ardport,baudrate=ardbaud)
ardserial.timeout = 2 
if ardserial.is_open:
    while True:
        size = ardserial.inWaiting()
        if size:
            data = ardserial.read(size)
            print data
        else:
            print 'no data'
        time.sleep(1)
else:
    print 'ardport not open'

plt.axis([0,10,0,1])


for i in range(10):
	y=np.random.random()
	plt.scatter(i,y)
	plt.pause(1)

plt.show()
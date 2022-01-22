import numpy as np
import cv2
import time
from datetime import datetime

cap = cv2.VideoCapture(0)#give vid name in '' to play video.

while(cap.isOpened ()):
    # Capture frame-by-frame
    ret, screen = cap.read()

    # Our operations on the frame come here
    frame = cv2.cvtColor(screen, cv2.COLOR_BGR2GRAY)
    now = datetime.now()
    font = cv2.FONT_HERSHEY_SIMPLEX 
    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
    cv2.putText(frame, dt_string , (50, 50), 
                font, 0.8, (0, 255, 0), 2, cv2.LINE_AA) 

    # Display the resulting frame
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):                 #press q to esape loop.
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()


























































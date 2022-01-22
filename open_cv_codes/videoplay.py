import cv2

##getting live stream from camera
cap = cv2.VideoCapture(0)#give video name as argument to read it or 0 for camera feed

#use cap.est to vary frame parameters.

cap .set(3, 960)

cap .set(4, 604)

while cap.isOpened ():
    ret, frame = cap.read()     #ret will store a bulian value wheather frame is available or not.frame is the serial tag of image being read
    cv2.imshow('vid',frame)
    q = cv2.waitKey(1)
    if q == ord('q'):
        break

h = cap.get(3)#this is property id no
print(h)
cap.release()

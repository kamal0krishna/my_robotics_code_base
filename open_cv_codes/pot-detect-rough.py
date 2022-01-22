import numpy as np
import cv2
import time
from datetime import datetime

def empty(a):
  pass


cv2.namedWindow('image')
cv2.resizeWindow('image', 3000, 300)

cv2.createTrackbar("hue min", 'image',93,179,empty)#track bar title,window of display,initial value,max value,recuring function
cv2.createTrackbar("hue max", 'image',121,179,empty)
cv2.createTrackbar("sat min", 'image',71,255,empty)
cv2.createTrackbar("sat max", 'image',248,255,empty)
cv2.createTrackbar("val min", 'image',18,255,empty)
cv2.createTrackbar("val max", 'image',148,255,empty)

# img = cv2.imread('kite2.jpg')
# imghsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)



cap = cv2.VideoCapture(0)#give vid name in '' to play video._____'http://192.168.43.1:8080/video'

while(cap.isOpened ()):
    # Capture frame-by-frame
    ret, screen = cap.read()

    # Our operations on the frame come here
    frame = cv2.cvtColor(screen, cv2.COLOR_BGR2HSV)

    




# while True:
  
    
    h_min = cv2.getTrackbarPos("hue min",'image')#trackbar name and window name.
    h_max = cv2.getTrackbarPos("hue max",'image')
    s_min = cv2.getTrackbarPos("sat min",'image')
    s_max = cv2.getTrackbarPos("sat max",'image')
    v_min = cv2.getTrackbarPos("val min",'image')
    v_max = cv2.getTrackbarPos("val max",'image')

    lower = np.array([h_min,s_min,v_min],dtype=np.uint8)
    upper = np.array([h_max,s_max,v_max],dtype=np.uint8)


    mask = cv2.inRange(frame,lower,upper)
    imgres = cv2.bitwise_and(screen,screen,mask=mask)
    contours,heirarchy=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

    if(len(contours)!=0):
        print(contours)
        c=max(contours,key=cv2.contourArea)
        cv2.drawContours(imgres,[c],-1,(0,255,0),3)


    # Display the resulting frame
    cv2.imshow('segmented_frame',imgres)


    if cv2.waitKey(1) & 0xFF == ord('q'):                 #press q to esape loop.
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
#########################################################################################


# # find contours in the thresholded image
# cnts = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL,
# 	cv2.CHAIN_APPROX_SIMPLE)
# cnts = imutils.grab_contours(cnts)

# # loop over the contours
# for c in cnts:
# 	# compute the center of the contour
# 	M = cv2.moments(c)
# 	cX = int(M["m10"] / M["m00"])
# 	cY = int(M["m01"] / M["m00"])
# 	# draw the contour and center of the shape on the image
# 	cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
# 	cv2.circle(image, (cX, cY), 7, (255, 255, 255), -1)
# 	cv2.putText(image, "center", (cX - 20, cY - 20),
# 		cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
# 	# show the image
# 	cv2.imshow("Image", image)
# 	cv2.waitKey(0)


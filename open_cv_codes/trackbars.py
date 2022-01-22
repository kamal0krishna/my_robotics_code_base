# import cv2
# import numpy as np

# def empty(a):
#   pass


# img = np.zeros((250,500,3),np.uint8)
# cv2.namedWindow('image')


# cv2.createTrackbar("B", 'image',0,255,empty)
# cv2.createTrackbar("G", 'image',0,255,empty)
# cv2.createTrackbar("R", 'image',0,255,empty)
# cv2.createTrackbar("switch", 'image',0,1,empty)

# while (1):
#     cv2.imshow('image',img)
#     q = cv2.waitKey(1)
#     if q == ord('q'):
#         break
    
#     b = cv2.getTrackbarPos("B", 'image')
#     g = cv2.getTrackbarPos("G", 'image')
#     r = cv2.getTrackbarPos("R", 'image')
#     s = cv2.getTrackbarPos("switch", 'image')

#     if s == 0:
#       img[:] = 0
#     else:
#       img[:] = [b,g,r]


# cv2.destroyAllWindows()


############################################################################################################################################################

import cv2
import numpy as np

def empty(a):
  pass

cv2.namedWindow('image')

cv2.createTrackbar("hue min", 'image',0,179,empty)#track bar title,window of display,initial value,max value,recuring function
cv2.createTrackbar("hue max", 'image',179,179,empty)
cv2.createTrackbar("sat min", 'image',0,255,empty)
cv2.createTrackbar("sat max", 'image',255,255,empty)
cv2.createTrackbar("val min", 'image',0,255,empty)
cv2.createTrackbar("val max", 'image',255,255,empty)

img = cv2.imread('smarties.png')
imghsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

while True:
  
  
  h_min = cv2.getTrackbarPos("hue min",'image')#trackbar name and window name.
  h_max = cv2.getTrackbarPos("hue max",'image')
  s_min = cv2.getTrackbarPos("sat min",'image')
  s_max = cv2.getTrackbarPos("sat max",'image')
  v_min = cv2.getTrackbarPos("val min",'image')
  v_max = cv2.getTrackbarPos("val max",'image')

  lower = np.array([h_min,s_min,v_min],dtype=np.uint8)
  upper = np.array([h_max,s_max,v_max],dtype=np.uint8)


  mask = cv2.inRange(imghsv,lower,upper)
  imgres = cv2.bitwise_and(img,img,mask=mask)
  cv2.waitKey(1)
  cv2.imshow('image',img)
  cv2.imshow('mask',mask)
  cv2.imshow('res',imgres)





















































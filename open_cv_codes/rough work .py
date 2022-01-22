

###########################################################################################################
# import cv2
# import numpy as np

# img = cv2.imread('illusion.jpg')

# height, width = img.shape[:2]
# res = cv2.resize(img,(2*width, 2*height), interpolation = cv2.INTER_CUBIC)

# cv2.imshow('resize',res)
# cv2.imshow('img',img)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# cv2.imwrite('image name.jpg',res)
####################################################################################################3333
# import numpy as np
# import cv2 as cv
# img = cv.imread('stick man.jpg',0)
# rows,cols = img.shape
# M = np.float32([[1,0,100],[0,1,50]])
# dst = cv.warpAffine(img,M,(cols,rows))

# cv.imwrite('image name.jpg',dst)
# cv.imshow('img',dst)
# cv.imshow('orig',img)
# cv.waitKey(0)
# cv.destroyAllWindows()



############################################################################################################


# img = cv.imread('stick man.jpg',0)
# rows,cols = img.shape
# # cols-1 and rows-1 are the coordinate limits.
# M = cv.getRotationMatrix2D(((cols-1)/2.0,(rows-1)/2.0),90,1)
# dst = cv.warpAffine(img,M,(cols,rows))

# cv.imwrite('image name.jpg',dst)

#########################################################################################################


# import cv2 as cv
# import numpy as np
# from matplotlib import pyplot as plt
# img = cv.imread('gradiance.png',0)
# ret,thresh1 = cv.threshold(img,127,255,cv.THRESH_BINARY)
# ret,thresh2 = cv.threshold(img,127,255,cv.THRESH_BINARY_INV)
# ret,thresh3 = cv.threshold(img,127,255,cv.THRESH_TRUNC)
# ret,thresh4 = cv.threshold(img,127,255,cv.THRESH_TOZERO)
# ret,thresh5 = cv.threshold(img,127,255,cv.THRESH_TOZERO_INV)
# titles = ['Original Image','BINARY','BINARY_INV','TRUNC','TOZERO','TOZERO_INV']
# images = [img, thresh1, thresh2, thresh3, thresh4, thresh5]
# for i in xrange(6):
#     plt.subplot(2,3,i+1),plt.imshow(images[i],'gray',vmin=0,vmax=255)
#     plt.title(titles[i])
#     plt.xticks([]),plt.yticks([])
# plt.show()


#############################################################################################################################



import cv2
import numpy as np

def empty(a):
  pass

cv2.namedWindow('image')
cv2.resizeWindow('image', 6000, 100)

cv2.createTrackbar("hue min", 'image',0,179,empty)#track bar title,window of display,initial value,max value,recuring function
cv2.createTrackbar("hue max", 'image',95,179,empty)
cv2.createTrackbar("sat min", 'image',64,255,empty)
cv2.createTrackbar("sat max", 'image',255,255,empty)
cv2.createTrackbar("val min", 'image',1,255,empty)
cv2.createTrackbar("val max", 'image',255,255,empty)

img = cv2.imread('kite2.jpg')
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
  contours,heirarchy=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

  if(len(contours)!=0):
      c=max(contours,key=cv2.contourArea)
      cv2.drawContours(imgres,[c],-1,(0,255,0),3)



  cv2.waitKey(1)
  cv2.imshow('image',imgres)
  cv2.imshow('mask',mask)
  cv2.imshow('res',imgres)
  cv2.imshow('hsv',imghsv)
  cv2.imshow('input',img)

  cv2.imwrite('mask.jpg',mask)
  cv2.imwrite('imghsv.jpg',imghsv)
  cv2.imwrite('imgres.jpg',imgres)










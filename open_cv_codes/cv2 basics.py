import cv2
# #print(cv2.__version__)
img = cv2.imread('lena.jpg')#2nd second argument is called flag .there are 3 flag values:1(loads color image),0(loads grey image),-1(loads alpha channel included image)
# #print (img)
cv2.imshow('img',img)
# #the first argument is the window name and second argument si the variable name
# cv2.waitKey(0)
# #this command is to hold the created window which would other wise disappear in a mili second-the argument is the number of mili seconds to hold the window.
# #use 0 fro infinite wait
# cv2.destroyAllWindows()
# #this command is to close all created windows
# cv2.imwrite('image name.jpg',img)#command to save an img

# #conveting into grey 
# greyimg = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
# blurimg = cv2.blur(greyimg,(7,7),0)
# cannyimg = cv2.Canny(img,100,100)

# cv2.imshow('grey',greyimg)
# cv2.imshow('blur',blurimg)
# cv2.imshow('canny',cannyimg)
# cv2.waitKey(0)

# cv2.destroyAllWindows()


# print(img.shape)
# print(img.size)
# print(img.dtype)
# b,g,r = cv2.split(img)

# img = cv2.merge((b,g,r))

# cv2.imshow('img',img)

# cv2.waitKey(3000)

#cv2.destroyAllWindows()



















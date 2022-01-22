import cv2 

img = cv2.imread('pink kite.png')


print(img.shape)

res = cv2.resize(img,(280, 440), interpolation = cv2.INTER_CUBIC)


cv2.imwrite('pink kite2.jpg',res)
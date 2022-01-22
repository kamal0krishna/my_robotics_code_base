import cv2
img = cv2.imread('lena.jpg',0)
cv2.imshow('img',img)
k = cv2.waitKey(0)
if k == 27:                       #27 is for esc
    cv2.destroyAllWindows()
elif k == ord('s'):                    #works if u press s key
    cv2.imwrite('image name.jpg',img)
    cv2.destroyAllWindows()












import cv2
import numpy as np 

def nothing(x):
    pass

cap=cv2.VideoCapture(0)
cv2.namedWindow("image")

cv2.createTrackbar("lb","image",0,255,nothing)
cv2.createTrackbar("lg","image",128,255,nothing)
cv2.createTrackbar("lr","image",0,255,nothing)

cv2.createTrackbar("ub","image",99,255,nothing)
cv2.createTrackbar("ug","image",248,255,nothing)
cv2.createTrackbar("ur","image",45,255,nothing)

frame = cv2.imread("./1.jpg")
img_blur=cv2.GaussianBlur(frame,(21,21),0)
while True:
    lb=cv2.getTrackbarPos("lb","image")
    lg=cv2.getTrackbarPos("lg","image")
    lr=cv2.getTrackbarPos("lr","image")

    ub=cv2.getTrackbarPos("ub","image")
    ug=cv2.getTrackbarPos("ug","image")
    ur=cv2.getTrackbarPos("ur","image")

    lower=np.array([lb,lg,lr],dtype=np.uint8)
    upper=np.array([ub,ug,ur],dtype=np.uint8)

    mask=cv2.inRange(img_blur,lower,upper)

    contours,heirarchy=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

    if(len(contours)!=0):
        c=max(contours,key=cv2.contourArea)
        cv2.drawContours(frame,[c],-1,(0,0,255),3)
        M=cv2.moments(c)
        area=cv2.contourArea(c)
        if(area!=0):
            
                cx=M['m10']/M['m00']
                cy=M['m01']/M['m00']
            
                print(cx,cy,area)
                '''
                if(area>30000 and area<90000):

                    if(cx<320):
                        requests.get(ip+'/left')
                    elif(cx>240):
                        requests.get(ip+'/right')
                    elif(cx>320 and cx<240):
                        requests.get(ip+'/forward')
                elif(area>90000):
                    requests.get(ip+'/halt')
                '''
        

    cv2.imshow("img",frame)
    cv2.imshow("image",mask)
    k=cv2.waitKey(1)
    if k==ord('q'):
        cv2.destroyAllWindows()
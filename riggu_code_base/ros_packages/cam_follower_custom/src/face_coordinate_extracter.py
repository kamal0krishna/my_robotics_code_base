#!/usr/bin/python3

import rospy
import cv2
import numpy as np 
from cam_follower_custom.msg import coordinates

obj_pose = coordinates()

  
face_cascade = cv2.CascadeClassifier('src/haarcascade_frontalface_default.xml')
  

#####################################################################################


def coordinate_marker():

    cap=cv2.VideoCapture(0)


    while not rospy.is_shutdown():


        pub = rospy.Publisher('coordinates_obj', coordinates, queue_size=10)
        rospy.init_node('coordinate_marker', anonymous=True)
        rate = rospy.Rate(10) # 10hz



        ret, img = cap.read() 
        # img_blur=cv2.GaussianBlur(frame,(21,21),0)
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)


        for (x,y,w,h) in faces:
            # To draw a rectangle in a face 
            cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,0),2) 
            # roi_gray = gray[y:y+h, x:x+w]
            # roi_color = img[y:y+h, x:x+w]
            print(x,y,w,h)

            cx=x+w*0.5
            cy=y+h*0.5

            obj_pose.obj_x = cx
            obj_pose.obj_y = cy

            pub.publish(obj_pose)
            cv2.imshow('img',img)        
    




#####################################################################################################


if __name__ == '__main__':
        try:
            coordinate_marker()
        except rospy.ROSInterruptException:
            pass




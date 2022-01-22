# import cv2
# events = [i for i in dir(cv2) if 'EVENT' in i]
# print (events)



##########################################################################################################################################

# import cv2
# import numpy as np

# # mouse callback function
# def draw_circle(event,x,y,flags,param):
#     if event == cv2.EVENT_LBUTTONcDBLCLK:
#         cv2.circle(img,(x,y),100,(255,0,0),-1)

# # Create a black image, a window and bind the function to window
# img = np.zeros((512,512,3), np.uint8)
# cv2.namedWindow('image')
# cv2.setMouseCallback('image',draw_circle)

# while(1):
#     cv2.imshow('image',img)
#     if cv2.waitKey(20) & 0xFF == 27:
#         break
# cv2.destroyAllWindows()

################################################################################################################################################

# import cv2
# import numpy as np

# drawing = False # true if mouse is pressed
# mode = True # if True, draw rectangle. Press 'm' to toggle to curve
# ix,iy = -1,-1

# # mouse callback function
# def draw_circle(event,x,y,flags,param):
#     global ix,iy,drawing,mode

#     if event == cv2.EVENT_LBUTTONDOWN:
#         drawing = True
#         ix,iy = x,y

#     elif event == cv2.EVENT_MOUSEMOVE:
#         if drawing == True:
#             if mode == True:
#                 cv2.rectangle(img,(ix,iy),(x,y),(0,255,0),-1)
#             else:
#                 cv2.circle(img,(x,y),5,(0,0,255),-1)

#     elif event == cv2.EVENT_LBUTTONUP:
#         drawing = False
#         if mode == True:
#             cv2.rectangle(img,(ix,iy),(x,y),(0,255,0),-1)
#         else:
#             cv2.circle(img,(x,y),5,(0,0,255),-1)


# img = np.zeros((512,512,3), np.uint8)
# cv2.namedWindow('image')
# cv2.setMouseCallback('image',draw_circle)

# while(1):
#     cv2.imshow('image',img)
#     k = cv2.waitKey(1) & 0xFF
#     if k == ord('m'):
#         mode = not mode
#     elif k == 27:
#         break

# cv2.destroyAllWindows()

####################################################################################################################################################
## code to indicate coordinates and pixel value.


# import cv2
# import numpy as np

# # mouse callback function
# def click_event(event,x,y,flags,param):
#     if event == cv2.EVENT_LBUTTONDOWN:
#         print(x,',',y)
#         font = cv2.FONT_HERSHEY_SIMPLEX 
#         string = str(x) + ',' + str(y)
#         cv2.putText(img, string, (x, y), 
#                     font, 0.8, (255, 255, 255), 2, cv2.LINE_AA) 
#         cv2.imshow('image',img)
#     if event == cv2.EVENT_RBUTTONDOWN:
#         blue = img[x,y,0]
#         green = img[x,y,1]
#         red = img[x,y,2]
#         font = cv2.FONT_HERSHEY_SIMPLEX 
#         string = str(blue) + ',' + str(green) + ',' + str(green)
#         cv2.putText(img, string, (x, y), 
#                     font, 0.8, (255, 255, 0), 2, cv2.LINE_AA) 
#         cv2.imshow('image',img)





# #img = np.zeros((1024,1024,3), np.uint8)
# img = cv2.imread('lena.jpg')
# cv2.imshow('image',img)
# cv2.setMouseCallback('image',click_event)

# cv2.waitKey(0)    
# cv2.destroyAllWindows()

########################################################################################################################################################


# # code to draw line between two points.


# import cv2
# import numpy as np

# # mouse callback function
# def click_event(event,x,y,flags,param):
#     if event == cv2.EVENT_LBUTTONDOWN:
#         cv2.circle(img, (x, y), 3, (0, 0, 255), -1)
#         points.append((x, y))
#         if len(points) >=2:
#             cv2.line(img, points[-1],points[-2], (255, 0, 0), 5)
#         cv2.imshow('image', img)

# img = np.zeros((1024,1024,3), np.uint8)
# #img = cv2.imread('lena.jpg')
# cv2.imshow('image',img)
# points = []
# cv2.setMouseCallback('image',click_event)

# cv2.waitKey(0)    
# cv2.destroyAllWindows()

################################################################################################################################################












































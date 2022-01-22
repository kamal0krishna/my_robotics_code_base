#trail code
import cv2
import numpy as np
from google.colab.patches import cv2_imshow
%cd /content/drive/My Drive/OBJECT DETECTION FRAMES/frame set 1

pathOut ='repatched_video_2.avi'
fps = 30
frame_array = []
#for sorting the file names properly
j = 0

while j<566 :
    filename ='/content/drive/My Drive/OBJECT DETECTION FRAMES/frame set 2/fnl_frm'+str(j)+'.jpg'
    #reading each files
    img = cv2.imread(filename)
    height, width, layers = img.shape
    size = (width,height)
 #inserting the frames into an image array
    frame_array.append(img)
    j+=1

vid_final = cv2.VideoWriter(pathOut,cv2.VideoWriter_fourcc(*'DIVX'), fps, size)

for i in range(len(frame_array)):
    # writing to a image array
    vid_final.write(frame_array[i])
vid_final.release()



















































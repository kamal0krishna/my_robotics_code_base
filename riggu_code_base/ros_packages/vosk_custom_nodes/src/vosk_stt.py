#!/usr/bin/python3

# license removed for brevity
import rospy
from std_msgs.msg import String

from vosk import Model, KaldiRecognizer
import os
import json

# if not os.path.exists("model4"):
#     print ("Please download the model from https://alphacephei.com/vosk/models and unpack as 'model' in the current folder.")
#     exit (1)

import pyaudio

model = Model("/home/kamal/catkin_ws/src/vosk_custom_nodes/src/model4")
rec = KaldiRecognizer(model, 16000)

p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8000)
stream.start_stream()
text = 'blank'


# while True:
#     data = stream.read(4000)
#     if len(data) == 0:
#         break
#     if rec.AcceptWaveform(data):
#         jres = json.loads(rec.Result())
#         text = jres['text']
#         print(text)
#     if 'exit' in text :
#         break





###########################################################################  
def request_audio():
        pub = rospy.Publisher('audio_input', String, queue_size=10)
        rospy.init_node('vocal2text', anonymous=True)
        rate = rospy.Rate(10) # 10hz
        while not rospy.is_shutdown():
            ########################################################################################
            data = stream.read(4000)
            if len(data) == 0:
                rospy.loginfo('node terminated as no input is being fed')
                break
            if rec.AcceptWaveform(data):
                jres = json.loads(rec.Result())
                text = jres['text']
                rospy.loginfo(text)
                pub.publish(text)
            rate.sleep()


            #####################################################################################

if __name__ == '__main__':
        try:
            request_audio()
        except rospy.ROSInterruptException:
            pass

########################################################################

# created by virtualenv automatically


############################################################################
# from os import path
# from pydub import AudioSegment

# # files                                                                         
# src = r"C:\Users\pkk\Documents\virtual env\py3.8.6\sound.mp3"
# dst = "test.wav"

# # convert wav to mp3                                                            
# sound = AudioSegment.from_mp3(src)
# sound.export(dst, format="wav")

########################################################################################################

  # import subprocess

  # subprocess.call(['ffmpeg', '-i', '/input/file.mp3',
  #                  '/output/file.wav'])


########################################################################################################

import subprocess

subprocess.call(['ffmpeg', '-i', r'C:/Users/pkk/Documents/virtual env/py3.8.6/sound.mp3','test.wav'])












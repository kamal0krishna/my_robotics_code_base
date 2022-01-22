#rom gtts import gTTS
#tts = gTTS('hello')
#tts.save('hello.mp3')

#from gtts import gTTS
#tts = gTTS('hi kamal')
#tts.save('greetings.mp3')

# from gtts import gTTS
# from io import BytesIO
# mp3_fp = BytesIO()
# tts = gTTS('hello')
# tts.write_to_fp(mp3_fp)

import os
#os.system("start greetings.mp3")

# from gtts import gTTS
# from tempfile import TemporaryFile
# tts = gTTS(text='Hello', lang='en')
# f = TemporaryFile()
# tts.write_to_fp(f)

# os.system("start f.mp3")

#f.close()

from gtts import gTTS
tts = gTTS('The context manager opens the file and reads its contents, storing the data in an AudioFile instance called source. Then the record() method records the data from the entire file into an AudioData instance. You can confirm this by checking the type of audio')
tts.save('audio.mp3')

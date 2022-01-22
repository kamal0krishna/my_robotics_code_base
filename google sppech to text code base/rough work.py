import speech_recognition as sr
import pyaudio
import time

r3 = sr.Recognizer()
r3.energy_threshold = 1200
r3.pause_threshold = 1

p = 'n'

if p == 'n':
    exit()

import speech_recognition as sr

# obtain path to "english.wav" in the same folder as this script
from os import path
AUDIO_FILE = path.join(path.dirname(path.C:r\Users\pkk\Downloads),)

with sr.AudioFile(AUDIO_FILE) as source:
    audio = r3.record(source)  # read the entire audio file

try:
    # for testing purposes, we're just using the default API key
    # to use another API key, use `r.recognize_google(audio, key="GOOGLE_SPEECH_RECOGNITION_API_KEY")`
    # instead of `r.recognize_google(audio)`
    print("Google Speech Recognition thinks you said :" + r.recognize_google(audio))
except sr.UnknownValueError:
    print("Google Speech Recognition could not understand audio")
except sr.RequestError as e:
    print("Could not request results from Google Speech Recognition service; {0}".format(e))


import speech_recognition as sr
import webbrowser as wb
import pyaudio

r3 = sr.Recognizer()
r3.energy_threshold = 1900
r3.pause_threshold = 1
r2 = sr.Recognizer()
r2.energy_threshold = 1900
r2.pause_threshold = 1

with sr.Microphone() as source:
    print ('search options:google,chegg.')
    print('speak now.')
    
    try:
        
        global feed
        feed = 'a'
        audio = r3.listen(source,2,5)
        feed = r3.recognize_google (audio)
        print('heard.')
        feed = "".join(feed.split())
        print('ur input:' + feed)
    except sr.WaitTimeoutError: 
        print('time out,try again.')
    except sr.RequestError as e:
        print('failed'.format(e))
    except sr.UnknownValueError: 
        print('Error')

if 'Google' in feed :
    url = 'https://www.google.com/search?q='
    with sr.Microphone() as source:
        print('search your query')
        try:
            audio = r2.listen(source,2,7)
            print("heard.")
            get = r2.recognize_google (audio)
            get = "".join(get.split())
            print('ur input'+ get)
            wb.open(url+get)
        except sr.WaitTimeoutError: 
            print('time out,try again.')
        except sr.UnknownValueError: 
            print('Error')
        except sr.RequestError as e:
            print('failed'.format(e)) 
elif 'chegg' in feed :
    url = 'https://expert.chegg.com/expertqna'
    wb.open(url)
else:
    print("spell your search if programm fails or results are'nt the ones u expected.")
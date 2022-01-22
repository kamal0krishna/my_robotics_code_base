#!/usr/bin/python3
import rospy
from std_msgs.msg import String

cmd1 = 'move forward'
cmd2 = 'move backward'
cmd3 = 'turn right'
cmd4 = 'turn left'



def cmd_pub(speaker_text):
    senctence = speaker_text.data
    pub = rospy.Publisher('user_cmd', String, queue_size=10)

    if cmd1 in senctence:
        print('command given: '+ cmd1)
        rospy.loginfo('command given: '+ cmd1)
        pub.publish(cmd1)

    elif cmd2 in senctence:
        print('command given: '+ cmd2)
        rospy.loginfo('command given: '+ cmd2)
        pub.publish(cmd2)

    elif cmd3 in senctence:
        print('command given: '+ cmd3)
        rospy.loginfo('command given: '+ cmd3)
        pub.publish(cmd3)

    elif cmd4 in senctence:
        print('command given: '+ cmd4)
        rospy.loginfo('command given: '+ cmd4)
        pub.publish(cmd4)

    else:
        rospy.loginfo('no command matched')
        pub.publish('no command matched')


def speech2command():

    rospy.init_node('speech2cmd_cvt', anonymous=True)

    rospy.Subscriber("audio_input", String, cmd_pub)

    rospy.spin()


if __name__ == '__main__':
    speech2command()

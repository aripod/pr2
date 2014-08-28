#!/usr/bin/env python

import roslib
import rospy

import actionlib

from sensor_msgs.msg import Image
#from std_msgs.msg import ByteMultiArray
from std_msgs.msg import String


def callback(data):
    #rospy.loginfo("DATA: %r\n", data.data)
    length = data.height*data.width*4
    image = [0] * length
    string = list("%s" % data.data)

    for i in range(0, length):
        current = data.data[i]        
        current = list("%r" % current)
        if(len(current)) == 3:
            image[i] = ord(current[1])
        else:
            aux = [0]*2
            aux[0] = current[3]
            aux[1] = current[4]
            current = int(''.join(aux),16)
            image[i] = current
    #print image   
    #pub = rospy.Publisher('pr2_videocamera_images', ByteMultiArray)
    pub = rospy.Publisher('pr2_videocamera_images', String)
    pub.publish(str(image))
       

if __name__ == '__main__':
    rospy.init_node('scriptpr2_rgba', anonymous=True)
    rospy.Subscriber("video_camera/image", Image, callback)
    rospy.spin()

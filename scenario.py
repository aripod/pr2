from morse.builder import *

# A 'naked' PR2 robot to the scene
james = NavPR2()
james.translate(x=4, y=-2.5, z=0.0)
james.add_interface('ros')

# An odometry sensor to get odometry information
odometry = Odometry()
james.append(odometry)
odometry.add_interface('ros', topic="/odom")

scan = Hokuyo()
scan.translate(x=0.275, z=0.252)
james.append(scan)
scan.properties(Visible_arc = False)
scan.properties(laser_range = 30.0)
scan.properties(resolution = 1.0)
scan.properties(scan_window = 10.0)
scan.create_laser_arc()
scan.add_interface('ros', topic='/base_scan')

motion = MotionXYW()
motion.properties(ControlType = 'Position')
james.append(motion)
motion.add_interface('ros', topic='/cmd_vel')

# Keyboard control
keyboard = Keyboard()
james.append(keyboard)

videocamera = VideoCamera()
videocamera.properties(cam_width=2, cam_height=2, cam_focal = 25)
videocamera.translate(x=0, y=0, z=0)
videocamera.rotate(x=0, y=0, z=0)
james.head.append(videocamera)
videocamera.add_interface('ros', topic='/video_camera')

# Set the environment
env = Environment('laas/grande_salle')
env.set_camera_rotation([1.0470, 0, 0.7854])

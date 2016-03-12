#copy the shutdown folder to home
cd shutdown
gcc shutdown.c -o shut -lwiringPi -lpthread

#set as a boot program
sudo vim /etc/rc.local
#add the following before "exit 0":
cd /home/ubuntu/shutdown
sudo ./shut &

#plug the 3 pins:
header 14: GND
header 16: VCC
header 18: SIGNAL

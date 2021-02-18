raspivid -n -w 920 -h 540 -t 999999 -b 2000000 -o - | gst-launch-1.0 -e -vvv fdsrc ! h264parse ! rtph264pay pt=96 config-interval=5 ! udpsink host=192.168.0.110 port=5001

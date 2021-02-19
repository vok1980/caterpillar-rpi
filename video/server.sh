raspivid \
    --nopreview \
    --width 920 \
    --height 540 \
    --timeout 999999 \
    --bitrate 2000000 \
    --output - \
| gst-launch-1.0 -e -vvv fdsrc ! h264parse ! rtph264pay pt=96 config-interval=5 ! udpsink host=192.168.0.110 port=5001

hostname=$(hostname)
ip=$(hostname -I)
ip=${ip::-1}

echo "Starting Connection"
echo "Connect to:"
echo ""
echo "rtsp://$hostname:8080/"
echo "or"
echo "rtsp://$ip:8080/"

rm -rf cameraLog.txt
touch cameraLog.txt
raspivid -o - -t 0 -w 1024 -h 768 -fps 30 | cvlc -vvv stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8080/}' :demux=h264 &> cameraLog.txt
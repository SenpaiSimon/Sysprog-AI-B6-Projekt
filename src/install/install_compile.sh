#!/usr/bin/env bash

rm -rf ./logs/log.txt

# Kernel Module Installation and Log
mkdir logs
touch logs/log.txt
echo "Starting compilation of the Kernel Module and installing it..."
echo "Kernel Install Log" >> ./logs/log.txt
echo "" >> ./logs/log.txt

cd ../kernel_driver
sudo rmmod led_matrix_driver
sudo make install >> ../install/logs/log.txt

echo "Kernel Module compiled and installed"
echo ""


# App Compilation and Execution
echo "" >> ../install/logs/log.txt
echo "App compile Log" >> ../install/logs/log.txt
echo "" >> ../install/logs/log.txt

echo "Compiling User app"
cd ../user_app
gcc app.c functions/functions.c led_controller/controller.c -o app >> ../install/logs/log.txt

echo "Starting user App"
./app

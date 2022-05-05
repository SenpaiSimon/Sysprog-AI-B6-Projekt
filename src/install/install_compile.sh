#!/usr/bin/env bash

rm -rf log.txt

# Kernel Module Installation and Log
echo "Starting compilation of the Kernel Module and installing it..."
echo "Kernel Install Log" >> log.txt
echo "" >> log.txt

cd ../kernel_driver
sudo rmmod led_matrix_driver
sudo make install >> ../install/log.txt

echo "Kernel Module compiled and installed"
echo ""


# App Compilation and Execution
echo "" >> ../install/log.txt
echo "App compile Log" >> ../install/log.txt
echo "" >> ../install/log.txt

echo "Compiling User app"
cd ../user_app
gcc app.c -o app >> ../install/log.txt

echo "Starting user App"
./app

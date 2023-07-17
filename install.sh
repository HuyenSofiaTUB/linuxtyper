#!/bin/bash

# build
mkdir build
cd build
cmake ..
make

# add to applications
sudo mkdir /opt/linuxtyper
sudo mkdir /usr/share/icons/linuxtyper
sudo mv ../linuxtyper.desktop /usr/share/applications
sudo mv linuxtyper /opt/linuxtyper
sudo mv ../icon.png /usr/share/icons/linuxtyper

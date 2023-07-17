#!/bin/bash

# build
mkdir build
cd build
cmake ..
make

# add to applications
mkdir /opt/linuxtyper
mkdir /usr/share/icons/linuxtyper
mv ../linuxtyper.desktop /usr/share/applications
mv linuxtyper /opt/linuxtyper
mv ../icon.png /usr/share/icons/linuxtyper

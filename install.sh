#!/bin/bash

applications=~/.local/share/applications

# build
mkdir build
cd build
cmake ..
make

# add to applications
mkdir "$applications"/linuxtyper
mv linuxtyper.desktop "$applications"
mv linuxtyper "$applications"/linuxtyper
mv ../gui.glade "$applications"/linuxtyper
mv icon.png "$applications"/linuxtyper
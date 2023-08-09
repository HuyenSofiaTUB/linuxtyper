#!/bin/bash

sudo rm -rf /opt/linuxtyper
sudo mkdir /opt/linuxtyper
sudo rm -rf /usr/share/icons/linuxtyper
sudo mkdir /usr/share/icons/linuxtyper
sudo mv linuxtyper.desktop /usr/share/applications
sudo mv build/linuxtyper /opt/linuxtyper
sudo mv icon.png /usr/share/icons/linuxtyper

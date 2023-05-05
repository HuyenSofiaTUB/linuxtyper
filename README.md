# LinuxTyper

The superior Auto-Typer for Linux.

## Features

LinuxTyper is a productivity tool written in C that automates repetitive typing tasks at specified intervals in a selected window. The GUI is built with GTK, allowing it to integrate smoothly with most Linux desktops.

Users can **input a desired time** in seconds and **up to five different phrases**, then **select a window** by clicking on it. At the specified time interval **Linuxtyper chooses a random phrase and types it into the selected window**.
        
While other auto-typers require users to keep the cursor on the selected window, **LinuxTyper can run in the background. Even if the selected window is minimized**, LinuxTyper will automatically maximize it to execute the routine and then minimize it again.

LinuxTyper **remembers previously used phrases** the next time the app is opened. 

## Prerequisities
Make sure you are using X11, not Wayland. Logout from your session. On the GNOME login screen find and click gear icon. Select option "GNOME on Xorg". Log back in.

For compilation, you will need:

- CMake
- Make
- `gtk-3.0` and `xdotool` development headers

On Debian based distributions (Ubuntu, Zorin...) run:
```
sudo apt-get install libxdo-dev libgtk-3-dev
```

## Installation
1. Make sure you are running `Xorg` display server. If not sure logout from your session. On the GNOME login screen click ⚙ icon on the bottom right. Select `GNOME on Xorg`. Log in.
2. Check out the repository to some arbitrary location and run the `install.sh` script in Terminal. Script will ask for administrator password.

```
mkdir -p ~/Downloads && cd ~/Downloads
rm -rf ./linuxtyper
git clone https://github.com/huyenngn/linuxtyper.git
cd linuxtyper
chmod +x ./install.sh
./install.sh
```

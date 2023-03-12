# LinuxTyper

LinuxTyper is a productivity tool written in C that automates repetitive typing tasks at specified intervals in a selected window. The GUI is built with GTK, allowing it to integrate smoothly with most Linux desktops.

Users can input a desired time in seconds and up to five different phrases, then select a window by clicking on it. At the specified time interval Linuxtyper chooses a random phrase and types it into the selected window.
        
While other auto-typers require users to keep the cursor on the selected window, LinuxTyper can run in the background. Even if the selected window is minimized, LinuxTyper will automatically maximize it to execute the routine and then minimize it again.

LinuxTyper remembers previously used phrases the next time the app is opened. 

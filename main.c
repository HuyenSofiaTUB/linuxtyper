#include <stdio.h>
#include <stdlib.h>
#include <xdo.h>
#include <unistd.h>
#include <time.h>

// gcc main.c -lxdo -Wall -o linuxtyper

int main(int argc, char* argv[]) {
    int minimize_toggle = atoi(argv[2]);
    xdo_t * x = xdo_new(":0.0");

    int time = atoi(argv[1]);

    struct timespec *req = (struct timespec*) malloc(sizeof(struct timespec));
    req->tv_sec =  200 / 1000;
    req->tv_nsec = (200 % 1000) * 1000000;
    struct timespec *rem = (struct timespec*) malloc(sizeof(struct timespec));

    Window *window = (Window*)malloc(sizeof(Window));;

    printf("please select a window!\n");
    for(int i = 3; i > 0; i--) {
        sleep(1);
        xdo_get_focused_window(x, window);
        printf("%d \n", i);
    }
    int pid = xdo_get_pid_window(x, *window);
    printf("done selecting window: %d\n", pid);

    while(1) {
        xdo_activate_window(x, *window);
        xdo_send_keysequence_window(x, *window, "Return", 2);

        nanosleep(req,rem);

        xdo_enter_text_window(x, *window, "o/", 0);
        xdo_send_keysequence_window(x, *window, "Return", 2);

        if (minimize_toggle != 0) {
            nanosleep(req, rem);
            xdo_minimize_window(x, *window);
            xdo_send_keysequence_window(x, *window, "Return", 2);
        }

        printf("sleeping for %d seconds...\n", time);
        sleep(time);
    }
    return 0;
}

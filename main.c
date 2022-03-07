#include <stdio.h>
#include <stdlib.h>
#include <xdo.h>
#include <unistd.h>
#include <time.h>
#define NUMBER_OF_STRING 5
#define MAX_STRING_SIZE 40

// gcc main.c -lxdo -Wall -o linuxtyper

void select_window(xdo_t * x, Window * window) {
    for(int i = 5; i > 0; i--) {
        sleep(1);
        xdo_get_focused_window(x, window);
        printf("%d \n", i);
    }
    int pid = xdo_get_pid_window(x, *window);
    printf("done selecting window: %d\n", pid);
}

int main(int argc, char* argv[]) {

    int minimize_toggle = 1;
    xdo_t * x = xdo_new(":0.0");
    struct timespec *req = (struct timespec*) malloc(sizeof(struct timespec));
    req->tv_sec =  200 / 1000;
    req->tv_nsec = (200 % 1000) * 1000000;
    struct timespec *rem = (struct timespec*) malloc(sizeof(struct timespec));

    struct timespec * current_time = (struct timespec*) malloc(sizeof(struct timespec));
    struct timespec * saved_time= (struct timespec*) malloc(sizeof(struct timespec));


    Window *window = (Window*)malloc(sizeof(Window));;

    char text[NUMBER_OF_STRING][MAX_STRING_SIZE] =
            { "test string 1",
              "test string 2",
              "test string 3",
              "test string 4"
            };

    printf("minimize window after typing? [Y/n] ");
    char c = getchar();
    switch (c) {
        case 'y': case 'Y':
            minimize_toggle = 1;
            break;
        case 'n': case 'N':
            minimize_toggle = 0;
            break;
        default:
            minimize_toggle = 1;
            break;
    }

    printf("enter a time: ");
    int time = 10;
    scanf("%d", &time);

    printf("please select a window!\n");
    select_window(x, window);

    while(1) {
        xdo_activate_window(x, *window);
        xdo_send_keysequence_window(x, *window, "Return", 2);

        nanosleep(req,rem);

        int r = rand() % NUMBER_OF_STRING;

        xdo_enter_text_window(x, *window, text[r], 0);
        xdo_send_keysequence_window(x, *window, "Return", 2);

        if (minimize_toggle != 0) {
            nanosleep(req, rem);
            xdo_minimize_window(x, *window);
            xdo_send_keysequence_window(x, *window, "Return", 2);
        }

        printf("sleeping for %d seconds...\n", time);
        clock_gettime(CLOCK_REALTIME, current_time);
        clock_gettime(CLOCK_REALTIME, saved_time);
        while(current_time->tv_sec < (saved_time->tv_sec + time)) {
            clock_gettime(CLOCK_REALTIME, current_time);
        }
    }
    return 0;
}

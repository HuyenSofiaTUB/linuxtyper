
// Libraries
#include <gtk-3.0/gtk/gtk.h> // GTK Library
#include <stdio.h>
#include <stdlib.h>
#include <xdo.h>
#include <unistd.h>
#include <time.h>

// Objects
GtkWidget *uiwindow; // Window
GtkLabel *uiselected; // Label
GtkEntry* text[5];
GtkEntry* uitime;
GtkButton* uistartbutton;

// Variables
struct timespec *req;
struct timespec *rem;
struct timespec * current_time;
struct timespec * saved_time;
int intervall = 10;

int toggle = 0;
int start_toggle = 0;
char* state[2] = {"Start", "Pause"};
xdo_t * x;
Window *window;


void func() {
    clock_gettime(CLOCK_REALTIME, current_time);
    while((current_time->tv_sec > (saved_time->tv_sec + intervall)) && (start_toggle != 0)) {
        printf("tim in yall\n");
        xdo_activate_window(x, *window);
        xdo_send_keysequence_window(x, *window, "Return", 2);

        nanosleep(req,rem);

        int r = rand() % 5;

        xdo_enter_text_window(x, *window, gtk_entry_get_text(text[r]), 0);
        xdo_send_keysequence_window(x, *window, "Return", 2);

        if (toggle != 0) {
            nanosleep(req, rem);
            xdo_minimize_window(x, *window);
            xdo_send_keysequence_window(x, *window, "Return", 2);
        }

        printf("sleeping for %d seconds...\n", intervall);
        clock_gettime(CLOCK_REALTIME, saved_time);
    }
}

// Main function
int main(int argc, char *argv[])
{
    GtkBuilder *builder; // GTK Builder variable
    gtk_init(&argc, &argv); // Start GTK

    builder = gtk_builder_new(); // Create GTK UI Builder
    gtk_builder_add_from_file(builder, "gui.glade", NULL); // Load our UI file

    // Assign the Variables
    uiwindow = GTK_WIDGET(gtk_builder_get_object(builder, "uiwindow")); // Load our window named MyWindow

    text[0] = GTK_ENTRY(gtk_builder_get_object(builder, "uitext1"));
    text[1] = GTK_ENTRY(gtk_builder_get_object(builder, "uitext2"));
    text[2] = GTK_ENTRY(gtk_builder_get_object(builder, "uitext3"));
    text[3] = GTK_ENTRY(gtk_builder_get_object(builder, "uitext4"));
    text[4] = GTK_ENTRY(gtk_builder_get_object(builder, "uitext5"));

    uiselected = GTK_LABEL(gtk_builder_get_object(builder, "uiselected")); // Load our label named MyLabel
    uitime = GTK_ENTRY(gtk_builder_get_object(builder, "uitime"));
    uistartbutton = GTK_BUTTON(gtk_builder_get_object(builder, "uistartbutton"));

    // Essential for a GTK based program
    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);

    // Setup
    x = xdo_new(":0.0");
    window = (Window*)malloc(sizeof(Window));

    req = (struct timespec*) malloc(sizeof(struct timespec));
    req->tv_sec =  200 / 1000;
    req->tv_nsec = (200 % 1000) * 1000000;
    rem = (struct timespec*) malloc(sizeof(struct timespec));

    current_time = (struct timespec*) malloc(sizeof(struct timespec));
    saved_time= (struct timespec*) malloc(sizeof(struct timespec));
    clock_gettime(CLOCK_REALTIME, saved_time);

    // Run our program
    gtk_widget_show_all(uiwindow); // Show our window
    gtk_main();

    return 0; // Necessary for a c main function
}

// Function to exit our app
void exit_app()
{
    printf("Exit app \n"); // Not neccesary
    gtk_main_quit(); // Command to quit a GTK program
}

// Function when our button is pressed
void start_clicked()
{
    intervall = atoi(gtk_entry_get_text(uitime));
    start_toggle = !start_toggle;
    gtk_button_set_label(uistartbutton, state[start_toggle]);
    clock_gettime(CLOCK_REALTIME, saved_time);
    printf("tstart %d\n", start_toggle);
    gdk_threads_add_idle((GSourceFunc)func, NULL);
}

void minimize_toggled()
{
    toggle = !toggle;
    printf("toggle the min %d\n", toggle);

}

void select_clicked()
{
    char str[10];
    printf("pleek choose \n");
    for(int i = 5; i > 0; i--) {
        sleep(1);
        xdo_get_focused_window(x, window);
        printf("%d \n", i);
    }
    printf("done choose \n");
    int pid = xdo_get_pid_window(x, *window);
    sprintf(str, "%d", pid);
    gtk_label_set_text(uiselected, str);
}

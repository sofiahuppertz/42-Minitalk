#include "../minitalk.h"
int main(int argc, char *argv[])
{
    struct sigaction c_handler;
    int server_pid;
    char *str;

    server_pid = 0;
    str = NULL;

    init(&server_pid, &str, argc, argv);
    set_signal_handler(&c_handler, client_sighandler);
    send_message(str, server_pid);
    exit(0);    
}




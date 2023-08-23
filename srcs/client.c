#include "../minitalk.h"
int main(int argc, char *argv[])
{
    struct sigaction handler;
    sigset_t mask_set;
    int server_pid;
    char *str;

    server_pid = 0;
    str = NULL;

    sigemptyset(&mask_set);
    int i = 1;
    while (i < NSIG)
    {
        if (i != SIGUSR1 && i != SIGUSR2)
            sigaddset(&mask_set, i);
        i += 1;
    }
    handler.sa_handler = client_signal_handler;
    handler.sa_flags = SA_RESTART;
    handler.sa_mask = mask_set;

    sigaction(SIGUSR1, &handler, NULL);
    sigaction(SIGUSR2, &handler, NULL);

    init(&server_pid, &str, argc, argv);
    send_message(str, server_pid);
    
}


void client_signal_handler(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("received bit: 0\n");
    else
        ft_printf("received bit: 1\n");
}


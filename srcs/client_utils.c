#include "../minitalk.h"

int init(int *server_pid, char **str, int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_printf("Usage: ./client [server_pid] [string]\n");
        exit(0);
    }
    *server_pid = ft_atoi(argv[1]);
    *str = ft_strdup(argv[2]);
    return(1);
}

void client_sighandler(int signum, siginfo_t *source, void *context)
{
    (void)source;
    (void)context;
    if (signum == SIGUSR1)
        ft_printf("received bit: 0\n");
    else
        ft_printf("received bit: 1\n");
}


int    send_message(char *str, int s_pid)
{
    unsigned char character;
    int bits_count;
    int l_s_b;

    while (*str)
    {
        character = *str;
        bits_count = 0;
        while (bits_count < 8)
        {
            l_s_b = character & 1;
            if (l_s_b == 0)
                kill(s_pid, SIGUSR1);
            if (l_s_b == 1)
                kill(s_pid, SIGUSR2);
            character = character >> 1;
            bits_count += 1;
            usleep(1000);
        }
        str++;
    }
    return(1);
} 
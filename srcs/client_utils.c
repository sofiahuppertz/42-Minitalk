#include "../minitalk.h"

void init(int *server_pid, char **str, int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_printf("Usage: ./client [server_pid] [string]\n");
        exit(0);
    }
    *server_pid = ft_atoi(argv[1]);
    *str = ft_strdup(argv[2]);
}

void    send_message(char *str, int pid)
{
    unsigned char byte;
    int bit;
    int i;
    int lsb;

    i = 0;
    while (str[i])
    {
        byte = str[i];
        bit = 0;
        while (bit < 8)
        {
            lsb = byte & 1;
            if (lsb == 0)
                kill(pid, SIGUSR1);
            if (lsb == 1)
                kill(pid, SIGUSR2);
            byte = byte >> 1;
            bit += 1;
            usleep(1500);
        }
    }
    exit(0);
}
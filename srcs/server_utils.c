#include "../minitalk.h"

volatile uint16_t state;

void server_sighandler(int signum, siginfo_t *source, void *context)
{
    u_int16_t bit;
    u_int8_t count;
    static int sender_id;

    (void)context;
    kill(source->si_pid, signum);
    bit = signum == SIGUSR1 ? 0 : 1;
    count = (state >> 8) & 0xFF;
    state = state | (bit << count);
    count += 1;
    state = (state & 0x00FF) | (count << 8); //first clear state... then add count.
    if (count == 8)
    {
        if (sender_id != 0 && sender_id != source->si_pid)
        {
            ft_printf("\n"); 
            sender_id = source->si_pid;
        }
        else if (sender_id == 0)
            sender_id = source->si_pid;

        ft_printf("%c", (char)state & 0x00FF);
        state = 0;
    }
}

int print_pid(void)
{
    pid_t pid;

    pid = getpid();
    ft_printf("%d\n", pid);
    return (1);
}

int wait_for_signal(void)
{
    int time_passed;
    int time_limit;

    time_passed = 0;
    time_limit = 900;
    while (time_passed < time_limit)
    {
        sleep(1);
        time_passed += 1;
    }
    return(1);
}
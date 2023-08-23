#include "../minitalk.h"

volatile uint16_t state;


int main(void)
{
    struct sigaction action;
    sigset_t mask_set;
    int time_passed;
    int time_limit;
    int i;
    int pid;


    pid = getpid();
    ft_printf("%d\n", pid);

    i = 1;
    sigemptyset(&mask_set);
    while (i < NSIG)
    {
        if (i != SIGUSR1 && i != SIGUSR2)
            sigaddset(&mask_set, i);
        i += 1;
    }
    action.sa_sigaction = action_handler;
    action.sa_flags = SA_RESTART |  SA_SIGINFO | SA_NODEFER;
    action.sa_mask = mask_set;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    time_passed = 0;
    time_limit = 360;
    while (time_passed < time_limit)
    {
        sleep(1);
        time_passed += 1;
    }
    return (0);
}


void action_handler(int signum, siginfo_t *source, void *context)
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
        if (sender_id == 0)
            sender_id = source->si_pid;

        ft_printf("%c", (char)state & 0x00FF);
        state = 0;
    }
}

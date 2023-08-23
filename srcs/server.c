#include "../minitalk.h"

volatile uint16_t state;
//upper 8 bits are the count of bits received
//lower 8 bits are the byte being received

int main(void)
{
    struct sigaction action;
    sigset_t mask_set;
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
    action.sa_handler = action_handler;
    action.sa_flags = SA_RESTART;
    action.sa_mask = mask_set;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (1)
    {
        pause();
    }
}


void action_handler(int signum)
{
    u_int16_t bit;
    u_int8_t count;

    bit = signum == SIGUSR1 ? 0 : 1;
    count = (state >> 8) & 0xFF;
    state = state | (bit << count);
    count += 1;
    state = (state & 0x00FF) | (count << 8); //first clear state... then add count.
    if (count == 8)
    {
        ft_printf("%c", (char)state & 0x00FF);
        state = 0;
    }
}
//count skips 5 and 6.
//maybe it is wronlgy stored into the state variable
//not sure if the bits are being stored backwards. I receive first lsb. Probably ok...
//Program isn't reading the character.
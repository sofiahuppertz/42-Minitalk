#include "../minitalk.h"

int set_signal_handler(struct sigaction *action, void (*f)(int, siginfo_t *, void *))
{
    sigset_t mask_set;
    int i;

    i = 1;
    sigemptyset(&mask_set);
    while (i < NSIG)
    {
        if (i != SIGUSR1 && i != SIGUSR2)
            sigaddset(&mask_set, i);
        i += 1;
    }
    action->sa_sigaction = f;
    action->sa_flags = SA_RESTART |  SA_SIGINFO | SA_NODEFER;
    action->sa_mask = mask_set;

    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    return (1);
}
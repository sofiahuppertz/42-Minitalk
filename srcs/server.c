#include "../minitalk.h"

int main(void)
{
    struct sigaction s_handler;

    print_pid();
    set_signal_handler(&s_handler, server_sighandler);
    wait_for_signal();

    return (0);
}

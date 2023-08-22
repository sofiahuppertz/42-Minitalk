#include "../minitalk.h"
int main(int argc, char *argv[])
{
    int server_pid;
    char *str;

    server_pid = 0;
    str = NULL;

    init(&server_pid, &str, argc, argv);
    send_message(str, server_pid);
}





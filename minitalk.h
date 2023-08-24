#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "42-Libft/libft/ft_printf.h"
# include "42-Libft/libft/libft.h"



void    server_sighandler(int signum, siginfo_t *source, void *context);
void client_sighandler(int signum, siginfo_t *source, void *context);
int     init(int *server_pid, char **str, int argc, char *argv[]);
int     print_pid(void);
int     send_message(char *str, int pid);
int set_signal_handler(struct sigaction *action, void (*f)(int, siginfo_t *, void *));
int     wait_for_signal(void);

#endif

// TODO: fix memory leaks
// Norminette
// Test bugs

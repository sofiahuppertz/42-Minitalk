#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "42-Libft/libft/ft_printf.h"
# include "42-Libft/libft/libft.h"



void client_signal_handler(int signum);
void action_handler(int signum, siginfo_t *source, void *context);
void init(int *server_pid, char **str, int argc, char *argv[]);
void    send_message(char *str, int pid);

#endif

// TODO: fix memory leaks
// Readable code (norminette)
// Possible bugs: passing incorrect values

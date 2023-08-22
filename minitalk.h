#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "42-Libft/libft/ft_printf.h"
# include "42-Libft/libft/libft.h"


void action_handler(int signum);
void init(int *server_pid, char **str, int argc, char *argv[]);
void    send_message(char *str, int pid);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:51:36 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 12:12:55 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "42-Libft/libft/ft_printf.h"
# include "42-Libft/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	server_sighandler(int signum, siginfo_t *source, void *context);
void	client_sighandler(int signum, siginfo_t *source, void *context);
int		init(int *server_pid, char **str, int argc, char *argv[]);
int		print_pid(void);
int		send_message(char *str, int pid);
int		set_signal_handler(struct sigaction *action, void (*f)(int, siginfo_t *,
				void *));
int		wait_for_signal(void);

#endif
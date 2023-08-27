/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:48:17 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:11:44 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

volatile uint16_t	g_state;

void	server_sighandler(int signum, siginfo_t *source, void *context)
{
	u_int16_t	bit;
	u_int8_t	count;
	static int	sender_id;

	(void)context;
	bit = 1;
	if (signum == SIGUSR1)
		bit = 0;
	count = (g_state >> 8) & 0xFF;
	g_state = g_state | (bit << count);
	count += 1;
	g_state = (g_state & 0x00FF) | (count << 8);
	if (count == 8)
	{
		if (sender_id != 0 && sender_id != source->si_pid)
		{
			ft_printf("\n");
			sender_id = source->si_pid;
		}
		else if (sender_id == 0)
			sender_id = source->si_pid;
		ft_printf("%c", (char)g_state & 0x00FF);
		g_state = 0;
	}
	kill(source->si_pid, signum);
}

int	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	return (1);
}

int	wait_for_signal(void)
{
	while (1)
	{
		pause();
	}
}

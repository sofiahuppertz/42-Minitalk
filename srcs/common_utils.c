/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:33 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 12:09:18 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	set_signal_handler(struct sigaction *action, void (*f)(int, siginfo_t *,
			void *))
{
	sigset_t	mask_set;
	int			i;

	i = 1;
	sigemptyset(&mask_set);
	while (i < NSIG)
	{
		if (i != SIGUSR1 && i != SIGUSR2)
			sigaddset(&mask_set, i);
		i += 1;
	}
	action->sa_sigaction = f;
	action->sa_flags = SA_RESTART | SA_SIGINFO | SA_NODEFER;
	action->sa_mask = mask_set;
	if (sigaction(SIGUSR1, action, NULL) != 0)
	{
		perror("SIGUSR1");
		exit(1);
	}
	if (sigaction(SIGUSR2, action, NULL) != 0)
	{
		perror("SIGUSR2");
		exit(1);
	}
	return (1);
}

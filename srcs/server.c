/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:48:34 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 12:06:05 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(void)
{
	struct sigaction	s_handler;

	print_pid();
	set_signal_handler(&s_handler, server_sighandler);
	wait_for_signal();
	return (0);
}

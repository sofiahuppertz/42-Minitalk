/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:47:04 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:13:46 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char *argv[])
{
	struct sigaction	c_handler;
	int					server_pid;
	char				*str;

	server_pid = 0;
	str = NULL;
	init(&server_pid, &str, argc, argv);
	set_signal_handler(&c_handler, client_sighandler);
	send_message(str, server_pid);
	exit(0);
}

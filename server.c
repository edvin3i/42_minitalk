/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:19:54 by gbreana           #+#    #+#             */
/*   Updated: 2022/02/21 15:14:47 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/minitalk.h"
#include "include/libft.h"

#include <stdio.h>

void	ft_sighandler(int signum, siginfo_t *signal, void *context)
{
	ft_printf("I feel a signal\n");
	sleep(1);
}



int main(int argc, char **argv)
{
	int 	self_pid;
	struct	sigaction sigact;

	self_pid = getpid();
	ft_printf("PID: %d\n", self_pid);

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);

	while (1)
		usleep(100);

	return 0;
}

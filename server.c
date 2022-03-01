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

#include <stdio.h>
void	ft_sighandler(int signum, siginfo_t *signal, void *context)
{
	printf("I feel signal");
	sleep(1);
}



int main(int argc, char **argv)
{
	int 	pid;
	struct	sigaction sigact;

	pid = getpid();
	printf("PID: %d\n", pid);
	while (1)
	{
		sigact.sa_flags = SA_SIGINFO;
		sigact.sa_sigaction = ft_sighandler;
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);

	}

	return 0;
}

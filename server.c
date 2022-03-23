/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:19:54 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/06 13:43:00 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include "include/libft.h"

void	ft_sighandler(int signum, siginfo_t *info, void *context)
{
	static pid_t			src_pid;
	static int				bit = 7;
	static unsigned char	c = 0;

	(void) context;
	if (info->si_pid)
		src_pid = info->si_pid;
	if (signum == SIGUSR2)
		c |= (1 << bit);
	else if (signum == SIGUSR1)
		c &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		if (c)
		{
			write(1, &c, 1);
			kill(src_pid, SIGUSR1);
		}
		else
			kill(src_pid, SIGUSR2);
		bit = 7;
		c = 0;
	}
}

int	main(void)
{
	pid_t				self_pid;
	struct sigaction	sigact;
	sigset_t			set;

	self_pid = getpid();
	ft_printf("Server PID: %d\n", self_pid);
	ft_bzero(&sigact, sizeof sigact);
	sigact.sa_sigaction = ft_sighandler;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigact.sa_mask = set;
	sigact.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sigact, NULL) != 0) || \
					(sigaction(SIGUSR2, &sigact, NULL) != 0))
	{
		ft_printf("Sigaction error!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}

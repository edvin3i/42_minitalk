/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:19:54 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/06 13:43:08 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/libft.h"

char	*g_message;

void	ft_sendchar(pid_t pid, const unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		usleep(50);
	}
	g_message++;
}

void	ft_resphandler(pid_t signum, siginfo_t *info, void *context)
{
	pid_t	srv_pid;

	(void)context;
	if (info->si_pid)
		srv_pid = info->si_pid;
	if (signum == SIGUSR1)
		ft_sendchar(srv_pid, *g_message);
	else if (signum == SIGUSR2)
	{
		ft_printf("\nMessage sent!\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction			act;
	sigset_t					set;

	if (argc != 3 || !argv[2])
	{
		ft_printf("Usage: ./client PID STRING\n");
		return (1);
	}
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_sigaction = ft_resphandler;
	if ((sigaction(SIGUSR1, &act, NULL) != 0) || \
					(sigaction(SIGUSR2, &act, NULL) != 0))
	{
		ft_printf("Sigaction error!");
		return (1);
	}
	g_message = argv[2];
	ft_sendchar(ft_atoi(argv[1]), *g_message++);
	while (1)
		pause();
	return (0);
}

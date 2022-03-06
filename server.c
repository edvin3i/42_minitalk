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
#include "include/minitalk.h"
#include "include/libft.h"


void	ft_sighandler(int signum, siginfo_t *info, void *context)
{
	static int              bit = 0;
    static pid_t            src_pid;
    static unsigned char    c = 0;

    (void)context;

    if (src_pid == 0)
        src_pid = info->si_pid;
    if (signum == SIGUSR2)
    {
        c |= (1 << bit);
        ft_putchar('1');
    }
    else if (signum == SIGUSR1)
    {
        ft_putchar('0');
    }

    if (bit++ == 7)
    {
        ft_putchar('\n');
        ft_putchar(c);
        ft_putchar('\n');
        c = 0xFF;
        bit = 0;
    }


}



int main()
{
    pid_t 	self_pid;
    struct	sigaction sigact;

	self_pid = getpid();
	ft_printf("Server PID: %d\n", self_pid);


	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_sighandler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
    sigemptyset(&sigact.sa_mask);

	while (1)
		pause();
    return (0);
}

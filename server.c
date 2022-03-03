/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:19:54 by gbreana           #+#    #+#             */
/*   Updated: 2022/02/22 15:14:47 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/minitalk.h"
#include "include/libft.h"

void	ft_sighandler(int signum, siginfo_t *info, void *context)
{
	static int             i;
    static pid_t           src_pid;
    static unsigned char   c;

    (void)context;
    if (src_pid == 0)
        src_pid = info->si_pid;
    ft_printf("I feel a signal from: %d\n", src_pid);
    i = 0;
    c = 0;
    c |= (signum == SIGUSR2);
    if (++i == 8)
    {
        i = 0;
        if (!c)
        {
            kill(src_pid, SIGUSR2);
            src_pid = 0;
            return ;
        }
        putchar(c);
        c = 0;
        kill(src_pid, SIGUSR1);
    }
    else
        c <<= 1;

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

	while (1)
		sleep(1);

	return 0;
}

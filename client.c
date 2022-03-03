/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:19:54 by gbreana           #+#    #+#             */
/*   Updated: 2022/02/22 15:14:47 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/minitalk.h"
#include "include/libft.h"


void ft_sendchar(pid_t pid, char c)
{
    int i = 7;
    while(i >= 0)
    {
        if (c & (1 << i))
        {
            kill(pid, SIGUSR2);
            ft_putchar('1');
        }
        else
        {
            kill(pid, SIGUSR1);
            ft_putchar('0');
        }
        i--;
    }
}


int     main(int argc, char **argv)
{
	pid_t	serv_pid;


	if (argc != 3 && !argv[2])
		return (1);
	else
	{
		serv_pid = ft_atoi(argv[1]);

        ft_printf("PID: %d\n", serv_pid);
        while (*argv[2])
        {
            ft_sendchar(serv_pid,*argv[2]);
            argv[2]++;
        }
	}

	return 0;
}

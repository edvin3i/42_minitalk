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

void    ft_sendchar(pid_t pid, char c)
{
    int curr_bit;

    curr_bit = 0;
    while(curr_bit <= 7)
    {
        if (c & (1 << curr_bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        curr_bit++;
    }
}

void printbincharpad(char c)
{
    for (int i = 7; i >= 0; --i)
    {
        ft_putchar( (c & (1 << i)) ? '1' : '0' );
    }
    putchar('\n');
}

int     main(int argc, char **argv)
{
	pid_t	serv_pid;
    int     i;
	char	c;
	struct	sig;

	if (argc != 3 && !argv[2])
		return (1);
	else
	{
		serv_pid = atoi(argv[1]);
        i = 0;
        while (argv[2][i])
        {
            c = argv[2][i];
            ft_sendchar(serv_pid, c);
            i++;
        }

	}


	printf("PID: %d\n", serv_pid);
    while (argv[2])
    printbincharpad()

	return 0;
}

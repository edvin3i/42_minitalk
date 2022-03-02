/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
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

int main(int argc, char **argv)
{
	int 	pid;
	char	msg;
	struct	sig;

	if (argc != 3 && !argv[2])
		return (1);
	else
	{
		pid = ft_atoi(argv[1]);
		kill(pid, SIGUSR1);

	}


	printf("PID: %d\n", pid);

	return 0;
}

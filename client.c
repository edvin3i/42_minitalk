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

static int	ft_check_lllim(unsigned long long n, int sign)
{
	if (n >= LLONGMAX && sign == 1)
		return (-1);
	if (n >= LLONGMAX + 1 && sign == -1)
		return (0);
	return (21);
}

int	ft_atoi(const char *str)
{
	int					sign;
	int					len;
	unsigned long long	result;

	sign = 1;
	len = 0;
	result = 0;
	while (*str == 0x20 || (0x09 <= *str && *str <= 0x0d))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str) && 0x30 <= *str && *str <= 0x39)
	{
		result = result * 10 + *str - 0x30;
		str++;
		len++;
	}
	if (ft_check_lllim(result, sign) == 0 || ft_check_lllim(result, sign) == -1)
		return ((int)ft_check_lllim(result, sign));
	return ((int)result * sign);
}


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

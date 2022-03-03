/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:18:12 by gbreana           #+#    #+#             */
/*   Updated: 2022/02/21 12:12:52 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
/*
 * Includes
 */
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>


#include <stdio.h>
#include <string.h>



/*
 * Macroses
 */
# define LLONGMAX 		9223372036854775807ull

/*
 * Functions
 */
void	ft_sighandler(int signum, siginfo_t *signal, void *context);

#endif
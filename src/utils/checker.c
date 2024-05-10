/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:59 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 14:10:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minishell.h"

/* Checking if the person ran ./minishell without mistakes (e.g. extra
argument). One sole argument can be used to run ./minishell */

void	arg_checker(int argc, char **argv)
{
	if (argc > 1 || !argv[0])
	{
		ft_putstr_fd("Error, try again by running ./minishell", STDERR_FILENO);
		exit(0);
	}
}
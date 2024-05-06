/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:23 by srudman           #+#    #+#             */
/*   Updated: 2024/05/06 16:26:01 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_missing_env(t_shell *shell, char **env)
{
	if ()
}

void	env_handling(t_shell *shell, char **env)
{
	if (env == NULL)
	{
		shell->env_exists = false;
		init_missing_env(shell, env);
	}
	else
	{
		shell->env_exists == true;
		shell->env = copy_env();
	}
}



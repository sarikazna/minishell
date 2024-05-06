/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:23 by srudman           #+#    #+#             */
/*   Updated: 2024/05/06 18:23:21 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* What env do we have to add or handle? */
void	init_missing_env(t_shell *shell, char **envp)
{
	if (get_env_var(shell, "USER=") == NULL)
		shell->env[ft_strlen] = ft_strdup("USER="); // so just leave it empty or assign it a value?
	if (get_env_var(shell, "SHLVL=") == NULL)
		shell->env[ft_strlen] = ft_strdup("SHLVL=1");
	if (get_env_var(shell, "_=/usr/bin") == NULL)
		shell->env[ft_strlen] = ft_strdup("_=/usr/bin/env");
	if (get_env_var(shell, "OLDPWD=") == NULL)
		shell->env[ft_strlen] = ft_strjoin_modified("OLDPWD=", /* I need pwd here. I think I need to use getcwd() function*/);
	if (get_env_var(shell, "PWD=") == NULL)
		shell->env[ft_strlen] = ft_strjoin_modified("PWD=", /* I need pwd here. I think I need to use getcwd() function*/);
}

void	copy_env(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	while(envp[i] && shell->env[i])
	{
		shell->env[i] = ft_strdup(envp[i]);
		i++;
	}
}

void	env_handling(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	if (envp != NULL)
	{
		shell->env_exists == true;
		shell->env = copy_env(shell, envp);
		while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
			i++;
		if (ft_strncmp("PATH=", envp[i], 5) != 0)
			shell->table->cmd->path = NULL;
		else
			shell->table->cmd->path = ft_split(envp[find where PATH] + 5, ':');
	}
	else
	{
		shell->env_exists = false;
		shell->table->cmd->path = NULL;
	}
	init_missing_env(shell, envp);
}



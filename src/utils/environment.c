/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:23 by srudman           #+#    #+#             */
/*   Updated: 2024/07/23 16:51:18 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// SARA TO DO: seg fault when env -i ./minishell
int	ft_last_array(char **array)
{
	int	i;
	
	i = 0;
	while(array[i] != NULL)
		i++;
	return(i);
}

char	*get_env_var(t_shell *shell, char *var)
{
	int		i;
	char	*env_var;

	i = 0;
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(var, shell->env[i], ft_strlen(var)) == 0)
		{
			env_var = ft_strdup(shell->env[i]);
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

/* What env do we have to add or handle? */
void	init_missing_env(t_shell *shell)
{
	if (get_env_var(shell, "USER=") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("USER=");
	else if (get_env_var(shell, "HOSTNAME=") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("HOSTNAME=");
	else if (get_env_var(shell, "SHLVL=") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("SHLVL=1");
	else if (get_env_var(shell, "_=/usr/bin") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("_=/usr/bin/env");
	// if (get_env_var(shell, "OLDPWD=") == NULL)
	// 	shell->env[ft_last_array(shell->env)] = ft_strjoin_modified("OLDPWD=", /* I need pwd here. I think I need to use getpwd() function*/);
	// if (get_env_var(shell, "PWD=") == NULL)
	// 	shell->env[ft_last_array(shell->env)] = ft_strjoin_modified("PWD=", /* I need pwd here. I think I need to use getpwd() function*/);
}

char	**copy_env(char **envp, char **new_envp)
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		new_envp[i] = ft_strdup(envp[i]);
		// printf("Copy of envp: %s\n\n", shell->env[i]);
		i++;
	}
	return (new_envp);
}

int	count_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	env_handling(t_shell *shell, char **envp)
{
	int	i;
	char **new_envp;

	i = 0;
	new_envp = (char **)malloc((sizeof(char *) * count_env(envp)) + 1);
	(void)i; // delete after
	if (envp != NULL)
	{
		//printf("Env copy: %s\n", envp[i]);
		// left off here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		shell->env_exists = true;
		new_envp = copy_env(envp, new_envp);
		while (new_envp[i] && ft_strncmp("PATH=", new_envp[i], 5) != 0)
		 	i++;
		if (ft_strncmp("PATH=", new_envp[i], 5) != 0)
		{
		 	printf("Path doesn't exist\n\n"); // don't forget to delete
		 	shell->table->cmd->path = NULL;
		}
		else
		{
			shell->table->cmd->path = ft_split(new_envp[i] + 5, ':');
		}
	}
	else
	{
		shell->env_exists = false;

		shell->table->cmd->path = NULL;
	}
	shell->env = new_envp;
	//init_missing_env(shell);
}

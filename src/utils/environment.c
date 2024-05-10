/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:23 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 16:16:13 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minishell.h"

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
void	init_missing_env(t_shell *shell, char **envp)
{
	if (get_env_var(shell, "USER=") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("USER=");
	if (get_env_var(shell, "HOSTNAME=") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("HOSTNAME=");
	if (get_env_var(shell, "SHLVL=") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("SHLVL=1");
	if (get_env_var(shell, "_=/usr/bin") == NULL)
		shell->env[ft_last_array(shell->env)] = ft_strdup("_=/usr/bin/env");
	// if (get_env_var(shell, "OLDPWD=") == NULL)
	// 	shell->env[ft_last_array(shell->env)] = ft_strjoin_modified("OLDPWD=", /* I need pwd here. I think I need to use getpwd() function*/);
	// if (get_env_var(shell, "PWD=") == NULL)
	// 	shell->env[ft_last_array(shell->env)] = ft_strjoin_modified("PWD=", /* I need pwd here. I think I need to use getpwd() function*/);
	(void)envp;
}

void	copy_env(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		shell->env[i] = ft_strdup(envp[i]);
		// printf("Copy of envp: %s\n\n", shell->env[i]);
		i++;
	}
}

void	env_handling(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	(void)i;
	if (envp != NULL)
	{
		shell->env_exists = true;
		copy_env(shell, envp);
		while (shell->env[i] && ft_strncmp("PATH=", shell->env[i], 5) != 0)
		 	i++;
		if (ft_strncmp("PATH=", shell->env[i], 5) != 0)
		{
		 	printf("Path doesn't exist\n\n");
		 	shell->table->cmd->path = NULL;
		}
		else
		{
		printf("infile: %d\n", shell->table->infile);
    	printf("outfile: %d\n", shell->table->outfile);
    	printf("errfile: %d\n", shell->table->errfile);
    	printf("infile_valid: %d\n", shell->table->infile_valid);
    	printf("outfile_valid: %d\n", shell->table->outfile_valid);
    	printf("pipes: %d\n", shell->table->pipes);
		// printf("PATH environment: %s\n\n", envp[i]);
		// i = 0;
		// while (shell->table->cmd->path[i])
		// 	printf("Struct to path: %s\n\n", envp[i]);
		// shell->table->cmd->path = ft_split(shell->env[i] + 5, ':');
		}
	}
	// else
	// {
	// 	shell->env_exists = false;
	// 	shell->table->cmd->path = NULL;
	// }
	// init_missing_env(shell, envp);
}



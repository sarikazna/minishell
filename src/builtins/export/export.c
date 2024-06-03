/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:36:18 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/02 16:20:58 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	export(t_shell *shell)
{
	char	**tmp;
	char	**args;
	int		i;

	args = shell->table->cmd->args;
	i = 1;
	if (!args[1] || args[1][0] == '\0')
		env(shell, args);
	else
	{
		while (args[i])
		{
			if (args_check(args[i]) == 0 && var_exist(args[i]) == 0)
			{
				if (args[i])
				{
					tmp = add_var(shell->env, args[i])
					//free env
					shell->env = tmp;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCESS);
}

char	**add_var(char **env, char *str)
{
	char		**new_env;
	size_t		i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		modify_str_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		modify_str_quotes(str, '\'');
	while (env[i] != NULL)
		i++;
	new_env = ft_calloc(sizeof(char *), i + 2); //+2 for the new_env and NULL term
	if (!new_env)
		return (NULL);
	loop_add_var(env, new_env, str);
	return (new_env);
}

char	**loop_add_var(char **env, char **new_env, str)
{
	int	i;

	i = 0;
	while (env[i] != '\0')
	{
		if (env[i + 1] == NULL)
		{
			new_env[i] = ft_strdup(str); 
			new_env[i + 1] = ft_strdup(env[i]); //_=/usr/bin/env
		}
		else
			new_env[i] = ft_strdup(env[i]);
		if (new_env[i] == NULL)
		{
			//free new_env
			return(new_env);
		}
		i++;
	}
	return (new_env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:55:56 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/23 17:34:26 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	invalid_chars(char	*arg)
{
	int	i;
	
	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] == 95 || (arg[i] >= 65 && 122 >= arg[i]) || (arg[i] >= 48 && arg[i] <= 57))
			i++;
		else
			return (1);
	}
	return (0);
}

char	**del_var(char **env, char *str)
{
	char	**new_env;
	size_t	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	new_env = ft_calloc(sizeof(char *), i + 1);
	if (!new_env)
		return (NULL);
	new_env = loop_del_var(env, str);
	return (new_env);
}

char	**loop_del_var(char	**env, char	**new_env, char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (env[i] != NULL)
	{
		if (!(ft_strncmp(arr[i], str, equal_sign(arr[i]) - 1) == 0 && str[equal_sign(arr[i])] == '\0' && arr[i][ft_strlen(str)] == '='))
		{
			new_env[j] = ft_strdup(env[i]);
			if (new_env[j] == NULL)
			{
				//free new_env
				return (new_env); 
			}
			j++;
		}
		i++;
	}
	return (new_env);
}

size_t	equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}
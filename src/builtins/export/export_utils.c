/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:37:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/02 16:08:11 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_identifier(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

int	args_check(char	*str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '=')
		return (export_error(str));
	if (equal_sign(str) == 0)
		return (EXIT_FAILURE);
	while (str[i] != '=')
	{
		if (check_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (EXIT_SUCESS);
}

int	var_exist(t_shell *shell, char *str)
{
	int	i;
	
	i = 0;
	if (str[equal_sign(str)] == '\"')
		modify_str_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		modify_str_quotes(str, '\'');
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], str, equal_sign(shell->env[i])) == 0)
		{
			free(shell->envp[i]);
			shell->env[i] = ft_strdup(str); //updates the value
			return (1);
		}
		i++;
	}
	return (0); //Doesn't exists
}

//Function to remove double quotes or single quotes to help search
char	*modify_str_quotes(char *str, char c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            j = 0;
            while (str[i + j] == c)
                j++;
            ft_strlcpy(&str[i], &str[i + j], strlen(str) - i + 1);
        }
        i++;
    }
    return (str);
}
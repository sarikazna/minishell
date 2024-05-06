/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/06 16:22:40 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Function to create the prompt*/
void	prompt(t_shell *shell)
{
	char	*half;
	char	*final;
	char	*user;
	char	*half2;
	char	*half3;

	if (shell->prompt != NULL)
		free(shell->prompt);
	user = ft_strjoin(shell->username, "@"); //1st username + @
	half = ft_strjoin_modified(user, shell->logname); //username@ + logname
	half2 = ft_strjoin(half, ":~"); //username@logname + :~
	half3 = ft_strjoin_modified(half2, shell->directory); //username@logname:~ + path
	final = ft_strjoin(half3, "$"); //username@logname:~path + $
	free(half);
	free(half3);
	shell->prompt = "on";
}

/*Aditional function to help find the current directory*/

char	*get_curr_dir(t_shell *shell)
{
	int		i;
	char	*directory;
	char	*pwd;

	i = 0;
	pwd = get_env_var(shell, "PWD=");
	
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
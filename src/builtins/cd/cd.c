/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:53:06 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/09 17:34:54 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	cd(t_shell *shell, char *args)
{
	//char	*oldpwd;
	//char	**args;
	
	//args = shell->table->cmd->args;
	//oldpwd = get_env_var(shell, "OLDPWD=") + 7;
	if (args[0] == '\0' || args[0] == 126) //if it's only cd
		cd_home(shell);
	else if (args[0] == 45) //if is cd -
		cd_oldpwd(shell);
	else if (ft_strncmp(args, "..", 2) == TRUE
		|| ft_strncmp(args, "../", 3) == 0) //if is cd .. or cd ../
		normal_cd_back(shell, args);
	else if (args != NULL && ft_strncmp(args, "..", 2) != TRUE
		&& args[0] != '-') //Other normal cd
		normal_cd_back(shell, args);
}

void	add_oldpwd(t_shell *shell)
{
	char	*oldpwd;

	oldpwd = get_env_var(shell, "OLDPWD=");
	if (!oldpwd)
		add_var(shell->env, "OLDPWD=");
}

int	lenght_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	return (i);
}

void	change_var_env(t_shell *shell, char **env, char *search, char *replace)
{
	int	i;
	int	lenght;
	int	search_len;
	
	i = 0;
	search_len = lenght_equal(search);
	while (env[i])
	{
		if (ft_strncmp(env[i], search, search_len) == 0 && env[i][search_len] == '=')
			break;
		i++;
	}
	if (env[i])
	{
		free(env[i]);
		lenght = ft_strlen(replace) + 1;
		env[i] = malloc(sizeof(char) * lenght + 1);
		if (!env[i])
		{
			ft_putstr_fd("minishell: Error allocating memory\n", shell->table->errfile);
			return ;
		}
		ft_strlcpy(env[i], replace, lenght);
	}

}

void	update_pwd_oldpwd(t_shell *shell)
{
	char	*new_pwd;
	char	*new_pwd_join;
	char	*old_pwd_join;
	char	path[PATH_MAX];
	char	*old_pwd;

	add_oldpwd(shell);
	old_pwd = get_env_var(shell, "PWD="); //Gets the actual pwd to put it as oldpwd
	new_pwd = getcwd(NULL, sizeof(path)); 
	new_pwd_join = ft_strjoin("PWD=", new_pwd);
	old_pwd_join = ft_strjoin("OLDPWD=", old_pwd + 4);
	change_var_env(shell, shell->env, "PWD=", new_pwd_join);
	change_var_env(shell, shell->env, "OLDPWD=", old_pwd_join);
	free(old_pwd_join);
	free(new_pwd_join);
	free(new_pwd);
}

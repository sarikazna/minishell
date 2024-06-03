/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:53:06 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/28 16:50:16 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd(t_shell *shell)
{
	char	*oldpwd;
	char	**args;
	
	args = shell->table->cmd->args;
	oldpwd = get_env_var(shell, "OLDPWD=") + 7;
	if (args[1] == NULL)
		cd_home(shell);
	else if (args[1][0] == '~')
		cd_tilde(shell, args[1]);
	else if (args[1] == '-')
		cd_oldpwd(shell);
	else if (ft_strcmp(args[1], "..") == TRUE
		|| ft_strncmp(args[1], "../", 3) == 0)
		normal_cd(shell, args[1]);
	else if (args[1] != NULL && ft_strcmp(args[1], "..") != TRUE
		&& args[1][0] != '-')
		normal_cd(shell, args[1]);
		
}

void	update_pwd_oldpwd(t_shell *shell)
{
	char	*new_pwd;
	char	*pwd_join;
	char	*old_pwd_join;
	char	path[PATH_MAX];
	char	*old_pwd;

	add_oldpwd(shell);
	oldpwd = get_env_var(shell, "OLDPWD=") + 5;
	new_pwd = getcwd(NULL, sizeof(path));
	pwd_join = ft_strjoin("PWD=", new_pwd);
	old_pwd_join = ft_strjoin("OLDPWD=", old_pwd);
	replace_var_content(shell, old_pwd_join, "OLDPWD"); //do export
	replace_var_content(shell, pwd_join, "PWD"); //do export
	free(old_pwd_join);
	free(pwd_join);
	free(new_pwd);
}

void	add_oldpwd(t_shell *shell)
{
	char	*oldpwd;

	oldpwd = get_env_var(shell, "OLDPWD=");
	if (!oldpwd)
		add_to_env(shell, "OLDPWD"); //To do for export
}
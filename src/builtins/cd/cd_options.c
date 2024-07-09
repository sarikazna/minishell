/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:09:03 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/09 17:34:41 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	cd_home(t_shell *shell)
{
	char	*home;

	home = get_env_var(shell, "HOME=") + 5;
	if (!home)
		ft_putstr_fd("minishell: HOME not set\n", shell->table->errfile);
	else if (chdir(home) == -1)
		ft_putstr_fd("minishell:  No such file or directory. The specified path does not exist.\n", shell->table->errfile);
	update_pwd_oldpwd(shell);
}

void	cd_oldpwd(t_shell *shell)
{
	char	*old_pwd;

	if (shell->env_exists == FALSE)
		ft_putstr_fd("minishell: OLDPWD not set\n", shell->table->errfile);
	old_pwd = get_env_var(shell, "OLDPWD=");
	if (!old_pwd)
		ft_putstr_fd("minishell: OLDPWD not set\n", shell->table->errfile);
	else if (old_pwd == NULL)
		printf("\n");
	else if (chdir(old_pwd + 7) == -1)
		ft_putstr_fd("minishell: OLDPWD : No such file or directory\n", shell->table->errfile);
	printf("%s\n", old_pwd + 7);
	update_pwd_oldpwd(shell);
}

void	normal_cd_back(t_shell *shell, char *path)
{
	char *pwd;
	char *new_pwd;
	char *final_pwd;

	pwd = get_env_var(shell, "PWD=");
	new_pwd = ft_strjoin(pwd, "/");
	final_pwd = ft_strjoin(new_pwd, path) + 4;
	if (chdir(final_pwd) == -1)
	{
		ft_putstr_fd("minishell: ", shell->table->errfile);
		ft_putstr_fd(final_pwd, shell->table->errfile);
		perror(" ");
	}
	update_pwd_oldpwd(shell);
}

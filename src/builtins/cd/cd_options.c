/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:09:03 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/28 16:34:25 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cd_home(t_shell *shell)
{
	char	*home;

	home = get_env_var(shell, "HOME=") + 5;
	if (!home)
		ft_putstr_fd("minishell: HOME not set\n", STDERR_FILENO);
	else if (chdir(home) == -1)
		ft_putstr_fd("minishell:  No such file or directory. The specified path does not exist.\n", STDERR_FILENO);
}

void cd_tilde(t_shell *shell, char *path)
{
	char	*home;

	home = get_env_var(shell, "HOME=") + 5;
	if ()
}

void	cd_oldpwd(t_shell *shell)
{
	char	*old_pwd;
	char	*curr_pwd;

	if (shell->env_exists == FALSE)
		ft_putstr_fd("minishell: OLDPWD not set\n", STDERR_FILENO);
	old_pwd = get_env_var(shell, "OLDWPWD=");
	if (!old_pwd)
		ft_putstr_fd("minishell: OLDPWD not set\n", STDERR_FILENO);
	else if (old_pwd == NULL)
		printf("\n");
	else if (chdir(old_pwd + 8) == -1)
		ft_putstr_fd("minishell: OLDPWD : No such file or directory\n", STDERR_FILENO);
	printf("%s\n", old_pwd + 5);
}

void	normal_cd_back(t_shell *shell, char *path)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		perror(" ");
	}
}

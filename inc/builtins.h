/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:48:53 by srudman           #+#    #+#             */
/*   Updated: 2024/07/19 17:58:27 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stddef.h>
# include "minishell.h"

void	pwd(t_shell *shell);
int		env(t_shell *shell);

//cd
void	cd(t_shell *shell, char *args);
void	cd_home(t_shell *shell);
void	cd_oldpwd(t_shell *shell);
void	normal_cd_back(t_shell *shell, char *path);
void	update_pwd_oldpwd(t_shell *shell);

//export
char	**add_var(char **env, char *str);
char	**loop_add_var(char **env, char **new_env, char *str);
int		check_identifier(char c);
int		args_check(char	*str);
int		var_exist(t_shell *shell, char *str);
char	*modify_str_quotes(char *str, char c);

//unset
size_t	equal_sign(char *str);

//echo
void	run_echo(t_shell *shell, char **args, char **cmd_args);
bool	is_flag_valid(char	*flag);
void	echo_print(char *str, int i, int j, int quote);
int 	write_backslash(int backslash_nb, int i);
int		has_quotes(char *str);
bool	is_special_filled(char *str);
int 	echo_n_flag(char **cmd_args, char **args);
bool 	has_content(char **array);

#endif
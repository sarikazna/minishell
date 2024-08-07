/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:41:12 by srudman           #+#    #+#             */
/*   Updated: 2024/07/08 16:17:22 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

void	arg_checker(int argc, char **argv);
void	init_shell(t_shell **shell);

// void	init_table(t_table **table);
char	*get_env_var(t_shell *shell, char *var);
void	env_handling(t_shell *shell, char **envp);

void	signals(void);
void	prompt(t_shell *shell);

#endif
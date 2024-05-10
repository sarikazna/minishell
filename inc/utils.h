/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:41:12 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 14:04:24 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

void	arg_checker(int argc, char **argv);
void	init_shell(t_shell *shell);
void	init_data(t_table *data);
void    init_cmd(t_table *data);
void	env_handling(t_shell *shell, char **envp);


#endif
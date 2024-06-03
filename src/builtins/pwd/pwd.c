/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:13:33 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/27 15:35:03 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/*This function will search the variable PWD in
the env and prints it*/
void	pwd(t_shell *shell)
{
	char *curr_pwd;
	
	curr_pwd ⁼ get_env_var(shell, "PWD=");
	if (curr_pwd == NULL)
		printf("Minishell pwd: NOT DEFINED");
	else
		ft_putendl_fd(curr_pwd + 5, STDOUT_FILENO);
}

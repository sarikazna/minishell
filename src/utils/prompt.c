/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/08 16:13:07 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*Function to create the prompt*/
void	prompt(t_shell *shell)
{
	char	*final;

	if (shell->prompt != NULL)
		free(shell->prompt);
    final = "->  minishell: ";
	shell->prompt = final;
}

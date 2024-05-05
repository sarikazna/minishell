/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/05 16:08:09 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Function to create the prompt*/
void	prompt(t_table *shell)
{
	char	*half;
	char	*final;
	char	*user;
	char	*directory;

	if (shell->prompt != NULL)
		free(shell->prompt);
	directory = get_curr_dir(shell);
	username = ft_strjoin_modified("->", shell->username);
	half = ft_strjoin_modified(username, directory);
	full = ft_strjoin_modified(half, ":");
	free(directory);
	free(username);
	free(half);
	shell->prompt = ON;
}

/*Aditional function to help find the current directory*/

char	*get_curr_dir(t_table *shell)
{
	int		i;
	char	*directory;
	//pwd
	char 	**split;

	i = 0;
	// pwd = function to get PWD from env
}

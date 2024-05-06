/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/06 14:48:33 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Function to create the prompt*/
void	prompt(t_shell *shell)
{
	char	*half;
	char	*final;
	char	*user;

	if (shell->prompt != NULL)
		free(shell->prompt);
	directory = get_curr_dir(shell);
	user = ft_strjoin_modified("->", shell->username);
	half = ft_strjoin_modified(username, directory);
	full = ft_strjoin_modified(half, ":");
	free(directory);
	free(username);
	free(half);
	shell->prompt = "full";
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/06 15:09:59 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Function to create the prompt*/
void	prompt(t_shell *shell)
{
	char	*half;
	char	*final;
	char	*user;
	char 	*directory;

	if (shell->prompt != NULL)
		free(shell->prompt);
	dir = shell->directory;
	user = ft_strjoin(, "@"); //1st username + @
	half = ft_strjoin_modified(username, dir); //username@ + logname
	full = ft_strjoin(half, ":"); //username@logname + :~
	//username@logname:~ + path
	free(dir);
	free(half);
	shell->prompt = "on";
}

/*Aditional function to help find the current directory*/

char	*get_curr_dir(t_shell *shell)
{
	int		i;
	char	*directory;
	//pwd

	i = 0;
	// pwd = function to get PWD from env
}

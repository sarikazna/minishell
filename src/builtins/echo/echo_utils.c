/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:06:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/22 16:15:24 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SingleQuote é 0 e DoubleQuote é 1*/

#include "../../../inc/minishell.h"

int write_backslash(int backslash_nb, int i)
{
    int k;
	
    // If only one backslash is needed, return the incremented index
    if (backslash_nb == 1)
        return (i + 1);
    // If multiple backslash are needed
    k = backslash_nb;
    if (backslash_nb % 2 == 0) // If the number of escapes is even
        while (k-- != backslash_nb / 2) // Write backslashes until k reaches half of backslash_nb
            write(1, "\\", 1); // Write a single backslash to the standard output
    else // If the number of escapes is odd
    {
        k = backslash_nb;
        while (k-- != (backslash_nb / 2) + 1) // Write backslashes until k reaches half of backslash_nb + 1
            write(1, "\\", 1); // Write a single backslash to the standard output
    }
    // Return the index incremented by the number of backslashes
    return (i + backslash_nb);
}

int	has_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

bool	is_special_filled(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39 || str[i] == ' ')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

bool has_content(char **array)
{
    int i = 0;

    while (array[i] != NULL)
    {
        // Check if the current element is not an empty string
        if (array[i][0] != '\0')
            return (TRUE);
        i++;
    }
    return (FALSE);
}

/*j is the number is backslashes*/
void	echo_print(char *str, int i, int j, int quote) 
{
	int	z;

	z = has_quotes(str);
	while (str[i] != '\0')
	{
		//printf("%d\n", i);
		if (str[i] == 34)
			quote = 1;
		if ((str[i] == ' ' && str[i + 1] == ' ' && z == 0) || (str[i] == '\\'))
			while (str[i] == ' ')
				i++;
		j = i;
		if (str[i] == '\\')
		{
			while (str[j] == '\\')
				j++;
			//printf("Number os backslashes is: %d\n", j - i);
			i = write_backslash(j - i, i);
		}
		if (str[i] != 34 && str[i] != 39)
			write(1, &str[i], 1);
		else if (str[i] == 39)
			if (quote == 1)
				write(1, &str[i], 1);
		i++;
	}
}
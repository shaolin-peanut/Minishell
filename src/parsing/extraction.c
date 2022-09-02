/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/09/02 17:43:09 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Below you can see the very redundant explanations I make to myself to be sure I understand. Will clean those up when 100% done with them - Sam

// Save the pointer to a temporary placeholder, incremented to skip the $
// Allocate new space for the string value, so that it stays consistent with the str[i] space malloced by ft_substr in ft_split.
// Send the name of the variable (w/o the $) to getenv, output goes to value
// free(str[i]) which is now to be discarded (except if value is NULL)
// return value, which is gonna take the place of the now freed (str[i])
// No error-checking, just substituing var name with NULL, when var doesn't exist. That's bash does, it doesn't care, just doesn't print anything but executes anything that comes after it.
char	*var_substitution(char **str, int i)
{
	char	*value;
	char	*tmp;

	tmp = str[i];
	tmp++;
	value = (char *) malloc(sizeof(char) * ((int) ft_strlen(str[i]) - 1));
	value = getenv(tmp);
	free(str[i]);
	return (value);
}

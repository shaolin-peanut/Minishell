/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:44 by sbars             #+#    #+#             */
/*   Updated: 2022/10/10 14:26:46 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int quote_len(t_meta *pkg, int *iterator)
{
    char type;
    int len;
    
    type = pkg->str[*iterator];
    *iterator += 1;
    len = 0;
while (pkg->str[*iterator] != '\0')
    {
        if (pkg->str[*iterator] == type)
        {
            *iterator += 1;
            return (len);
        }
        else
        {
            *iterator += 1;
            len++; 
        }
    }
    return (len);
}

int add_quote_content(char *word, int i, t_meta *pkg)
{
    int type;

    type = pkg->str[pkg->i];
    pkg->i++;
    while (pkg->str[pkg->i] != '\0')
    {
        if (pkg->str[pkg->i] == type)
        {
            pkg->i++;
            return (i);
        }
        else
        {
            word[i] = pkg->str[pkg->i];
            i++;
            pkg->i++;
        }
    }
    return (i);
}

int quote_in_word(char *word)
{
    return (ft_strchr(word, 39) || ft_strchr(word, 34));
}

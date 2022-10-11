/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:22 by sbars             #+#    #+#             */
/*   Updated: 2022/10/10 14:26:24 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
    printf("> Cmd found!: %s\n> binary path: %s\n", cmd_name, full_path);
    if (full_path)
    {
        free(full_path);
        full_path = NULL;
    }
    (void) pkg;
    return (0);
}

int create_builtin_token(char *cmd_name, t_meta *pkg)
{
    printf("> Builtin found!: %s\n>", cmd_name);
    (void) pkg;
    return (0);
}

int create_alien_word_token(char *word, t_meta *pkg)
{
    (void) word;
    (void) pkg;
    return (0);
}

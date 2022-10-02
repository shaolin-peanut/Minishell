#include "../../include/minishell.h"

int create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
    printf("> Cmd found!: %s\n> binary path: %s\n", cmd_name, full_path);
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
#include "../../include/minishell.h"

void    free_all(t_meta *pkg)
{
    if (pkg->paths != NULL)
        free(pkg->paths);
    //if (pkg->prompt)
    //    free(pkg->prompt);
    if (pkg->str)
    {
	    //pkg->str = NULL;
        free(pkg->str);
    }
    if (pkg)
        free(pkg);
}
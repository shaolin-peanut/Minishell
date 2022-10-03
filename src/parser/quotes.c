#include "../../include/minishell.h"


char    *process_quotes(char *word, t_meta *pkg)
{
    char    *before_quote;
    char    *quote_content;
    char    *after_quote;
    char    *temp;
    char    *ret;
    int     i;
    
    i = -1;
    before_quote = NULL;
    quote_content = NULL;
    after_quote = NULL;
    while (word[++i])
    {
        if (is_quote(word[i]))
        {
            before_quote = ft_substr(word, 0, i);
            quote_content = return_quote_content(word, i, pkg);
            ret = ft_strjoin(before_quote, quote_content);
            free(before_quote);
            free(quote_content);
            i += ft_strlen(quote_content);
            if (word[i] != '\0')
                after_quote = ft_substr(word, i, ft_strlen(word) - i);
        }
        i++;
    }
}

char    *return_quote_content(char *word, int i, t_meta *pkg)
{
    char    *ret;
    char    *old;
    char    *new;
    int     temp_i;
    int     type;

    ret = ft_strdup("");
    new = NULL;
    type = word[i];
    temp_i = i;
    while (word[temp_i] != '\0');
    {
        if (type == 34 && is_dollar(word[temp_i]))
            printf("TODO:substitute variable in quote\n");
        if (word[temp_i] == type && is_last_quote(word, i))
        else if (word[temp_i] && !is_last_quote(word, i))
        {
            new = return_quote
        }
        temp_i++;
    }
}




int is_quote_closed(int type, t_meta *pkg)
{
    int temp_i;

    temp_i = pkg->i;
    while (pkg->str[temp_i] != '\0')
    {
        if (type == pkg->str[temp_i])
            return (1);
        temp_i++;
    }
    return (0);
}

int how_many_closed_quotes(t_meta *pkg)
{
    char    *str;
    int     i;
    int     scount;
    int     dcount;

    str = pkg->str;
    i = pkg->i;
    scount = 0;
    dcount = 0;
    if (is_quote(str[i]))
    {
        while (str[++i])
        {
            if (str[i] == 39)
                scount++;
            else if (str[i] == 34)
                dcount++;
        }
    }
    if ((dquote % 10 == 0) && (squote % 10 == 0))
        return (QUOTES_CLOSED);
    else if ((dquote % 10 == 0) || (squote % 10 == 0))
        return (CLOSED_AND_UNCLOSED_QUOTES);
    else
        return (UNCLOSED_QUOTES);
}

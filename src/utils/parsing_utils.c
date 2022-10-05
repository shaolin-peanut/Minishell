int last_strchr_index(char *str, char c)
{
    int len;

    len = ft_strlen(str);
    while (len-- != 0)
    {
        if (str[len] == c)
            return (len);
    }
    return (0);
}
int	closed_quotes_len(char *str, int i)
{
	int	counter;
	char type;

	counter = 0;
	if (str[i] == 39)
		type = 39;
	else if (str[i] == 34)
		type = 34;
	else
		return (-1);
	while (str[i] != type)
		counter++;
	return (i + counter);
}

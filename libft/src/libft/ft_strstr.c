/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:30:18 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/13 19:30:20 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*p_str;
	char	*p_to_find;

	start = str;
	while (*start != '\0')
	{
		p_to_find = to_find;
		p_str = start;
		while (*p_to_find != '\0')
		{
			if (*p_to_find != *p_str)
				break ;
			++p_to_find;
			++p_str;
		}
		if (*p_to_find == '\0')
			return (start);
		++start;
	}
	return (0);
}
//int main ()
//{
//	char s0[] = "cette chaine contient certainement au moins un peu de texte qui
//pourrait se retrouver facilement car elle est tres longue";
//	char s1[] = "elle";
//
//	char *res = ft_strstr(s0,s1);
//	if (res)
//		printf("le texte a partir de la chaine: %s\nest: %s\n", s1, res);
//	else
//		printf("le texte ne contenait pas la chaine\n");
//	return 0;
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:39:41 by lanlan            #+#    #+#             */
/*   Updated: 2022/11/29 14:54:13 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
int			ft_atoi2(const char *nptr, long *nbr);
char		*ft_itoa(int n);
int			ft_putchar_fd(char c, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isdigit(int c);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
int			ft_strchr_i(const char *s, int c);
int			ft_strchars_i(const char *s, char *set);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_nbrlen(long n, int base);
int			ft_countchar(char *s, char c);
int			ft_isspace(char c);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstclear(t_list **lst, void (*del)(void*));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_free_matrix(char ***m);
char		**ft_dup_matrix(char **m);
int			ft_putmatrix_fd(char **m, int nl, int fd);
int			ft_matrixlen(char **m);
char		**ft_extend_matrix(char **in, char *newstr);
t_list		*ft_matrixtolst(char **matrix);
char		**ft_lsttomatrix(t_list *lst);
char		**ft_matrix_replace_in(char ***big, char **small, int n);
void		ft_matrix_del_elem(char **m, char *key);
int			ft_matrix_search(char **m, char *key);
void 		ft_matrix_replace_elem(char **m, int i, char *elem);
int			ft_putmatrix_fd_export(char **m, int nl, int fd);

#endif

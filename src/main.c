/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:16:19 by sbars             #+#    #+#             */
/*   Updated: 2022/11/15 17:32:14 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_last_data	*g_data;

int	main(int argc, char **argv, char **envp)
{
	t_meta		*pkg;

	(void) argc;
	(void) argv;
	pkg = init_meta(envp);
	g_data = init_data();
	prompt(pkg);
	free_all(pkg);
	return (0);
}
/*
void tests(t_meta *pkg)
{
	char	*key;
	char 	*export_string = "arg=yolo yola salut";
	char 	*export_string2 = "arg2=une autre chaine d'arguments quoi";

	printf("##########################################\n");
	ft_putmatrix_fd(pkg->envp, 1, STDOUT_FILENO);

	key = get_export_variable_name(export_string);
	change_or_create_var(pkg, key, export_string);

	printf("##########################################\n");
	ft_putmatrix_fd(pkg->envp, 1, STDOUT_FILENO);

	ft_matrix_del_elem(pkg->envp, key);

	printf("##########################################\n");
	ft_putmatrix_fd(pkg->envp, 1, STDOUT_FILENO);
	free(key);

	key = get_export_variable_name(export_string2);
	change_or_create_var(pkg, key, export_string2);
	ft_matrix_del_elem(pkg->envp, key);
	printf("##########################################\n");
	ft_putmatrix_fd(pkg->envp, 1, STDOUT_FILENO);
	free(key);

}

int	main(int argc, char **argv, char **envp)
{
	t_meta		*pkg;

	(void) argc;
	(void) argv;
	pkg = init_meta(envp);
	g_pkg = pkg;

	tests(pkg);

	free_all(pkg);
	return (0);
}
 */
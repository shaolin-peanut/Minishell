/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:19:40 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:21:25 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**paths_finder
{
	int	i;
	char	**tmp;
	char	**paths;

	i = -1;
// This actually is the paths_finder command, something else that should be done before... Or maybe only done when at least one command is found. If pkg->paths is null, run paths_finder.
	while (pkg->envp[++i])
	{
		if (ft_strncmp(pkg->envp[i], "PATH=", 5))
		{
			tmp = ft_split(pkg->envp[i], '=');
			paths = ft_split(tmp, ':');
			free(tmp);
			return (paths);
		}
	}
	return (0);
}

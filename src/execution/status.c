/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	get_last_status(int bin_status, int ret_built_in)
{
	if (ret_built_in == -1)
		return (bin_status);
	else if (bin_status == -1)
		return (ret_built_in);
	return (0);
}

int	convert_status_process_value(int status)
{
	printf("converting status process value:%d", status);
	if (WIFSIGNALED(status))
	{
		printf(" WIFSIGNALED");
		status = 128 + status;
	}

	else if (WIFEXITED(status))
	{
		printf(" WIFexited");
		status = WEXITSTATUS(status);
	}
	printf(" to %d\n", status);
	return (status);
}

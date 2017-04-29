/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:02:36 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 09:32:15 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

char		**g_ft_environ;
char		*g_ft_program_name;

void		ft_initenv(void)
{
	char	**tmp;
	int		i;

	tmp = g_environ;
	i = 0;
	while (tmp[i])
		i++;
	if (!(g_ft_environ = ft_memalloc(sizeof(char *) * (i + 1))))
		ft_exit(1, "Memory allocation failed");
	g_ft_environ[i] = NULL;
	i = 0;
	while (tmp[i])
	{
		if (!(g_ft_environ[i] = ft_strdup(tmp[i])))
			ft_exit(1, "Memory allocation failed");
		i++;
	}
}

void		ft_initname(char *name)
{
	char	*f;

	f = ft_strrchr(name, '/');
	g_ft_program_name = (f ? f + 1 : name);
}

void		ft_init(char *name)
{
	ft_initname(name);
	ft_initenv();
}

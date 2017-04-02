/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:26:57 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 17:06:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static t_alcu	*parsing_param2(t_alcu *alcu, int fd, int *ret)
{
	char	*buf;
	int		i;
	int		j;
	int		tmp;

	if (!(buf = ft_strnew(10000))
		|| (i = (int)read(fd, buf, 10000)) < 1 || i == 10000
		|| (buf[i] = '\0') || buf[0] == '\n')
	{
		*ret = -1;
		return (alcu);
	}
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			++i;
		if (!buf[i])
			break ;
		tmp = ft_atoi(&buf[i]);
		j = 0;
		while (ft_isdigit((int)buf[i]))
		{
			++i;
			++j;
		}
		if (tmp < 1 || tmp > 10000 || j > 5 || buf[i] != '\n'
			|| !(alcu = init_add_t_alcu(alcu)))
		{
			ft_strdel(&buf);
			*ret = -1;
			return (alcu);
		}
		alcu->board = tmp;
	}
	ft_strdel(&buf);
	return (alcu);
}

t_alcu			*parsing_param(t_alcu *alcu, char **argv, int *ret)
{
	int		fd;

	ft_putendl("Board is initialized from the parameter file\n");
	if ((fd = open(argv[1], O_RDONLY)) < 0 || read(fd, 0, 0)
		|| !(alcu = parsing_param2(alcu, fd, ret)) || *ret == -1
		|| close(fd) == -1)
	{
		*ret = -1;
		return (alcu);
	}
	return (alcu);
}

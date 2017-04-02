/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:56:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 20:45:29 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static t_alcu	*parsing_stdi2(t_alcu *alcu, char *buf, int *lock, int *ret)
{
	int		i;
	int		tmp;

	i = 0;
	if ((buf[0] == '\n' && !*lock) || ft_strlen(buf) > 6
		|| (tmp = ft_atoi(buf)) < 1 || tmp > 10000
		|| !(alcu = init_add_t_alcu(alcu)))
	{
		ft_strdel(&buf);
		*ret = -1;
		return (alcu);
	}
	while (ft_isdigit((int)buf[i]))
		++i;
	if (buf[i] != '\n')
	{
		ft_strdel(&buf);
		*ret = -1;
		return (alcu);
	}
	alcu->board = tmp;
	ft_strclr(buf);
	return (alcu);
}

t_alcu			*parsing_stdi(t_alcu *alcu, int *ret)
{
	char		*buf;
	int			lock;

	lock = 0;
	if (!(buf = ft_strnew(10000))
		&& (*ret = -1))
		return (alcu);
	ft_putendl("\033[4mUsage\033[24m :");
	ft_putendl("Enter the number of sticks and a newline for each match,");
	ft_putendl("Then init the game with a newline.\n");
	ft_putendl("Number of sticks minimum : 1");
	ft_putendl("Number of sticks maximum : 10000\n");
	while (1)
	{
		read(1, buf, 10000);
		if (buf[0] == '\n' && lock)
			break ;
		else if (!(alcu = parsing_stdi2(alcu, buf, &lock, ret))
			|| *ret == -1)
			return (alcu);
		lock = 1;
	}
	ft_strdel(&buf);
	return (alcu);
}

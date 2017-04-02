/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:26:57 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 21:55:30 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void				del_t_alcu(t_alcu *alcu, t_alcu2 *alcu2)
{
	t_alcu		*tmp;

	while (alcu && alcu->previous)
	{
		alcu = alcu->previous;
	}
	while (alcu)
	{
		tmp = alcu->next;
		ft_memdel((void**)&alcu);
		alcu = tmp;
	}
	ft_memdel((void**)&alcu2);
}

t_alcu				*reset_position_t_alcu(t_alcu *alcu)
{
	while (alcu && alcu->previous)
		alcu = alcu->previous;
	return (alcu);
}

static t_alcu2		*init_t_alcu2(t_alcu2 *alcu2)
{
	if (!(alcu2 = ft_memalloc(sizeof(t_alcu2))))
		return (NULL);
	alcu2->scoreai = 0;
	alcu2->scorehuman = 0;
	alcu2->taken = 0;
	return (alcu2);
}

t_alcu				*init_add_t_alcu(t_alcu *alcu)
{
	t_alcu		*tmp;

	tmp = NULL;
	if (alcu)
	{
		tmp = alcu;
		if (!(alcu->next = ft_memalloc(sizeof(t_alcu))))
			return (NULL);
		alcu = alcu->next;
	}
	else if (!(alcu = ft_memalloc(sizeof(t_alcu))))
		return (NULL);
	alcu->board = 0;
	alcu->next = NULL;
	alcu->previous = NULL;
	if (tmp)
		alcu->previous = tmp;
	return (alcu);
}

int					main(int argc, char **argv)
{
	t_alcu		*alcu;
	t_alcu2		*alcu2;
	int			ret;

	alcu = NULL;
	alcu2 = NULL;
	ret = 0;
	if (argc != 1 && argc != 2)
	{
		ft_putendl("Usage : ./alum1 [Optional file well formatted]");
		return (-1);
	}
	if (!(alcu2 = init_t_alcu2(alcu2)))
		return (-1);
	display_start();
	if ((argc == 1 && (!(alcu = parsing_stdi(alcu, &ret)) || ret == -1))
		|| (argc == 2 && (!(alcu = parsing_param(alcu, argv, &ret))
		|| ret == -1))
		|| game(alcu, alcu2))
	{
		display_error(alcu, alcu2);
		return (-1);
	}
	del_t_alcu(alcu, alcu2);
	return (0);
}

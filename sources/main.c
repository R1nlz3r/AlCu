/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:26:57 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/01 16:13:24 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void				del_t_alcu(t_alcu *alcu)
{
	t_alcu		*tmp;

	ft_putchar('@');
	while (alcu && alcu->previous)
	{
		ft_putchar('-');
		alcu = alcu->previous;
	}
	while (alcu)
	{
		ft_putchar('*');
		tmp = alcu->next;
		ft_memdel((void**)&alcu);
		alcu = tmp;
	}
	ft_putchar('@');
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
	int			ret;

	(void)argv; //à retirer
	alcu = NULL;
	ret = 0;
	if (argc != 1 && argc != 2)
	{
		ft_putendl("Usage : ./alum1 [Optional file well formatted]");
		return (-1);
	}
	display_start();
	if ((argc == 1 && (!(alcu = parsing_stdi(alcu, &ret)) || ret == -1)))
//		|| (argc == 2 && parsing_param(alcu, argv) == -1))
	{
		display_error(alcu);
		return (-1);
	}
	//jeu
	del_t_alcu(alcu);
	return (0);
}

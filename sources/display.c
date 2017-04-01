/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:12:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/01 20:46:15 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void				display_error(t_alcu *alcu, t_alcu2 *alcu2)
{
	ft_putstr_fd("ERROR\n", 2);
	del_t_alcu(alcu, alcu2);
}

void				display_board(t_alcu *alcu)
{
	int		i;
	int		j;

	i = 1;
	alcu = reset_position_t_alcu(alcu);
	ft_putendl("Board :");
	ft_putendl("/*");
	while (alcu)
	{
		ft_putstr("** ");
		ft_putnbr(i);
		j = alcu->board;
		while (j--)
			ft_putstr(" |");
		ft_putchar('\n');
		++i;
		if (alcu->next)
			alcu = alcu->next;
		else
			break ;
	}
	ft_putendl("*/");
}

void				display_start(void)
{
	ft_putstr("\033c");
	ft_putendl("\n*************************************");
	ft_putendl("**            42 - AlCu            **");
	ft_putendl("*************************************\n");
}

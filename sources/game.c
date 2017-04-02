/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:48:03 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 05:08:02 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int		ai_plays(t_alcu *alcu)
{
	int		mod;

	if (alcu->board == 1)
		return (1);
	else if (alcu->board < 5)
		return (alcu->board - 1);
	mod = alcu->board % 5;
	if (mod > 0 && mod <= 3)
		return (mod);
	return (1);

}

int				game(t_alcu *alcu, t_alcu2 *alcu2)
{
	char	*buf;
	int		lock;

	if (!(buf = ft_strnew(10000)))
		return (-1);
	lock = 0;
	while (1)
	{
		alcu = reset_position_t_alcu(alcu);
		if (alcu && !alcu->board)
			break ;
		while (alcu->board > 0)
		{
			if (lock)
			{
				if (lock == 1)
				{
					ft_putstr("\033c");
					display_ai_plays(alcu2);
				}
			}
			lock = 0;
			display_score(alcu2);
			alcu = display_board(alcu);
			display_human_plays();
			while (1)
			{
				read(1, buf, 10000);
				if (buf[1] == '\n')
				{
					alcu2->taken = ft_atoi(buf);
					if (alcu2->taken >= 1 && alcu2->taken <= 3
						&& alcu->board - alcu2->taken >= 0)
						break ;
				}
			}
			alcu->board -= alcu2->taken;
			if (!alcu->board)
			{
				ft_putstr("\033c");
				display_ai_won(alcu2);
				lock = 2;
				break ;
			}
			alcu2->taken = ai_plays(alcu);
			alcu->board -= alcu2->taken;
			if (!alcu->board)
			{
				ft_putstr("\033c");
				display_human_won(alcu2);
				lock = 2;
				break ;
			}
			lock = 1;
		}
	}
	display_final_score(alcu2);
	ft_strdel(&buf);
	return (0);
}

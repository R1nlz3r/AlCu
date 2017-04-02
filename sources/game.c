/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:48:03 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 20:20:08 by mapandel         ###   ########.fr       */
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

static int		human_plays(t_alcu *alcu, t_alcu2 *alcu2, char *buf)
{
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
	return (alcu2->taken);
}

static int		plays(t_alcu *alcu, t_alcu2 *alcu2, char *buf, int *lock)
{
	alcu2->taken = human_plays(alcu, alcu2, buf);
	alcu->board -= alcu2->taken;
	if (!alcu->board)
	{
		ft_putstr("\033c");
		display_ai_won(alcu2);
		*lock = 2;
		return (1);
	}
	alcu2->taken = ai_plays(alcu);
	alcu->board -= alcu2->taken;
	if (!alcu->board)
	{
		ft_putstr("\033c");
		display_human_won(alcu2);
		*lock = 2;
		return (1);
	}
	*lock = 1;
	return (0);
}

static void		game2(t_alcu *alcu, t_alcu2 *alcu2, char *buf, int *lock)
{
	while (alcu->board > 0)
	{
		if (*lock)
		{
			if (*lock == 1)
			{
				ft_putstr("\033c");
				display_ai_plays(alcu2);
			}
		}
		*lock = 0;
		display_score(alcu2);
		alcu = display_board(alcu);
		if (plays(alcu, alcu2, buf, lock))
			break ;
	}
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
		game2(alcu, alcu2, buf, &lock);
	}
	display_final_score(alcu2);
	ft_strdel(&buf);
	return (0);
}

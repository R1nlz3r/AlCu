/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:12:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 19:41:46 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void				display_error(t_alcu *alcu, t_alcu2 *alcu2)
{
	ft_putstr_fd("ERROR\n", 2);
	del_t_alcu(alcu, alcu2);
}

void				display_human_plays(void)
{
	ft_putendl("Put a valid number between 1 and 3 :\n");
}

void				display_ai_plays(t_alcu2 *alcu2)
{
	ft_putstr("\033[31mAI\033[0m took ");
	ft_putnbr(alcu2->taken);
	ft_putstr(" stick");
	if (alcu2->taken != 1)
		ft_putstr("s");
	ft_putendl("\n");
}

t_alcu				*display_board(t_alcu *alcu)
{
	int		i;
	int		j;

	i = 1;
	alcu = reset_position_t_alcu(alcu);
	ft_putendl("\033[4mBoard\033[24m :");
	ft_putendl("/*");
	while (alcu)
	{
		ft_putstr("** \033[7m");
		ft_putnbr(i);
		ft_putstr("\033[27m");
		j = alcu->board;
		while (j--)
			ft_putstr(" |");
		ft_putchar('\n');
		++i;
		if (alcu->next && alcu->next->board)
			alcu = alcu->next;
		else
			break ;
	}
	ft_putendl("*/\n");
	return (alcu);
}

void				display_start(void)
{
	ft_putstr("\033c");
	ft_putendl("\033[90m\033[1m*************************************");
	ft_putendl("**\033[0m            42 - AlCu            \033[90m\033[1m**");
	ft_putendl("*************************************\033[0m\n");
}

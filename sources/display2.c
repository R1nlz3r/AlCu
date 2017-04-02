/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 21:34:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/02 20:31:52 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void			display_human_won(t_alcu2 *alcu2)
{
	ft_putendl("\033[33mYou\033[0m won this match !\n");
	++alcu2->scorehuman;
}

void			display_ai_won(t_alcu2 *alcu2)
{
	ft_putendl("\033[31mAI\033[0m won this match.. *rip*\n");
	++alcu2->scoreai;
}

void			display_score(t_alcu2 *alcu2)
{
	ft_putstr("\033[4mScore\033[24m : \033[33mYou\033[0m ");
	ft_putnbr(alcu2->scorehuman);
	ft_putstr(" - \033[31mAI\033[0m ");
	ft_putnbr(alcu2->scoreai);
	ft_putendl("\n");
}

void			display_final_score(t_alcu2 *alcu2)
{
	ft_putstr("\033[4mFinal Score\033[24m : \033[33mYou\033[0m ");
	ft_putnbr(alcu2->scorehuman);
	ft_putstr(" - \033[31mAI\033[0m ");
	ft_putnbr(alcu2->scoreai);
	ft_putchar('\n');
	if (alcu2->scorehuman > alcu2->scoreai)
		ft_putendl("Woah ! \033[33mYou\033[0m rock");
	else if (alcu2->scorehuman < alcu2->scoreai)
		ft_putendl("Well.. \033[33mYou\033[0m suck");
	else
		ft_putendl("Draw");
}

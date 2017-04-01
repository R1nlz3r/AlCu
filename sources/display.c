/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:12:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/01 15:29:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void				display_error(t_alcu *alcu)
{
	ft_putstr_fd("ERROR\n", 2);
	del_t_alcu(alcu);
}

void				display_start(void)
{
	ft_putstr("\033c");
	ft_putendl("\n*************************************");
	ft_putendl("**            42 - AlCu            **");
	ft_putendl("*************************************\n");
}

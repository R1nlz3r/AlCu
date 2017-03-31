/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:26:57 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/31 20:37:42 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void		del_t_alcu(t_alcu *alcu)
{
	//free tout ce qui à été malloc
}

static t_alcu		init_t_alcu(t_alcu *alcu)
{
	//init la structure
	return (alcu);
}

int					main(int argc, char **argv)
{
	t_alcu		*alcu;

	alcu = NULL;
	if (!(alcu = init_t_alcu(alcu)))
		return (-1);
	if (argc != 2)
		//Parser le fichier passé en paramètre
	else
		//Parser l'entrée standard
	return (0);
}

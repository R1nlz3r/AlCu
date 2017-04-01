/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:26:57 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/01 20:00:13 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "../libft/libft.h"
#include <fcntl.h>

typedef struct			s_alcu
{
	struct s_alcu		*previous;
	struct s_alcu		*next;
	int					board;
	char				pad_0[4];
}						t_alcu;

typedef struct			s_alcu2
{
	int					scoreai;
	int					scorehuman;
}						t_alcu2;

t_alcu					*init_add_t_alcu(t_alcu *alcu);
t_alcu					*reset_position_t_alcu(t_alcu *alcu);
void					del_t_alcu(t_alcu *alcu, t_alcu2 *alcu2);
void					display_error(t_alcu *alcu, t_alcu2 *alcu2);
void					display_start(void);
void					display_board(t_alcu *alcu);
t_alcu					*parsing_stdi(t_alcu *alcu, int *ret);
t_alcu					*parsing_param(t_alcu *alcu, char **argv, int *ret);
void					game(t_alcu *alcu, t_alcu2 *alcu2);

#endif

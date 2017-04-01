/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:26:57 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/01 15:54:54 by mapandel         ###   ########.fr       */
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

t_alcu					*init_add_t_alcu(t_alcu *alcu);
void					del_t_alcu(t_alcu *alcu);
void					display_error(t_alcu *alcu);
void					display_start(void);
t_alcu					*parsing_stdi(t_alcu *alcu, int *ret);
//int						parsing_param(t_alcu *alcu, char **argv);

#endif

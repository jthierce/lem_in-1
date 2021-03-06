/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_link.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:57:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/04/24 15:27:04 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_LINK_H
# define LI_LINK_H

# include "li_board.h"
# include "li_room.h"

/*
** t_li_link
**
** Represent a link between two rooms (here called 'a' and 'b').
*/

typedef struct s_li_link	t_li_link;
typedef t_li_link			t_link;
struct						s_li_link
{
	int			i_room_a;
	int			i_room_b;
	t_li_room	*p_room_a;
	t_li_room	*p_room_b;
};

void						li_link_dump(t_li_link *link);

#endif

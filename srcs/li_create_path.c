/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:00:00 by jthierce          #+#    #+#             */
/*   Updated: 2020/04/24 17:02:12 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static void	li_loop_return(t_board board, int **matrice, int i)
{
	int j;

	if (board.rooms[i].status == 5 || board.rooms[i].status == 6)
	{
		j = -1;
		while (board.rooms[i].status == 5 &&
		++j < board.rooms[i].count_link)
		{
			if (matrice[board.rooms[i].index][board.rooms
			[board.rooms[i].link[j]].index] == 6)
				board.rooms[i].prev = &(board.rooms[board.rooms[i].link[j]]);
		}
		board.rooms[i].status = 2;
	}
}

static void	li_return_old_version(t_board board, int **matrice)
{
	int i;
	int j;

	i = -1;
	while (++i < board.rooms_count)
		li_loop_return(board, matrice, i);
	i = -1;
	while (++i < board.rooms_count)
	{
		j = -1;
		while (++j < board.rooms_count)
		{
			if (matrice[i][j] == 6)
				matrice[i][j] = 4;
			if (matrice[i][j] == 7)
				matrice[i][j] = 5;
		}
	}
}

static void	li_loop_valide_path(t_board board, int **matrice, int i)
{
	t_room	*rooms;

	if (board.rooms[board.rooms[1].link[i]].status == 2 ||
	board.rooms[board.rooms[1].link[i]].status == 5)
	{
		rooms = &(board.rooms[board.rooms[1].link[i]]);
		while (rooms->prev != NULL)
		{
			if (rooms->index != 1)
				rooms->status = 2;
			else
				rooms->status = 3;
			matrice[rooms->index][rooms->prev->index] = 4;
			matrice[rooms->prev->index][rooms->index] = 5;
			rooms = rooms->prev;
		}
	}
}

static void	li_valide_path_matrice(t_board board, int **matrice)
{
	t_room	*rooms;
	int		i;

	i = -1;
	while (++i < board.rooms[1].count_link)
		li_loop_valide_path(board, matrice, i);
	rooms = &(board.rooms[1]);
	while (rooms->prev != NULL)
	{
		if (rooms->index != 1)
			rooms->status = 2;
		else
			rooms->status = 3;
		matrice[rooms->index][rooms->prev->index] = 4;
		matrice[rooms->prev->index][rooms->index] = 5;
		rooms = rooms->prev;
	}
}

/*
** Call li_calc_step and depending of result return create new path or
** take old version
**
** Return Value:
**
** -1 = Malloc fail
** -2 = path no valid stop bfs
** 0 = all is fine
*/

int			li_create_path(t_board board, int **matrice)
{
	int result;

	if ((result = li_calc_step(board, 0)) == -1)
		return (-1);
	if (result == -2)
	{
		li_return_old_version(board, matrice);
		return (-2);
	}
	li_valide_path_matrice(board, matrice);
	return (0);
}

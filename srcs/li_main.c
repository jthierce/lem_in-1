/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:14 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:17:35 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

/*
** Main, resolve lem_in.
** Return a negative int on error.
*/

int		main_resolve(t_li_board *board)
{
	int		rst;

	if ((rst = li_resolve(*board)) < 0)
		return (-1);
	board->resolve_result = rst;
	return (0);
}

/*
** Main, parse input then resolve.
** Return a negative int on error.
*/

int		main_parse_resolve(t_li_board *board)
{
	int		rst_parse;
	int		rst;

	if ((rst_parse = li_parse_input(board)) < 0)
		return (rst_parse);
	if ((rst = main_resolve(board)) < 0)
		return (rst);
	return (rst_parse);
}

/*
** Main, create the empty base board.
*/

int		main(int argc, char **argv)
{
	int			rst;
	t_li_board	*board;

	(void)argc;
	(void)argv;
	if (!(board = li_board_create()))
		return (ft_abs(li_perror(-1, NULL)));
	if ((rst = main_parse_resolve(board)) < 0)
	{
		li_board_destroy(&board);
		return (ft_abs(li_perror(rst, NULL)));
	}
	if (li_print_result(board) < 0)
		ft_putstr_fd("ERROR WHILE PRINTING RESULT", 2);
	li_board_destroy(&board);
	return (rst);
}

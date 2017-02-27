/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:29 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/27 14:37:31 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		make_check_o(t_game *g, int ty, int tx, int i)
{
	int res;

	res = 0;
	if ((g->m_symb[g->t.py[i]][g->t.px[i]] == 'O'
		|| g->m_symb[g->t.py[i]][g->t.px[i]] == 'o'
		|| g->m_symb[g->t.py[i]][g->t.px[i]] == '.'
		|| (((g->m_symb[g->t.py[i]][g->t.px[i]] == 'X'
		|| g->m_symb[g->t.py[i]][g->t.px[i]] == 'x')
		&& g->p_symb[g->t.py[i] - ty][g->t.px[i] - tx] == '.')))
		&& g->flag <= 1 && g->t.py[i] + (g->piece.py[i] - i) <= g->map.y
		&& g->t.px[i] + (g->piece.px[i] - i) <= g->map.x
		&& g->t.py[i] <= g->map.y - (g->piece.y - i)
		&& g->t.px[i] <= g->map.x - (g->piece.x - i))
	{
		res++;
		if ((g->m_symb[g->t.py[i]][g->t.px[i]] == 'O'
			|| g->m_symb[g->t.py[i]][g->t.px[i]] == 'o')
			&& g->p_symb[g->t.py[i] - ty][g->t.px[i] - tx] == '*')
			res++;
		return (res);
	}
	else
		return (-1);
}

int		check_o(t_game *g, int tx, int ty)
{
	int	x;
	int	y;
	int	i;
	int res;

	y = 0;
	i = 0;
	g->flag = 0;
	re_coord(g, tx, ty);
	while (y < g->piece.y)
	{
		x = 0;
		while (x < g->piece.x)
		{
			res = make_check_o(g, ty, tx, i);
			(res == 1 || res == 2) ? i++ : i;
			(res == 2) ? g->flag++ : g->flag;
			if (res == -1)
				return (0);
			x++;
		}
		y++;
	}
	return ((g->flag == 1) ? 1 : 0);
}

t_game	*all_o(t_game *game, int x, int y, int *i)
{
	int		tx;
	int		ty;

	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while (ty <= y)
	{
		while (tx <= x)
		{
			if (tx >= 0 && ty >= 0 && check_o(game, tx, ty) == 1)
			{
				game->all_ok.px[(*i)] = tx;
				game->all_ok.py[(*i)] = ty;
				(*i)++;
			}
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	game->all_ok.i = (*i);
	return (game);
}

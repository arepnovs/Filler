/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:36 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/27 14:37:38 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	map_copy(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	game->map_cmp = (char**)malloc(sizeof(char*) * (game->map.y * game->map.x));
	while (y < game->map.y)
	{
		game->map_cmp[y] = (char*)malloc(sizeof(char) * game->map.x);
		x = 0;
		while (x < game->map.x)
		{
			game->map_cmp[y][x] = game->m_symb[y][x];
			x++;
		}
		y++;
	}
}

int		make_check_x(t_game *g, int ty, int tx, int i)
{
	int res;

	res = 0;
	if ((g->m_symb[g->t.py[i]][g->t.px[i]] == 'X'
		|| g->m_symb[g->t.py[i]][g->t.px[i]] == '.'
		|| (((g->m_symb[g->t.py[i]][g->t.px[i]] == 'O')
		&& g->p_symb[g->t.py[i] - ty][g->t.px[i] - tx] == '.')))
		&& g->flag <= 1 && g->t.py[i] + (g->piece.py[i] - i) <= g->map.y
		&& g->t.px[i] + (g->piece.px[i] - i) <= g->map.x
		&& g->t.py[i] <= g->map.y - (g->piece.y - i)
		&& g->t.px[i] <= g->map.x - (g->piece.x - i))
	{
		res++;
		if ((g->m_symb[g->t.py[i]][g->t.px[i]] == 'X'
			|| g->m_symb[g->t.py[i]][g->t.px[i]] == 'x')
			&& g->p_symb[g->t.py[i] - ty][g->t.px[i] - tx] == '*')
			res++;
		return (res);
	}
	else
		return (-1);
}

int		check_x(t_game *g, int tx, int ty)
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
			res = make_check_x(g, ty, tx, i);
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

t_game	*all_x(t_game *game, int x, int y, int *i)
{
	int		tx;
	int		ty;

	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while (ty <= y)
	{
		while (tx <= x && ty >= 0)
		{
			if (check_rep(game->all_ok, ty, tx, (*i)) == 1 && (*i) < 1000 && tx >= 0)
			{
				if (tx >= 0 && ty >= 0 && check_x(game, tx, ty) == 1)
				{
					game->all_ok.px[(*i)] = tx;
					game->all_ok.py[(*i)] = ty;
					(*i) = (*i) + 1;
					if (game->piece.y > 30 || game->piece.x > 30)
						break;
				}
			}
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	game->all_ok.i = (*i);
	return (game);
}

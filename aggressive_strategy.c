/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggressive_strategy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:40:37 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/01 17:40:39 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cd	find_move_x(t_game *game, int *i)
{
	int		y;
	int		x;
	t_cd	e_move;

	y = 0;
	e_move.px = (int*)malloc(sizeof(int) * 100);
	e_move.py = (int*)malloc(sizeof(int) * 100);
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->m_symb[y][x] != game->map_cmp[y][x]
				&& game->m_symb[y][x] != 'O' && game->m_symb[y][x] != 'o')
			{
				e_move.px[(*i)] = x;
				e_move.py[(*i)] = y;
				(*i)++;
			}
			x++;
		}
		y++;
	}
	return (e_move);
}

t_cd	find_move_o(t_game *game, int *i)
{
	int		y;
	int		x;
	t_cd	e_move;

	y = 0;
	e_move.px = (int*)malloc(sizeof(int) * 100);
	e_move.py = (int*)malloc(sizeof(int) * 100);
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->m_symb[y][x] != game->map_cmp[y][x]
				&& game->m_symb[y][x] != 'X' && game->m_symb[y][x] != 'x')
			{
				e_move.px[(*i)] = x;
				e_move.py[(*i)] = y;
				break;
				//(*i)++;
			}
			x++;
		}
		y++;
	}
	return (e_move);
}

t_cd	read_move(t_game *gm, int i)
{
	t_cd	e_move;

	e_move.px = (int*)malloc(sizeof(int) * 100);
	e_move.py = (int*)malloc(sizeof(int) * 100);
	if (!gm->map_cmp)
	{
		map_copy(gm);
		e_move.px[0] = -1;
		e_move.py[0] = -1;
	}
	else
	{
		e_move = (gm->sign == 'O') ? find_move_x(gm, &i) : find_move_o(gm, &i);
		e_move.i = i;
		map_copy(gm);
	}
	return (e_move);
}

int		ft_abs(int x)
{
	if (x < 0)
		return(-x);
	else
		return(x);
}

void	millitary_secret(t_game *game, int j, int i)
{
	float	res;
	float	s_res;

	s_res = 1000.0;
	while (j < game->all_ok.i)/*2 realisation of the same strategy*/
	{
		res = (ft_abs(game->all_ok.px[j] - game->e_move.px[i]) + ft_abs(game->all_ok.py[j] - game->e_move.py[i]));
		/*res = ft_sqrt(mult(game->all_ok.px[j], game->e_move.px[i]),
			mult(game->all_ok.py[j], game->e_move.py[i]));  --this strategy quite slow but more accurate*/
		if (res < s_res)
		{
			s_res = res;
			game->all_ok.px[0] = game->all_ok.px[j];
			game->all_ok.py[0] = game->all_ok.py[j];
		}
		j++;
	}
}

t_game	*aggressive(t_game *gm)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	gm->e_move = read_move(gm, i);
	j = 0;
	if (gm->e_move.py[0] >= 0 && gm->e_move.i > 0)
	{
		while (i < gm->e_move.i)
		{
			millitary_secret(gm, j, i);
			j++;
			i++;
		}
	}
	return (gm);
}

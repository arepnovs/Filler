/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:21 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/27 14:37:23 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_game *gm, char piece[gm->piece.y][gm->piece.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	gm->piece.px = (int *)malloc(sizeof(int) * (gm->piece.x * gm->piece.y));
	gm->piece.py = (int *)malloc(sizeof(int) * (gm->piece.x * gm->piece.y));
	while (y < gm->piece.y)
	{
		x = 0;
		while (x < gm->piece.x)
		{
			if (piece[y][x] == '*' || piece[y][x] == '.')
			{
				gm->piece.px[i] = x;
				gm->piece.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	gm->piece.i = i;
	remember_piece(gm, piece);
}

void	remember_piece(t_game *game, char piece[game->piece.y][game->piece.x])
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	game->p_symb = (char **)malloc((game->piece.y + 1) * sizeof(char *));
	while (y < game->piece.y)
	{
		game->p_symb[y] = ft_strnew(0);
		while (x < game->piece.x)
		{
			game->p_symb[y] = ft_charjoin(game->p_symb[y], piece[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	game->p_symb[y] = NULL;
}

void	read_o_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	game->p1.px = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	game->p1.py = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (map[y][x] == 'O' || map[y][x] == 'o')
			{
				game->p1.px[i] = x;
				game->p1.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	game->p1.i = i;
}

void	read_x_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	game->p2.px = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	game->p2.py = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (map[y][x] == 'X' || map[y][x] == 'x')
			{
				game->p2.px[i] = x;
				game->p2.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	game->p2.i = i;
}

void	remember_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	game->m_symb = (char **)malloc((game->map.y + 1) * sizeof(char *));
	while (y < game->map.y)
	{
		game->m_symb[y] = ft_strnew(0);
		while (x < game->map.x)
		{
			game->m_symb[y] = ft_charjoin(game->m_symb[y], map[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	game->m_symb[y] = NULL;
}

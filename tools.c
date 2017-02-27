/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:45 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/27 19:04:14 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cd	set_coord(int x, int y)
{
	t_cd	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void	re_coord(t_game *game, int tx, int ty)
{
	int i;

	i = 0;
	while (i < game->piece.i)
	{
		game->t.px[i] = game->piece.px[i] + tx;
		game->t.py[i] = game->piece.py[i] + ty;
		i++;
	}
}

void	get_size(char *line, t_game *game, char w)
{
	char	*tmp;

	if (w == 'm')
	{
		tmp = ft_strchr(line, ' ');
		game->map.y = ft_atoi(tmp);
		tmp++;
		tmp = ft_strchr(tmp, ' ');
		game->map.x = ft_atoi(tmp);
	}
	else if (w == 'p')
	{
		tmp = ft_strchr(line, ' ');
		game->piece.y = ft_atoi(tmp);
		tmp++;
		tmp = ft_strchr(tmp, ' ');
		game->piece.x = ft_atoi(tmp);
	}
}

float	mult(int x1, int x2)
{
	float res;

	res = (float)x1 - (float)x2;
	res = res * res;
	return (res);
}

float	ft_sqrt(float res1, float res2)
{
	float fres;
	float sq_res;
	float i;

	i = 1;
	sq_res = 0.0;
	fres = (float)res1 + (float)res2;
	while (sq_res <= fres - 10 || sq_res >= fres + 10)
	{
		sq_res = i * i;
		i = i + 0.2;
	}
	return (sq_res);
}

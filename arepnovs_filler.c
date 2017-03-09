/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arepnovs_filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:12 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/01 13:04:45 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_piece(t_game *game, char map[game->map.y][game->map.x])
{
	char	piece[game->piece.y][game->piece.x];
	char	*line;
	t_cd	c;

	c.y = 0;
	c.x = 0;
	while (c.y < game->piece.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			while (c.x < game->piece.x)
			{
				piece[c.y][c.x] = line[c.x];
				c.x++;
			}
			c.x = 0;
			free(line);
		}
		c.y++;
	}
	read_piece(game, piece);
	read_o_map(game, map);
	read_x_map(game, map);
	remember_map(game, map);
	game_start(game);
}

void	get_map(t_game *game)
{
	char	map[game->map.y][game->map.x];
	char	*line;
	t_cd	c;

	c.y = 0;
	c.x = 0;
	while (c.y < game->map.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			while (c.x < game->map.x + 4)
			{
				map[c.y][c.x] = line[c.x + 4];
				c.x++;
			}
			c.x = 0;
			free(line);
		}
		c.y++;
	}
	get_next_line(0, &line);
	get_size(line, game, 'p');
	get_piece(game, map);
}

void	use_strategy(t_game *game)
{
	if (game->piece.y < 30 || game->piece.x < 30)
		game = aggressive(game);
	ft_putnbr_fd(game->all_ok.py[0], 1);
	write(1, " ", 1);
	ft_putnbr_fd(game->all_ok.px[0], 1);
	write(1, "\n", 1);
}

void	game_start(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->all_ok.px = (int *)malloc(sizeof(int) * (50000));
	game->all_ok.py = (int *)malloc(sizeof(int) * (50000));
	game->t.px = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	game->t.py = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	if (game->sign == 'O')
	{
		while (i < game->p1.i)
		{
			game = all_o(game, game->p1.px[i], game->p1.py[i], &j);
			i++;
		}
	}
	else
	{
		while (i < game->p2.i)
		{
			game = all_x(game, game->p2.px[i], game->p2.py[i], &j);
			i++;
		}
	}
}

int		main(void)
{
	char	*line;
	t_game	game;
	int		i;
	int		ret;

	i = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[1] == '$')
		{
			game.sign = ((line[10] == '1') ? 'O' : 'X');
			get_next_line(0, &line);
		}
		if (ft_strstr(line, "Plat"))
		{
			get_size(line, &game, 'm');
			get_next_line(0, &line);
			get_map(&game);
			use_strategy(&game);
		}
		free(line);
	}
	return (0);
}

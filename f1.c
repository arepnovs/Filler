#include "filler.h"

void		get_piece(t_game *game, char map[game->map.y][game->map.x])
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
	ft_recu_solver(game);
}

void		get_map(t_game *game)
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


int			main(void)
{
	char	*line;
	t_game	game;
	int i;
	int j;
	int ret;

	i = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[1] == '$')
		{
			game.sign = ((line[10] == '1') ? 'O' : 'X');
			if (line[10] == '1' || line[10] == '2')
				get_next_line(0, &line);
		}
		if (ft_strstr(line, "Plat"))
		{
			get_size(line, &game, 'm');
			get_next_line(0, &line);
			get_map(&game);
		}
		free(line);
	}
	return (0);
}

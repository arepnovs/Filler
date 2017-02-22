#include "filler.h"

void		read_piece(t_game *game, char piece[game->piece.y][game->piece.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < game->piece.y)
	{
		x = 0;
		while (x < game->piece.x)
		{
			if (piece[y][x] == '*')
			{
				game->p_coord.px[i] = x;
				game->p_coord.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	x = i;
	i = 0;
	while (i < x)
	{
		printf("p_x = %d\n", game->p_coord.px[i]);
		printf("p_y = %d\n", game->p_coord.py[i]);
		i++;
	}
}

void		get_piece(t_game *game, char map[game->map.y][game->map.x])
{
	char	piece[game->piece.y][game->piece.x];
	char	*line;
	t_cd	c;

	c.y = 0;
	c.x = 0;
	printf("\n------------------------\n\n");
	while (c.y < game->piece.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			//printf("c.x = %d\n", c.x);
			while (c.x < game->piece.x)
			{
				//printf("inwhile c.x = %d\n", c.x);
				piece[c.y][c.x] = line[c.x];
				c.x++;
			}
			//map[c.y][c.x] = '\n';
			c.x = 0;
			printf("%s\n", piece[c.y]);
			//free(line);
		}
		c.y++;
	}
	read_piece(game, piece);
}

void		get_map(t_game *game)
{
	char	map[game->map.y][game->map.x];
	char	*line;
	t_cd	c;

	c.y = 0;
	c.x = 0;
	printf("\n------------------------\n\n");
	while (c.y < game->map.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			//printf("c.x = %d\n", c.x);
			while (c.x < game->map.x + 4)
			{
				//printf("inwhile c.x = %d\n", c.x);
				map[c.y][c.x] = line[c.x + 4];
				c.x++;
			}
			//map[c.y][c.x] = '\n';
			c.x = 0;
			printf("%s\n", map[c.y]);
			//free(line);
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

	i = 0;
	game.map = set_coord(0, 0);
	get_next_line(0, &line);
	if (line[10] == '1' || line[10] == '2')
	{
		game.sign = ((line[10] == '1') ? 'O' : 'X');
		get_next_line(0, &line);
	}
	if (ft_strstr(line, "Plat"))
	{
		get_size(line, &game, 'm');
		get_next_line(0, &line);
		get_map(&game);
	}
	j = 3;
	while (i < j)
	{
		printf("p_x = %d\n", game.p_coord.px[i]);
		printf("p_y = %d\n", game.p_coord.py[i]);
		i++;
	}
	//printf("sign = %c\n", game.sign);
	//printf("y = %d\n", game.map.y);
	//printf("x = %d\n", game.map.x);
	//printf("ppy = %d\n", game.piece.y);
	//printf("ppx = %d\n", game.piece.x);
	free(line);
	return (0);
}
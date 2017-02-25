#include "filler.h"

void		read_piece(t_game *game, char piece[game->piece.y][game->piece.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	game->piece.px = (int *)malloc(sizeof(int) * 1000);
	game->piece.py = (int *)malloc(sizeof(int) * 1000);
	while (y < game->piece.y)
	{
		x = 0;
		while (x < game->piece.x)
		{
			if (piece[y][x] == '*' || piece[y][x] == '.')
			{
				game->piece.px[i] = x;
				game->piece.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	game->piece.i = i;
	remember_piece(game, piece);
}

void		read_o_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	game->p1.px = (int *)malloc(sizeof(int) * 1000);
	game->p1.py = (int *)malloc(sizeof(int) * 1000);
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

void		read_x_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	game->p2.px = (int *)malloc(sizeof(int) * 1000);
	game->p2.py = (int *)malloc(sizeof(int) * 1000);
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

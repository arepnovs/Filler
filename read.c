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
			if (piece[y][x] == '*' || piece[y][x] == '.')
			{
				game->p_coord.px[i] = x;
				game->p_coord.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	printf("!!!!!!i = %d!!!!!!!!!!!\n", i);
	game->p_coord.i = i;
}

void		read_o_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (map[y][x] == 'O' || map[y][x] == 'o')
			{
				game->p_coord.omx[i] = x;
				game->p_coord.omy[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	game->p_coord.oi = i;
	/*x = i;
	i = 0;
	printf("!!!!!!x = %d!!!!!!!!!!!\n", x);
	while (i < x)
	{
		printf("enemy_x = %d\n", game->p_coord.omx[i]);
		printf("enemy_y = %d\n", game->p_coord.omy[i]);
		i++;
	}*/

}

void		read_x_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (map[y][x] == 'X' || map[y][x] == 'x')
			{
				game->p_coord.xmx[i] = x;
				game->p_coord.xmy[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	game->p_coord.xi = i;
	/*x = i;
	i = 0;
	printf("!!!!!!x = %d!!!!!!!!!!!\n", x);
	while (i < x)
	{
		printf("my_x = %d\n", game->p_coord.xmx[i]);
		printf("my_y = %d\n", game->p_coord.xmy[i]);
		i++;
	}*/

}

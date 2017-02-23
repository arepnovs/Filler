#include "filler.h"

/*int			ft_check(char **tab, t_tetr *tetr, int size)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetr->x[i] == x && tetr->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (tetr->x[i] == x && tetr->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}*/

t_game		*all_xy(t_game *game, int x, int y, int *i)
{
	int tx;
	int ty;
	//int i;
	int j;

	printf("-----start--------\n");
	//i = 0;
	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while(ty <= y + (game->piece.y - 1))
	{
		while (tx <= x + (game->piece.x - 1))
		{
			printf("tx = %d\n", tx);
			printf("ty = %d\n", ty);
			ft_move_xy(game, tx, ty, i);
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	j = 0;
	printf("!!!!!!x = %d!!!!!!!!!!!\n", *i);
	printf("------------------------\n");
	while (j < (*i))
	{
		printf("i = %d\n", j);
		printf("enemy_x = %d\n", game->piece.px[j]);
		printf("enemy_y = %d\n", game->piece.py[j]);
		j++;
	}
	printf("-----end--------\n");
	return(game);
}

void	ft_move_xy(t_game *game, int x, int y, int *i)
{
	int		xmin;
	int		ymin;
	//int		i;
	int		j;

	xmin = 200;
	ymin = 200;
	j = 0;
	while (j != game->p_coord.i)
	{
		if (game->p_coord.px[j] < xmin)
			xmin = game->p_coord.px[j];
		if (game->p_coord.py[j] < ymin)
			ymin = game->p_coord.px[j];
		j++;
	}
	j = 0;
	while (j != game->p_coord.i && x < game->map.x - game->piece.x
		&& y < game->map.y - game->piece.y)
	{
		if(have to make check!!!!)
		game->piece.px[(*i)] = game->p_coord.px[j] - xmin + x;
		game->piece.py[(*i)] = game->p_coord.py[j] - ymin + y;
		j++;
	}
	if ((x >= game->map.x - game->piece.x
		|| y >= game->map.y - game->piece.y))
	{
		game->piece.px[(*i)] = -1;
		game->piece.py[(*i)] = -1;
	}

	(*i)++;
}

void		ft_recu_solver(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < game->p_coord.oi)
	{
		game = all_xy(game, game->p_coord.omx[i], game->p_coord.omy[i], &j);
		i++;
	}
	//return (NULL);
}
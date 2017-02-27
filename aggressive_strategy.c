#include "filler.h"

t_cd	read_x_move(t_game *game, int i)
{
	int		x;
	int		y;
	t_cd	e_move;

	y = 0;
	e_move.px = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	e_move.py = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->m_symb[y][x] == 'X' || game->m_symb[y][x] == 'x')
			{
				e_move.px[i] = x;
				e_move.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	e_move.i = i;
	return (e_move);
}

t_cd	read_o_move(t_game *game, int i)
{
	int		x;
	int		y;
	t_cd	e_move;

	y = 0;
	e_move.px = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	e_move.py = (int *)malloc(sizeof(int) * (game->map.x * game->map.y));
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->m_symb[y][x] == 'o' || game->m_symb[y][x] == 'O')
			{
				e_move.px[i] = x;
				e_move.py[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	e_move.i = i;
	return (e_move);
}

/*int	check_last_move(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->m_symb[y][x] == 'x' || game->m_symb[y][x] == 'x')
			{
				return(1);
			}
			x++;
		}
		y++;
	}
	return (0);
}*/

void	millitary_secret(t_game *game, int j, int i)
{
	float	res;
	float	s_res;
	
	//j = 0;
	s_res = 100000000.0;
	while (j < game->all_ok.i)
	{
		res = ft_sqrt(mult(game->all_ok.px[j], game->e_move.px[i]),
		mult(game->all_ok.py[j], game->e_move.py[i]));
		if (res < s_res)
		{
			s_res = res;
			game->all_ok.px[0] = game->all_ok.px[j];
			game->all_ok.py[0] = game->all_ok.py[j];
		}
		j++;
	}
}

t_game	*aggressive(t_game *game)
{
	int		i;
	int		j;
	//float	s_res;

	i = 0;
	j = 0;
	//s_res = 100000000.0;
	game->e_move = (game->sign == 'O') ? read_x_move(game, i) : read_o_move(game, i);
	while (i < game->e_move.i)
	{
		//j = 0;
		/*while (j < game->all_ok.i)
		{*/
			millitary_secret(game, j, i);
			j++;
		//}
		//j = 0;
		i++;
	}
	return (game);
}

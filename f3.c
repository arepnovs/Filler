#include "filler.h"

void		re_coord(t_game *game, int tx, int ty)
{
	int i;
	int j;

	i = 0;
	while (i < game->piece.i)
	{
		game->t.px[i] = game->piece.px[i] + tx;
		game->t.py[i] = game->piece.py[i] + ty;
		i++;
	}
}


int			check_o(t_game *game, int tx, int ty)
{
	int	x;
	int	y;
	int	i;
	int flag;

	y = 0;
	i = 0;
	flag = 0;
	re_coord(game, tx, ty);
	while (y < game->piece.y)
	{
		x = 0;
		while (x < game->piece.x)
		{
			if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'O' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'o'
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == '.' 
				|| (((game->m_symb[game->t.py[i]][game->t.px[i]] == 'X' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x') 
				&& game->p_symb[game->t.py[i] - ty][game->t.px[i] - tx] == '.'))) 
				&& flag <= 1 && game->t.py[i] + (game->piece.py[i] - i) <= game->map.y
				&& game->t.px[i] + (game->piece.px[i] - i) <= game->map.x
				&& game->t.py[i] <= game->map.y - (game->piece.y - i)
				&& game->t.px[i] <= game->map.x - (game->piece.x - i))
			{
				if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'O' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'o') 
					&& game->p_symb[game->t.py[i] - ty][game->t.px[i] - tx] == '*')
					flag++;
				i++;
			}
			else 
				return (0);
			x++;
		}
		y++;
	}
	return ((flag == 1 ) ? 1 : 0);
}

int			check_x(t_game *game, int tx, int ty)
{
	int	x;
	int	y;
	int	i;
	int flag;

	y = 0;
	i = 0;
	flag = 0;
	re_coord(game, tx, ty);
	while (y < game->piece.y)
	{
		x = 0;
		while (x < game->piece.x)
		{
			if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'X' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x'
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == '.' 
				|| (((game->m_symb[game->t.py[i]][game->t.px[i]] == 'O' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'o') 
				&& game->p_symb[game->t.py[i] - ty][game->t.px[i] - tx] == '.'))) 
				&& flag <= 1 && game->t.py[i] + (game->piece.py[i] - i) <= game->map.y
				&& game->t.px[i] + (game->piece.px[i] - i) <= game->map.x
				&& game->t.py[i] <= game->map.y - (game->piece.y - i)
				&& game->t.px[i] <= game->map.x - (game->piece.x - i))
			{
				if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'X' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x') 
					&& game->p_symb[game->t.py[i] - ty][game->t.px[i] - tx] == '*')
					flag++;
				i++;
			}
			else 
				return (0);
			x++;
		}
		y++;
	}
	return ((flag == 1 ) ? 1 : 0);
}

t_cd		all_o(t_game *game, int x, int y, int *i)
{
	int tx;
	int ty;
	t_cd res;

	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while (ty <= y)
	{
		while (tx <= x)
		{
			if (tx >= 0 && ty >= 0 && check_o(game, tx, ty) == 1)
			{
				game->all_ok.px[(*i)] = tx;
				game->all_ok.py[(*i)] = ty;
				(*i)++;
			}
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	res.x = game->all_ok.px[(*i) - 1];
	res.y = game->all_ok.py[(*i) - 1];
	return (res);
}

t_cd		all_x(t_game *game, int x, int y, int *i)
{
	int tx;
	int ty;
	t_cd res;
	int j;

	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while (ty <= y)
	{
		while (tx <= x)
		{
			if (tx >= 0 && ty >= 0 && check_x(game, tx, ty) == 1)
			{
				game->all_ok.px[(*i)] = tx;
				game->all_ok.py[(*i)] = ty;
				(*i)++;
			}
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	j = 0;
	res.x = game->all_ok.px[j];
	res.y = game->all_ok.py[j];
	return (res);
}

void		ft_recu_solver(t_game *game)
{
	int i;
	int j;
	t_cd res;

	i = 0;
	j = 0;
	game->all_ok.px = (int *)malloc(sizeof(int) * 1000);
	game->all_ok.py = (int *)malloc(sizeof(int) * 1000);
	game->t.px = (int *)malloc(sizeof(int) * 1000);
	game->t.py = (int *)malloc(sizeof(int) * 1000);
	if (game->sign == 'O')
	{
		while (i < game->p1.i)
		{
			res = all_o(game, game->p1.px[i], game->p1.py[i], &j);
			i++;
		}
	}
	else
	{
		while (i < game->p2.i)
		{
			res = all_x(game, game->p2.px[i], game->p2.py[i], &j);
			i++;
		}
	}
	ft_putnbr_fd(res.y, 1);
	write(1, " ", 1);
	ft_putnbr_fd(res.x, 1);
	write(1, "\n", 1);
}

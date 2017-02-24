#include "filler.h"

void 		re_coord(t_game *game, int tx, int ty)
{
	int i;
	int j;

	i = 0;
	while (i < game->p_coord.i)
	{
		game->t.px[i] = game->p_coord.px[i] + tx;
		game->t.py[i] = game->p_coord.py[i] + ty;
		i++;
	}
	/*j = 0;
	printf("------------------------\n");
	while (j < game->p_coord.i)
	{
		printf("i = %d\n", j);
		printf("enemy_x = %d\n", game->t.px[j]);
		printf("enemy_y = %d\n", game->t.py[j]);
		j++;
	}*/
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
		while (x < game->piece.x/* && game->t.py[i] <= game->map.y 
			&& game->t.px[i] <= game->map.x*/)
		{
			//re_coord(game, tx, ty);
			if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'O' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'o'
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == '.') && flag <= 1)
			{
				if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'O' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'o') 
					&& game->p_symb[game->t.py[i]][game->t.px[i]] != '.')
					flag++;
				i++;
			}
			else /*if (game->m_symb[game->t.py[i]][game->t.px[i]] == 'X'
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x' || flag > 1)*/
				return(0);
			x++;
		}
		y++;
	}
	return ((flag == 1) ? 1 : 0);
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
		while (x < game->piece.x /*&& game->t.py[i] < game->map.y 
			&& game->t.px[i] < game->map.x*/)
		{
			//re_coord(game, tx, ty);
			if ((game->m_symb[game->t.py[i]][game->t.px[i]] == 'X' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x'
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == '.') && flag <= 1)
			{
				if (game->m_symb[game->t.py[i]][game->t.px[i]] == 'X' 
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x')
					flag++;
				i++;
			}
			else /*if (game->m_symb[game->t.py[i]][game->t.px[i]] == 'X'
				|| game->m_symb[game->t.py[i]][game->t.px[i]] == 'x' || flag > 1)*/
				return(0);
			x++;
		}
		y++;
	}
	return ((flag == 1) ? 1 : 0);
}

t_cd		all_o(t_game *game, int x, int y, int *i)
{
	int tx;
	int ty;
	t_cd res;
	int j;

	//printf("--------start--------\n");
	//i = 0;
	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while(ty <= y + (game->piece.y - 1))
	{
		while (tx <= x + (game->piece.x - 1))
		{
			if (tx >= 0 && ty >= 0 && check_o(game, tx, ty) == 1)
			{
				game->allp.px[(*i)] = tx;
				game->allp.py[(*i)] = ty;
				(*i)++;
			}
			//ft_move_xy(game, tx, ty, i);
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	j = 0;
	/*printf("!!!!!!x = %d!!!!!!!!!!!\n", *i);
	printf("------------------------\n");
	while (j < (*i))
	{
		printf("i = %d\n", j);
		printf("enemy_x = %d\n", game->allp.px[j]);
		printf("enemy_y = %d\n", game->allp.py[j]);
		j++;
	}
	printf("--------end--------\n");*/
	res.x = game->allp.px[j];
	res.y = game->allp.py[j];
	return(res);
}
t_cd		all_x(t_game *game, int x, int y, int *i)
{
	int tx;
	int ty;
	t_cd res;
	int j;

	//printf("--------start--------\n");
	//i = 0;
	tx = x - (game->piece.x - 1);
	ty = y - (game->piece.y - 1);
	while(ty <= y + (game->piece.y - 1))
	{
		while (tx <= x + (game->piece.x - 1))
		{
			if (tx >= 0 && ty >= 0 && check_x(game, tx, ty) == 1)
			{
				game->allp.px[(*i)] = tx;
				game->allp.py[(*i)] = ty;
				(*i)++;
			}
			//ft_move_xy(game, tx, ty, i);
			tx++;
		}
		tx = x - (game->piece.x - 1);
		ty++;
	}
	j = 0;
	/*printf("!!!!!!x = %d!!!!!!!!!!!\n", *i);
	printf("------------------------\n");
	while (j < (*i))
	{
		printf("i = %d\n", j);
		printf("enemy_x = %d\n", game->allp.px[j]);
		printf("enemy_y = %d\n", game->allp.py[j]);
		j++;
	}
	printf("--------end--------\n");*/
	res.x = game->allp.px[j];
	res.y = game->allp.py[j];
	return(res);
}

void		ft_recu_solver(t_game *game)
{
	int i;
	int j;
	t_cd res;

	i = 0;
	j = 0;
	if (game->sign == 'O')
	{
		while (i < game->p_coord.oi)
		{
			res = all_o(game, game->p_coord.omx[i], game->p_coord.omy[i], &j);
			i++;
		}
	}
	else
	{
		while (i < game->p_coord.xi)
		{
			res = all_x(game, game->p_coord.xmx[i], game->p_coord.xmy[i], &j);
			i++;
		}
	}
	ft_putnbr_fd(res.y, 1);
	write(1, " ", 1);
	ft_putnbr_fd(res.x, 1);
	write(1, "\n", 1);
	//ft_putstr_fd("\n", 1);
	//printf("[%d, %d]", res.y, res.x);
	//return (NULL);
}
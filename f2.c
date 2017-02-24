# include "filler.h"

t_cd	set_coord(int x, int y)
{
	t_cd	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void		get_size(char *line, t_game *game, char w)
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

void	remember_map(t_game *game, char map[game->map.y][game->map.x])
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	game->m_symb = (char **)malloc((game->map.y + 1) * sizeof(char *));
	while (y < game->map.y)
	{
		game->m_symb[y] = ft_strnew(0);
		while (x < game->map.x)
		{
			game->m_symb[y] = ft_charjoin(game->m_symb[y], map[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	game->m_symb[y] = NULL;
}

void	remember_piece(t_game *game, char piece[game->piece.y][game->piece.x])
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	game->p_symb = (char **)malloc((game->piece.y + 1) * sizeof(char *));
	while (y < game->piece.y)
	{
		game->p_symb[y] = ft_strnew(0);
		while (x < game->piece.x)
		{
			game->p_symb[y] = ft_charjoin(game->p_symb[y], piece[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	game->p_symb[y] = NULL;
}
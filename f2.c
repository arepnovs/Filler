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
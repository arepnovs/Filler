#include "filler.h"

void		get_piece(t_game *game, char map[game->map.y][game->map.x])
{
	char	piece[game->piece.y][game->piece.x];
	char	*line;
	t_cd	c;

	c.y = 0;
	c.x = 0;
	//printf("\n------------------------\n\n");
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
			//printf("%s\n", piece[c.y]);
			//free(line);
		}
		c.y++;
	}
	//ft_putstr_fd("444444444444!!!", 1);
	read_piece(game, piece);
	//ft_putstr_fd("333333333333", 1);
	read_o_map(game, map);
	//ft_putstr_fd("22222222222222", 1);
	read_x_map(game, map);
	//ft_putstr_fd("1111111111111", 1);
	remember_map(game, map);
	//printf("\n------------------------\n\n");
	//ft_arr_putstr(game->m_symb);
	//printf("\n------------------------\n\n");
	//ft_arr_putstr(game->p_symb);
	//printf("\n------------------------\n\n");
	//ft_putstr_fd("!!!!!!!!!!!!!!!!!!", 1);
	ft_recu_solver(game);
}

void		get_map(t_game *game)
{
	char	map[game->map.y][game->map.x];
	char	*line;
	t_cd	c;

	c.y = 0;
	c.x = 0;
	//printf("\n------------------------\n\n");
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
			//printf("%s\n", map[c.y]);
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
	int ret;

	i = 0;
	//game.map = set_coord(0, 0);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		//get_next_line(0, &line);
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
			//ft_putstr_fd("\n", 1);
			get_map(&game);
		}
		//free(line);
	}
	return (0);
}
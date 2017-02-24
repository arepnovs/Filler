#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_cd
{
	int				x;
	int				y;
	int 			i;
	int				px[1000];
	int				py[1000];
	int				xi;
	int				xmx[1000];
	int				xmy[1000];
	int				oi;
	int				omx[1000];
	int				omy[1000];
}					t_cd;

typedef struct		s_game
{
	char			sign;
	char			**p_symb;
	char			**m_symb;
	t_cd			map;
	t_cd			piece;
	t_cd			p_coord;
	t_cd			allp;
	t_cd			t;
}					t_game;

/*pr1.c*/
int			main(void);
void		get_map(t_game *game);
void		get_piece(t_game *game, char map[game->map.y][game->map.x]);

/*pr2.c*/
t_cd	    set_coord(int x, int y);
void		get_size(char *line, t_game *game, char w);
void		remember_map(t_game *game, char map[game->map.y][game->map.x]);
void		remember_piece(t_game *game, char piece[game->piece.y][game->piece.x]);
/*read.c*/
void		read_piece(t_game *game, char piece[game->piece.y][game->piece.x]);
void		read_o_map(t_game *game, char map[game->map.y][game->map.x]);
void		read_x_map(t_game *game, char map[game->map.y][game->map.x]);
/*f3.c*/
t_cd		all_x(t_game *game, int x, int y, int *i);
t_cd		all_o(t_game *game, int x, int y, int *i);
void		ft_recu_solver(t_game *game);

#endif

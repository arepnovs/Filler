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
	int				px[1000];
	int				py[1000];
}					t_cd;

typedef struct		s_game
{
	char			sign;
	t_cd			map;
	t_cd			piece;
	t_cd			p_coord;
	t_cd			p_upleft;
	t_cd			p_upright;
	t_cd			p_dnleft;
	t_cd			p_dnright;

}					t_game;

/*pr1.c*/
int			main(void);
void		get_map(t_game *game);
void		get_piece(t_game *game, char map[game->map.y][game->map.x]);
void		read_piece(t_game *game, char piece[game->piece.y][game->piece.x]);
/*pr2.c*/
t_cd	    set_coord(int x, int y);
void		get_size(char *line, t_game *game, char w);

#endif

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define RED 	"\x1B[31m"
# define BLUE   "\x1B[34m"
# define GREEN  "\x1B[32m"
# define RESET  "\x1B[0m"

typedef struct		s_cd
{
	int				x;
	int				y;
	int 			i;
	int				*px;
	int				*py;
}					t_cd;

typedef struct		s_game
{
	char			sign;
	char			**p_symb;
	char			**m_symb;
	char			**map_cmp;
	int				flag;
	t_cd			map;
	t_cd			piece;
	t_cd			p1;
	t_cd			p2;
	t_cd			all_ok;
	t_cd			t;
	t_cd			e_move;
}					t_game;

/*arepnovs_filler.c*/
void		get_piece(t_game *game, char map[game->map.y][game->map.x]);
void		get_map(t_game *game);
void		use_strategy(t_game *game);
void		game_start(t_game *game);
int			main(void);
/*read.c*/
void		read_piece(t_game *game, char piece[game->piece.y][game->piece.x]);
void		remember_piece(t_game *game, char piece[game->piece.y][game->piece.x]);
void		read_o_map(t_game *game, char map[game->map.y][game->map.x]);
void		read_x_map(t_game *game, char map[game->map.y][game->map.x]);
void		remember_map(t_game *game, char map[game->map.y][game->map.x]);
/*player1.c*/
int			make_check_o(t_game *g, int ty, int tx, int i);
int			check_o(t_game *game, int tx, int ty);
t_game		*all_o(t_game *game, int x, int y, int *i);
/*player2.c*/
void		map_copy(t_game *game);
int			make_check_x(t_game *g, int ty, int tx, int i);
int			check_x(t_game *game, int tx, int ty);
t_game		*all_x(t_game *game, int x, int y, int *i);
/*tools.c*/
t_cd		set_coord(int x, int y);
void		re_coord(t_game *game, int tx, int ty);
void		get_size(char *line, t_game *game, char w);
float		mult(int x1, int x2);
float		ft_sqrt(float res1, float res2);
/*aggressive.c*/
t_cd		find_move_x(t_game *game, int *i);
t_cd		find_move_o(t_game *game, int *i);
t_cd		read_move(t_game *gm, int i);
void		millitary_secret(t_game *game, int j, int i);
t_game		*aggressive(t_game *gm);
/*bonus*/
int		get_res(char *line);
void	input_check(char *line);

#endif

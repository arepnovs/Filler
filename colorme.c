/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:47:01 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/01 17:47:10 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_res(char *line)
{
	char	*tmp;
	int		res;

	tmp = ft_strchr(line, ' ');
	tmp++;
	tmp = ft_strchr(tmp, ' ');
	tmp++;
	tmp = ft_strchr(tmp, ' ');
	res = ft_atoi(tmp);
	return (res);
}

void	input_check(char *line)
{
	int	i;

	i = 0;
	if (line[1] == '$')
	{
		if (line[10] == '1')
			printf(RED "%s\n" RESET, line);
		else if (line[10] == '2')
			printf(BLUE "%s\n" RESET, line);
	}
	if (line[0] >= '0' && line[0] <= '9' && line[1] >= '0' && line[0] <= '1')
	{
		while (line[i])
		{
			if (line[i] == 'O')
				printf(RED "%c" RESET, line[i]);
			else if (line[i] == 'o')
				printf(YELLOW "%c" RESET, line[i]);
			else if (line[i] == 'X')
				printf(BLUE "%c" RESET, line[i]);
			else if (line[i] == 'x')
				printf(GREEN "%c" RESET, line[i]);
			else
				printf("%c", line[i]);
			i++;
		}
		printf("\n");
	}
}

int		main(void)
{
	char	*line;
	t_cd	res;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		input_check(line);
		if (line[0] == '=')
		{
			res.x = get_res(line);
			printf(RED "%s\n" RESET, line);
			get_next_line(0, &line);
			printf(BLUE "%s\n" RESET, line);
			res.y = get_res(line);
			if (res.x == res.y)
				printf(GREEN "%s\n" RESET, "DRAW");
			(res.x > res.y) ? printf(RED "%s\n" RESET, "Player 1 WINS")
			: printf(BLUE "%s\n" RESET, "Player 2 WINS");
		}
		else if (line[0] == ' ' || line[0] == '.' || line[0] == '*'
			|| line[0] == 'P' || line[0] == '<')
			printf("%s\n", line);
		free(line);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:52:41 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/07 20:38:27 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "Lib/src/libft/libft.h"
# include "Lib/src/ft_printf/ft_printf.h"
# include "Lib/src/get_next_line/get_next_line.h"

typedef struct		s_ler
{
	char			**map;
	char			**fig;
	char			*letter;
	char			*not_mine;
	int				map_x;
	int				map_y;
	int				fig_x;
	int				fig_y;
	int				p1;
	int				p2;
	int				i;
	int				i_f;
	int				w_x;
	int				w_y;
	int				cm_x;
	int				cf_x;
	int				cm_y;
	int				cf_y;
	int				no_more;
	int				n;
	int				m;
	int				q;
	int				print;
}					t_ler;

t_ler				g_s;

void				write_map(char *line);
void				write_fig(char *line);
void				map_size(char *line);
void				fig_size(char *line);
void				clean(int i);
void				lets_start(void);
void				find_place(void);
void				one_more(void);
void				find_best(void);
void				best(int x1, int y1, int x, int y);
int					mod(int first, int second);
int					check(int x, int y, int rub);
void				bott(int rub);
void				top(void);
void				add(void);

#endif

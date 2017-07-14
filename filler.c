/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:02:53 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/07 20:36:04 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lets_start(void)
{
	clean(1);
	g_s.letter = (g_s.p1 == 1) ? "oO" : "xX";
	g_s.not_mine = !(ft_strcmp(g_s.letter, "oO")) ? "xX" : "oO";
	while ((g_s.cm_x < g_s.map_x) && ((g_s.cm_x + g_s.fig_x) <= (g_s.map_x)))
	{
		while ((g_s.cm_y < g_s.map_y) && (g_s.cf_x < g_s.fig_x))
		{
			find_place();
			if ((g_s.cf_y == g_s.fig_y) && (g_s.cf_x != g_s.fig_x))
				add();
		}
		if ((g_s.cf_x == g_s.fig_x) && (g_s.no_more == 1))
			find_best();
		if (((g_s.cf_x == g_s.fig_x) || (g_s.cm_y == g_s.map_y)))
			one_more();
	}
	if (g_s.print == 1)
	{
		ft_printf("%d %d\n", g_s.w_x, g_s.w_y);
		g_s.q = 0;
		g_s.print = 0;
	}
	else
		ft_printf("%d %d\n", 0, 0);
}

void	find_place(void)
{
	if (ft_strchr(g_s.letter, g_s.map[g_s.cm_x][g_s.cm_y]) &&
			ft_strchr("*", g_s.fig[g_s.cf_x][g_s.cf_y]))
		g_s.no_more++;
	if ((ft_strchr(g_s.not_mine, g_s.map[g_s.cm_x][g_s.cm_y]) &&
				ft_strchr("*", g_s.fig[g_s.cf_x][g_s.cf_y])) || g_s.no_more > 1)
	{
		g_s.n++;
		g_s.cm_y = -1;
		g_s.cm_y += g_s.n;
		g_s.cf_y = -1;
		g_s.no_more = 0;
		if (g_s.cf_x > 0)
		{
			g_s.cm_x -= g_s.cf_x;
			g_s.cf_x = 0;
		}
	}
	g_s.cf_y++;
	g_s.cm_y++;
}

void	fig_size(char *line)
{
	while (*line != ' ')
		line++;
	g_s.fig_x = ft_atoi(line);
	line++;
	while (ft_isdigit((int)*line))
		line++;
	g_s.fig_y = ft_atoi(line);
	g_s.fig = (char **)malloc(sizeof(char *) * (g_s.fig_x + 1));
}

void	map_size(char *line)
{
	g_s.i = 0;
	g_s.i_f = 0;
	while (*line != ' ')
		line++;
	g_s.map_x = ft_atoi(line);
	if (g_s.map_x == 15)
		g_s.map_y = 17;
	else if (g_s.map_x == 24)
		g_s.map_y = 40;
	else if (g_s.map_x == 100)
		g_s.map_y = 99;
	g_s.map = (char **)malloc(sizeof(char *) * (g_s.map_x + 1));
}

void	add(void)
{
	g_s.cm_y -= g_s.cf_y;
	g_s.cf_y = 0;
	g_s.cf_x++;
	g_s.cm_x++;
}

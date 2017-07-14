/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrt_cln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:25:20 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/07 20:34:15 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(int x, int y, int rub)
{
	int x1;
	int y1;

	x1 = x - rub;
	x1 < 0 ? x1 = x : 0;
	y1 = y - rub;
	y1 < 0 ? y1 = y : 0;
	while (x1 <= (x + rub) && (x1 < g_s.map_x))
	{
		while ((y1 <= (y + rub)) && (y1 < g_s.map_y))
		{
			if ((g_s.map[x1][y1] == 'O') || (g_s.map[x1][y1] == 'X'))
				return (0);
			y1++;
		}
		y1 = y - rub;
		y1 < 0 ? y1 = y : 0;
		x1++;
	}
	return (1);
}

void	one_more(void)
{
	if (g_s.cm_y != g_s.map_y)
	{
		g_s.n++;
		g_s.cm_y = 0;
		g_s.cm_y += g_s.n;
		g_s.cm_x -= g_s.cf_x;
		g_s.cf_y = 0;
		g_s.cf_x = 0;
	}
	if (g_s.cm_y == g_s.map_y)
	{
		g_s.m++;
		g_s.cm_x = 0;
		g_s.cm_x += g_s.m;
		g_s.cm_y = 0;
		g_s.cf_y = 0;
		g_s.cf_x = 0;
		g_s.n = 0;
	}
	g_s.no_more = 0;
}

void	clean(int i)
{
	if (i == 0)
	{
		g_s.i = 0;
		g_s.i_f = 0;
		g_s.p1 = 0;
		g_s.p2 = 0;
		g_s.fig_x = 0;
		g_s.fig_y = 0;
		g_s.map_x = 0;
		g_s.map_y = 0;
		g_s.no_more = 0;
		g_s.q = 0;
	}
	else if (i == 1)
	{
		g_s.w_x = 0;
		g_s.w_y = 0;
		g_s.cf_x = 0;
		g_s.cm_x = 0;
		g_s.cf_y = 0;
		g_s.cm_y = 0;
		g_s.n = 0;
		g_s.m = 0;
		g_s.no_more = 0;
	}
}

void	write_fig(char *line)
{
	g_s.fig[g_s.i_f] = ft_strsub(line, 0, (size_t)g_s.fig_y);
	g_s.i_f++;
}

void	write_map(char *line)
{
	g_s.map[g_s.i] = ft_strsub(line, 4, (size_t)g_s.map_y);
	g_s.i++;
}

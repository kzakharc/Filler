/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 18:37:07 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/07 20:39:58 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	top(void)
{
	if (check(g_s.cm_x, 0, 2))
		best(g_s.i, g_s.i_f, g_s.cm_x, 0);
	else if (check(g_s.map_x / 3, g_s.map_y - 1, 1))
		best(g_s.i, g_s.i_f, g_s.map_x / 3, g_s.map_y - 1);
	else if (check(g_s.map_x - 1, g_s.map_y / 2, 1))
		best(g_s.i, g_s.i_f, g_s.map_x - 1, g_s.map_y / 2);
	else if (check(g_s.map_x / 2, 0, 1))
		best(g_s.i, g_s.i_f, g_s.map_x / 2, 0);
	else if (check(0, g_s.map_y / 2, 2))
		best(g_s.i, g_s.i_f, 0, g_s.map_y / 2);
	else if (check(0, 0, 2))
		best(g_s.i, g_s.i_f, 0, 0);
	else if (check(g_s.map_x / 2, g_s.map_y / 2, 0))
		best(g_s.i, g_s.i_f, g_s.map_x / 2, g_s.map_y / 2);
	else
		best(g_s.i, g_s.i_f, g_s.map_x / 4 * 3, g_s.map_y / 2);
}

void	bott(int rub)
{
	if (check(0, g_s.map_y / 2, 0) && g_s.map_x == 15)
		best(g_s.i, g_s.i_f, 0, g_s.map_y / 2);
	else if (check(g_s.cm_x / 2, g_s.map_y / 2, 0) && g_s.map_x == 15)
		best(g_s.i, g_s.i_f, g_s.cm_x / 2, g_s.map_y / 2);
	else if (check(g_s.map_x / 4 * 3, 0, 1) && g_s.map_x == 24)
		best(g_s.i, g_s.i_f, g_s.map_x / 4 * 3, 0);
	else if (check(g_s.map_x / 2, 0, rub) && g_s.map_x != 24)
		best(g_s.i, g_s.i_f, g_s.map_x / 2, 0);
	else if (check(g_s.map_x / 2, g_s.map_y - 1, rub))
		best(g_s.i, g_s.i_f, g_s.map_x / 2, g_s.map_y - 1);
	else if (check(0, g_s.map_y / 2, rub) && g_s.map_x != 24)
		best(g_s.i, g_s.i_f, 0, g_s.map_y / 2);
	else if (check(g_s.map_x - 1, g_s.map_y / 2, rub) && g_s.map_x != 24)
		best(g_s.i, g_s.i_f, g_s.map_x - 1, g_s.map_y / 2);
	else if (check(0, 0, rub))
		best(g_s.i, g_s.i_f, 0, 0);
	else if (check(g_s.map_x / 4, g_s.map_y - 1, 0) && g_s.map_x == 24)
		best(g_s.i, g_s.i_f, g_s.map_x / 4, g_s.map_y - 1);
	else if (check(0, g_s.map_y / 3 * 2, 0) && g_s.map_x == 24)
		best(g_s.i, g_s.i_f, 0, g_s.map_y / 3 * 2);
	else if (check(0, g_s.map_y - 1, rub))
		best(g_s.i, g_s.i_f, 0, g_s.map_y - 1);
	else
		best(g_s.i, g_s.i_f, g_s.map_x / 4, g_s.map_y / 2);
}

void	find_best(void)
{
	int rub;

	rub = 0;
	g_s.map_x == 15 ? rub = 0 : 0;
	g_s.map_x == 100 ? rub = 4 : 0;
	g_s.map_x == 24 ? rub = 1 : 0;
	g_s.i = (g_s.cm_x - g_s.cf_x);
	g_s.i_f = (g_s.cm_y - g_s.cf_y);
	if (((g_s.p1 == 1) && g_s.map_x != 100) ||
			((g_s.p2 == 1) && g_s.map_x == 100))
		top();
	else if (((g_s.p2 == 1) && g_s.map_x != 100) ||
			((g_s.p1 == 1) && g_s.map_x == 100))
		bott(rub);
}

void	best(int x1, int y1, int x, int y)
{
	static int	d;
	int			try;

	if (g_s.q == 0)
	{
		d = mod(x1, x) + mod(y1, y);
		g_s.w_x = x1;
		g_s.w_y = y1;
		g_s.q++;
	}
	try = mod(x1, x) + mod(y1, y);
	if (try <= d)
	{
		d = try;
		g_s.w_x = x1;
		g_s.w_y = y1;
		g_s.print = 1;
	}
}

int		mod(int first, int second)
{
	int summ;

	summ = (first - second);
	if (summ < 0)
		summ *= -1;
	return (summ);
}

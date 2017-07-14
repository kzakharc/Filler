/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:11:59 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/07 20:40:52 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;

	clean(0);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1"))
			g_s.p1 = 1;
		else if (ft_strstr(line, "$$$ exec p2"))
			g_s.p2 = 1;
		else if (ft_strstr(line, "Plateau"))
			map_size(line);
		else if (line[0] == '0')
			write_map(line);
		else if (ft_strstr(line, "Piece"))
			fig_size(line);
		else if ((line[0] == '*') || (line[0] == '.'))
			write_fig(line);
		if ((g_s.map_x == g_s.i) && (g_s.fig_x == g_s.i_f) &&
				(g_s.map_x > 0) && (g_s.fig_x > 0))
			lets_start();
	}
	return (0);
}

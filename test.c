/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:28:23 by rluder            #+#    #+#             */
/*   Updated: 2016/01/30 17:22:39 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	t_win	tab[16];
	int		i;
	int		j;

	i = 0;
	while (i < 16)
		tab[i++].win = NULL;
	i = 0;
	initscr();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	while (i < 16)
	{
		if ((i + 5) % 4)
			j = (i + 1) % 4;
		else
			j = 4;
		tab[i].win = subwin(stdscr, LINES / 4, COLS / 4, LINES / j, COLS / (16 / ((i + 1) % 4)));
		box(tab[i].win, ACS_VLINE, ACS_HLINE);

		mvwprintw(tab[i].win, 1, 1, "Ceci est la fenetre du haut");

		wrefresh(tab[i].win);
		if (getch() != 410)
			break;
		i++;
	}
	endwin();
//	free(tab[i].win);

	return 0;
}

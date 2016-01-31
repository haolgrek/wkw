/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainjchen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:22:20 by rluder            #+#    #+#             */
/*   Updated: 2016/01/31 18:07:29 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	initrandom(int*tab)
{
	int	i;
	int	k;

	k = 0;
	srand(time(NULL));
	while (k < 2)
	{
		i = rand() % 16;
		tab[i] = ((rand() % 2 + 1) * 2);
		k++;
	}
	return (0);
}

static void	set_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 16)
		tab[i++] = 0;
}

static void	do_resize(t_win *board, int lines, int cols, int *tab)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (i < 16)
	{
		x = (i % 4 == 0) ? 0 : 0;
		x = (i % 4 == 1) ? cols : x;
		x = (i % 4 == 2) ? (cols * 2) : x;
		x = (i % 4 == 3) ? (cols * 3) : x;
		y = (i / 4 == 0) ? 0 : 0;
		y = (i / 4 == 1) ? lines : y;
		y = (i / 4 == 2) ? (lines * 2) : y;
		y = (i / 4 == 3) ? (lines * 3) : y;
		if (board[i].win)
			delwin(board[i].win);
		board[i].win = newwin(lines, cols, y, x);
		board[i].value = tab[i];
		if (board[i].value == WIN_VALUE)
		{
			board[i].win = newwin(LINES / 4, COLS / 8, LINES / 2, COLS / 2);
			wborder(board[i].win, '|', '|', '-', '-', '+', '+', '+', '+');
		}
		if (board[i].value)
			mvprintw(y + (lines / 2), x + (cols / 2), "%d", board[i].value);
		wborder(board[i].win, '|', '|', '-', '-', '+', '+', '+', '+');
		wrefresh(board[i++].win);
		refresh();
	}
	return ;
}

static void	init_ncurses(t_win *board)
{
	int		i;

	i = 0;
	while (i < 16)
		board[i++].win = NULL;
	initscr();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
}

int		main(void)
{
	int		ch;
	int		tab[16];
	t_win	board[16];

	ch = 0;
	set_tab(tab);
	initrandom(tab);
	init_ncurses(board);
	while (ch != 27)
	{
		clear();
		if (ch == 258 || ch == 259 || ch == 260 || ch == 261)
			keypressed(ch, tab);
		do_resize(board, LINES / 4, COLS / 4, tab);
		ch = getch();
	}
	endwin();
	return 0;
}

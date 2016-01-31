/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:12:12 by rluder            #+#    #+#             */
/*   Updated: 2016/01/31 17:52:03 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>

enum	e_const
{
	WIN_VALUE = 2048
};

typedef	struct		s_win
{
	WINDOW			*win;
	int				value;
	struct s_win	*next;
}					t_win;

int	keypressed(int ch, int *tab);

int	added_bot(int *tab);
int	push_bot(int *tab);
int	added_up(int *tab);
int	push_up(int *tab);
int	added_left(int *tab);
int	added_right(int *tab);
int	push_left(int *tab);
int	push_right(int *tab);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:12:12 by rluder            #+#    #+#             */
/*   Updated: 2016/01/30 19:03:47 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <ncurses.h>
# include <stdlib.h>

typedef	struct		s_win
{
	WINDOW			*win;
	int				value;
	struct s_win	*next;
}					t_win;

#endif

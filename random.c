/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:26:44 by rluder            #+#    #+#             */
/*   Updated: 2016/01/31 18:19:55 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	randompop(int *tab)
{
	int	i;

	i = 0;
	srand(time(NULL));
	while (1)
	{
		i = rand() % 16;
		if (tab[i] == 0)
		{
			tab[i] = ((rand() % 2 + 1) * 2);
			break;
		}
	}
	return (0);
}

int	keypressed(int ch, int *tab)
{
	if (ch == 258)
	{
		if (added_bot(tab))
			randompop(tab);
	}
	else if (ch == 259)
	{
		if (added_up(tab))
			randompop(tab);
	}
	else if (ch == 260)
	{
		if (added_left(tab))
			randompop(tab);
	}
	else if (ch == 261)
	{
		if (added_right(tab))
			randompop(tab);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:26:44 by rluder            #+#    #+#             */
/*   Updated: 2016/01/30 20:13:07 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	initrandom(int	*tab)
{
	int i;
	int	k;

	k = 0;
	while (k < 2)
	{
		i = rand() % 16;
		tab[i] = ((rand() % 2 + 1) * 2);
		k++;
	}
	return (0);
}

int	botarrow(int *tab)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (added_bot(tab) && deplaced(tab))
	{
		while (k == 0)
		{
			i = rand() % 16;
			if (tab[i] == 0)
			{
				tab[i] = ((rand() % 2) + 1) * 2;
				k = 1;
			}
		}
	}
}

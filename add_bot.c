/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:44:19 by cmichaud          #+#    #+#             */
/*   Updated: 2016/01/31 18:26:01 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int added_bot(int *tab)
{
	int i;
	int n;

	n = 0;
	i = 15;
	while (i != 0)
	{
		if (i <= 3)
			i += 12 - 1;
		if (tab[i] == tab[i - 4])
		{
			tab[i] = 0;
			tab[i - 4] *= 2;
			if (i - 8 >= 0)
				i -= 8;
			else
				i -= 4;
			n = 1;
		}
		else if (i >= 8 && tab[i] == tab[i - 8] && tab[i - 4] == 0)
		{
			tab[i] = 0;
			tab[i - 8] *= 2;
			if (i - 12 >= 0)
				i -= 12;
			else
				i -= 8;
			n = 1;
		}
		else if (i >= 12 && tab[i] == tab[i - 12] && tab[i - 8] == 0
				&& tab[i - 4] == 0)
		{
			tab[i] = 0;
			tab[i - 12] *= 2;
			i -= 12;
			n = 1;
		}
		else
			i -= 4;
	}
	i = push_bot(tab);
	if (n == 0)
		return (i);
	return (n);
}

int push_bot(int *tab)
{
	int i;
	int n;
	int j;

	j = 0;
	i = 15;
	while (i != 0)
	{
		if (i <= 3)
		{
			i += 12 - 1;
		}
		while (i > 3)
		{
			n = i - 4;
			while (n >= 0)
			{
				if (tab[i] == 0 && tab[n] != 0)
				{
					tab[i] = tab[n];
					tab[n] = 0;
					j = 1;
				}
				n -= 4;
			}
			i -= 4;
		}
	}
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:46:11 by cmichaud          #+#    #+#             */
/*   Updated: 2016/01/31 18:25:17 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int added_up(int *tab)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (i != 15)
	{
		if (i >= 12)
			i -= 12 + 1;
		if (tab[i] == tab[i + 4])
		{
			tab[i] = 0;
			tab[i + 4] *= 2;
			if (i + 8 <= 15)
				i += 8;
			else
				i += 4;
			n = 1;
		}
		else if (i < 8 && tab[i] == tab[i + 8] && tab[i + 4] == 0)
		{
			tab[i] = 0;
			tab[i + 8] *= 2;
			if (i + 12 <= 15)
				i += 12;
			else
				i += 8;
			n = 1;
		}
		else if (i < 4 && tab[i] == tab[i + 12] && tab[i + 4] == 0
				&& tab[i + 8] == 0)
		{
			tab[i] = 0;
			tab[i + 12] *= 2;
			i += 12;
			n = 1;
		}
		else
			i += 4;
	}
	i = push_up(tab);
	if (n == 0)
		return (i);
	return (n);
}

int push_up(int *tab)
{
	int i;
	int n;
	int j;

	j = 0;
	i = 0;
	while (i != 15)
	{
		if (i >= 12)
			i -= 11;
		while (i < 12)
		{
			n = i + 4;
			while (n <= 15)
			{
				if (tab[i] == 0 && tab[n] != 0)
				{
					tab[i] = tab[n];
					tab[n] = 0;
					j = 1;
				}
				n += 4;
			}
			i += 4;
		}
	}
	return (j);
}

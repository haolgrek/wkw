/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:45:49 by cmichaud          #+#    #+#             */
/*   Updated: 2016/01/31 18:27:03 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int added_left(int *tab)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i != 15)
	{
		if ((i + 1) % 4 == 0)
			i++;
		if (tab[i] == tab[i + 1])
		{
			tab[i] = 0;
			tab[i + 1] *= 2;
			if ((i + 1) % 4 == 3)
				i++;
			else
				i += 2;
			n = 1;
		}
		else if ((i + 1) % 4 != 3 && tab[i] == tab[i + 2] && tab[i + 1] == 0)
		{
			tab[i] = 0;
			tab[i + 2] *= 2;
			if ((i + 1) % 4 == 2)
				i += 2;
			else
				i += 3;
			n = 1;
		}
		else if ((i + 1) % 4 == 1 && tab[i] == tab[i + 3] && tab[i + 2] == 0
				&& tab[i + 1] == 0)
		{
			tab[i] = 0;
			tab[i + 3] *= 2;
			i += 3;
			n = 1;
		}
		else
			i++;
	}
	i = push_left(tab);
	if (n == 0)
		return (i);
	return (n);
}

int push_left(int *tab)
{
	int i;
	int n;
	int j;

	j = 0;
	i = 0;
	while (i != 15)
	{
		if ((i + 1) % 4 == 0)
			i++;
		while ((i + 1) % 4 != 0)
		{
			n = i + 1;
			while ((n + 1) % 4 != 1)
			{
				if (tab[i] == 0 && tab[n] != 0)
				{
					tab[i] = tab[n];
					tab[n] = 0;
					j = 1;
				}
				n++;
			}
			i++;
		}
	}
	return (j);
}

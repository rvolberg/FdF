/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:12:25 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 12:45:27 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui free tab char** tmp
*/

void		free_map_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free((void*)tab);
}

/*
** ft qui free tab int**
*/

void		free_int_tab(int **tab, int len, int hei)
{
	int		y;

	y = 0;
	while (y < hei)
	{
		free(tab[y]);
		y++;
	}
	free((void*)tab);
}

/*
** ft clear image
*/

void		ft_clear_image(t_map *stc)
{
	float	x;
	float	y;

	y = 0;
	x = 0;
	while (y < stc->d_hei)
	{
		while (x < stc->d_len)
		{
			ft_print_pixel(x, y, stc, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

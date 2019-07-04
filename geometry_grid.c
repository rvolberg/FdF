/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:11:29 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 12:46:06 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui calcule coordonnees horizontales
** crd[0] = i, crd[1] = j, compteurs
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_axe_x(t_map *stc)
{
	int		crd[2];
	float	x[2];
	float	y[2];

	crd[0] = 0;
	crd[1] = 0;
	x[0] = 0;
	y[0] = 0;
	x[1] = 0;
	y[1] = 0;
	while (crd[1] < stc->m_hei)
	{
		while (crd[0] < stc->m_len - 1)
		{
			if ((stc->tab[crd[1]][crd[0]] == '0') &&
				(stc->tab[crd[1]][crd[0] + 1] == '0'))
				ft_crd_x_zero(x, y, crd, stc);
			else
				ft_crd_x_nz(x, y, crd, stc);
			crd[0]++;
		}
		crd[0] = 0;
		crd[1]++;
	}
}

/*
** ft qui calcule coordonees verticales
** crd[0] = i, crd[1] = j >> compteurs
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_axe_y(t_map *stc)
{
	int		crd[2];
	float	x[2];
	float	y[2];

	crd[0] = 0;
	crd[1] = 0;
	x[0] = 0;
	y[0] = 0;
	x[1] = 0;
	y[1] = 0;
	while (crd[0] < stc->m_len)
	{
		while (crd[1] < stc->m_hei - 1)
		{
			if ((stc->tab[crd[1]][crd[0]] == '0') &&
				(stc->tab[crd[1] + 1][crd[0]] == '0'))
				ft_crd_y_zero(x, y, crd, stc);
			else
				ft_crd_y_nz(x, y, crd, stc);
			crd[1]++;
		}
		crd[1] = 0;
		crd[0]++;
	}
}

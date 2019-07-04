/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:25:56 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/07 15:55:51 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft cas, point et point suivant avec z = 0, axe x
** crd[0] = i, crd[1] = j, compteurs
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_crd_x_zero(float *x, float *y, int *crd, t_map *stc)
{
	int		i;
	int		j;

	i = crd[0];
	j = crd[1];
	x[0] = ft_coord_x(i, j, stc);
	y[0] = ft_coord_y(i, j, stc);
	x[1] = ft_coord_x(i + 1, j, stc);
	y[1] = ft_coord_y(i + 1, j, stc);
	stc->color = ft_color((float)stc->tab[j][i], stc);
	ft_segment(x, y, stc);
}

/*
** ft cas, point ou point2 avec z != 0, axe x
** crd[0] = i, crd[1] = j, compteurs
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_crd_x_nz(float *x, float *y, int *crd, t_map *stc)
{
	int		i;
	int		j;

	i = crd[0];
	j = crd[1];
	x[0] = ft_coord_x(i, j, stc);
	y[0] = ft_coord_z(i, j, (float)stc->tab[j][i], stc);
	x[1] = ft_coord_x(i + 1, j, stc);
	y[1] = ft_coord_z(i + 1, j, (float)stc->tab[j][i + 1], stc);
	if ((float)stc->tab[j][i + 1] > (float)stc->tab[j][i])
		stc->color = ft_color((float)stc->tab[j][i + 1], stc);
	else
		stc->color = ft_color((float)stc->tab[j][i], stc);
	ft_segment(x, y, stc);
}

/*
** ft cas, point et point2 avec z = 0, axe y
** crd[0] = i, crd[1] = j, compteurs
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_crd_y_zero(float *x, float *y, int *crd, t_map *stc)
{
	int		i;
	int		j;

	i = crd[0];
	j = crd[1];
	x[0] = ft_coord_x(i, j, stc);
	y[0] = ft_coord_y(i, j, stc);
	x[1] = ft_coord_x(i, j + 1, stc);
	y[1] = ft_coord_y(i, j + 1, stc);
	stc->color = ft_color((float)stc->tab[j][i], stc);
	ft_segment(x, y, stc);
}

/*
** ft cas, point ou point2 avec z != 0, axe y
** crd[0] = i, crd[1] = j, compteurs
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_crd_y_nz(float *x, float *y, int *crd, t_map *stc)
{
	int		i;
	int		j;

	i = crd[0];
	j = crd[1];
	x[0] = ft_coord_x(i, j, stc);
	y[0] = ft_coord_z(i, j, (float)stc->tab[j][i], stc);
	x[1] = ft_coord_x(i, j + 1, stc);
	y[1] = ft_coord_z(i, j + 1, (float)stc->tab[j + 1][i], stc);
	if ((float)stc->tab[j + 1][i] > (float)stc->tab[j][i])
		stc->color = ft_color((float)stc->tab[j + 1][i], stc);
	else
		stc->color = ft_color((float)stc->tab[j][i], stc);
	ft_segment(x, y, stc);
}

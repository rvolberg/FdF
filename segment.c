/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:45:49 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 13:18:24 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft segment valeur absolue de x > valeur absolue de y
** crd[0] = x, crd[1] = y >> valeur de copie du (x,y)
** du premier point.
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_seg_b(float *d, float *inc, float *crd, t_map *stc)
{
	int		i;
	float	cumul;

	i = 1;
	cumul = d[0] / 2;
	while (i <= d[0])
	{
		crd[0] += inc[0];
		cumul += d[1];
		if (cumul >= d[0])
		{
			cumul -= d[0];
			crd[1] += inc[1];
		}
		ft_print_pixel(crd[0], crd[1], stc, stc->color);
		i++;
	}
}

/*
** ft segment valeur absolue de y > valeur absolue de x
** crd[0] = x, crd[1] = y >> valeur de copie du (x,y)
** du premier point.
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_seg_c(float *d, float *inc, float *crd, t_map *stc)
{
	int		i;
	float	cumul;

	i = 1;
	cumul = d[1] / 2;
	while (i <= d[1])
	{
		crd[1] += inc[1];
		cumul += d[0];
		if (cumul >= d[1])
		{
			cumul -= d[1];
			crd[0] += inc[0];
		}
		ft_print_pixel(crd[0], crd[1], stc, stc->color);
		i++;
	}
}

/*
** ft qui dessine les ligne entre les points
** crd[0] = x, crd[1] = y >> valeur de copie du (x,y)
** du premier point.
** x[0] et y[0] = coordonnees du premier point (x,y)
** x[1] et y[1] = coordonnees du deuxieme point (x,y)
*/

void		ft_segment(float *x, float *y, t_map *stc)
{
	float	d[2];
	float	inc[2];
	float	crd[2];

	crd[0] = x[0];
	crd[1] = y[0];
	d[0] = x[1] - x[0];
	d[1] = y[1] - y[0];
	inc[0] = (d[0] > 0) ? 1 : -1;
	inc[1] = (d[1] > 0) ? 1 : -1;
	d[0] = fabsf(d[0]);
	d[1] = fabsf(d[1]);
	ft_print_pixel(crd[0], crd[1], stc, stc->color);
	if (d[0] > d[1])
		ft_seg_b(d, inc, crd, stc);
	else
		ft_seg_c(d, inc, crd, stc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:23:03 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/22 18:05:39 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui cree et rempli struct map
*/

t_map			*ft_struct_map(void)
{
	t_map		*map_data;

	map_data = NULL;
	if (!(map_data = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map_data->map = NULL;
	map_data->m_len = 0;
	map_data->m_hei = 0;
	map_data->d_len = 1800;
	map_data->d_hei = 1300;
	map_data->w_len = 1800;
	map_data->w_hei = 1300;
	map_data->t_len = 10;
	map_data->t_hei = 10;
	map_data->mlx = NULL;
	map_data->win = NULL;
	map_data->img = NULL;
	map_data->data = 0;
	map_data->color = 0x86C74C;
	map_data->xm = 0;
	map_data->ym = 0;
	map_data->tab = NULL;
	map_data->next = NULL;
	return (map_data);
}

/*
** ft qui recupere la map ds un char *
** attention free line, free map si mauvais fd.
*/

t_map			*ft_get_map(int fd)
{
	char		*line;
	t_map		*stc;
	int			i;

	i = 0;
	stc = ft_struct_map();
	stc->map = ft_memalloc(1);
	while ((i = get_next_line(fd, &line)))
	{
		if ((ft_parsing_by_line(line, stc)) == -1)
			return (NULL);
		stc->map = ft_strjoin_free(stc->map, line);
		ft_strdel(&line);
		stc->map = ft_back_n(stc->map);
	}
	if ((ft_parsing_by_map(stc)) == -1)
		return (NULL);
	stc = ft_map_size(stc);
	stc->tab = ft_map_to_tab(stc);
	return (stc);
}

/*
** ft qui compte la largeur et la hauteur et stock ds structure
*/

t_map			*ft_map_size(t_map *stc)
{
	float		crd[2];
	int			i;

	i = 0;
	crd[0] = 0;
	crd[1] = 0;
	while (stc->map[i] != '\n')
	{
		if (stc->map[i] >= '0' && stc->map[i] <= '9')
		{
			if (!(stc->map[i + 1] >= '0' && stc->map[i + 1] <= '9'))
				crd[0]++;
		}
		i++;
	}
	i = 0;
	while (stc->map[i] != '\0')
	{
		if (stc->map[i] == '\n')
			crd[1]++;
		i++;
	}
	stc->m_len = crd[0];
	stc->m_hei = crd[1];
	return (stc);
}

/*
** ft qui adapte char** pour remplir int** tab
*/

char			**ft_str_adaptor(t_map *stc)
{
	int			i;
	char		**mtab;

	i = 0;
	while (stc->map[i] != '\0')
	{
		if (stc->map[i] == '\n')
			stc->map[i] = ' ';
		i++;
	}
	mtab = ft_strsplit(stc->map, ' ');
	return (mtab);
}

/*
** ft qui rempli le tab int** avec les valeurs z de chaque point
** crd[0] et crd[1] sont des compteurs, crd[0] = i, crd[1] = j
** crd[2] est l'index
*/

int				**ft_map_to_tab(t_map *stc)
{
	int			crd[3];
	char		**map;
	int			**tab_m;

	crd[0] = 0;
	crd[1] = 0;
	crd[2] = 0;
	map = ft_str_adaptor(stc);
	if (!(tab_m = (int**)malloc(sizeof(int*) * ((int)stc->m_hei))))
		return (NULL);
	while (crd[1] < stc->m_hei)
	{
		if (!(tab_m[crd[1]] = (int*)malloc(sizeof(int) * ((int)stc->m_len))))
			return (NULL);
		while (crd[0] < stc->m_len)
		{
			tab_m[crd[1]][crd[0]] = ft_atoi(map[crd[2]]);
			crd[0]++;
			crd[2]++;
		}
		crd[0] = 0;
		crd[1]++;
	}
	free_map_tab(map);
	return (tab_m);
}

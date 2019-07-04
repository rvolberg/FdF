/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:59:02 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 12:43:54 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft rajoute le \n pour definir longeur ligne et nombre ligne
*/

char		*ft_back_n(char *map)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(map);
	tmp = ft_strnew(len + 1);
	while (map[i] != '\0')
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = '\n';
	i++;
	tmp[i] = '\0';
	ft_strdel(&map);
	return (tmp);
}

/*
** ft qui compte la longeur de la premiere ligne pour ft suivante
*/

int			ft_first_line_count(char *map)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] == ' ')
		{
			if (map[i + 1] >= '0' && map[i + 1] <= '9')
				len++;
			else if (map[i + 1] == '-')
				len++;
		}
		i++;
	}
	return (len);
}

/*
** ft qui verifie que toute les lignes de map ont la meme longeur
** (check % nombre de ' ')
*/

int			ft_check_len_map(char *map)
{
	int		i;
	int		len;
	int		len1;

	i = 0;
	len = 0;
	len1 = ft_first_line_count(map);
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (len != len1)
				return (-1);
			len = 0;
		}
		else if (map[i] == ' ')
		{
			if (map[i + 1] >= '0' && map[i + 1] <= '9')
				len++;
			else if (map[i + 1] == '-')
				len++;
		}
		i++;
	}
	return (0);
}

/*
** ft verifie emplacement : separe chaque element ds tab
** verifie si charque elem est valide (pas de '-' n'importe ou)
*/

int			ft_check_map(char *map)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tab = NULL;
	if (map != NULL)
	{
		tab = ft_strsplit(map, ' ');
		while (tab[y])
		{
			while (tab[y][x] != '\0')
			{
				if ((tab[y][x] == '-') && (x != 0))
					return (-1);
				x++;
			}
			x = 0;
			y++;
		}
		free_map_tab(tab);
	}
	return (0);
}

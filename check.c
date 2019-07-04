/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:23:44 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 13:24:32 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui regroupe les verifications parsing line par line
*/

int			ft_parsing_by_line(char *line, t_map *stc)
{
	if ((ft_check_char_map(line)) == -1)
	{
		ft_strdel(&stc->map);
		free(stc);
		ft_strdel(&line);
		return (-1);
	}
	else if ((ft_check_map(line)) == -1)
	{
		ft_strdel(&stc->map);
		free(stc);
		ft_strdel(&line);
		ft_putendl_fd("Error 2 : invalid map", 2);
		return (-1);
	}
	return (0);
}

/*
** ft qui regroupe les verifications parsing line par line
*/

int			ft_parsing_by_map(t_map *stc)
{
	if ((ft_check_empty(stc->map)) == -1)
	{
		ft_strdel(&stc->map);
		free(stc);
		return (-1);
	}
	if (ft_check_len_map(stc->map) == -1)
	{
		ft_strdel(&stc->map);
		free(stc);
		ft_putendl_fd("Error 0 : invalid map", 2);
		return (-1);
	}
	return (0);
}

/*
** ft qui verifie les char valides
*/

int			ft_check_char_map(char *map)
{
	int		i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != '\0')
		{
			if (!(map[i] >= '0' && map[i] <= '9'))
			{
				if ((map[i] != ' ') && (map[i] != '\n') && (map[i] != '-'))
				{
					ft_putendl_fd("Error 1 : invalid map", 2);
					return (-1);
				}
			}
			i++;
		}
	}
	return (0);
}

/*
** ft qui verifie si la map est vide ou n a qu un seul point
*/

int			ft_check_empty(char *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		if ((map[i] >= '0') && (map[i] <= '9'))
			j++;
		i++;
	}
	if ((j == 0) || (j == 1))
	{
		ft_putendl_fd("Error 3 : invalid map", 2);
		return (-1);
	}
	return (0);
}

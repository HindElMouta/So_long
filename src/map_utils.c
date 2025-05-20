/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:28:40 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/07 12:28:40 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	is_map_closed(char **map, int width, int height)
{
	int	x; 
    int	y;

	for (x = 0; x < width; x++)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
	}
	for (y = 0; y < height; y++)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_elements(char **map, t_game *game)
{
	int	y = 0, x, p = 0, e = 0, c = 0;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				map[y][x] = '0';
				p++;
			}
			else if (map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				e++;
			}
			else if (map[y][x] == 'C')
				c++;
			else if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '\n' && map[y][x] != '\r')
				error_exit("Carte invalide : caractère inconnu.\n");
			x++;
		}
		y++;
	}
	if (p != 1 || e != 1 || c < 1)
		error_exit("Carte invalide : il faut 1 P, 1 E et au moins 1 C.\n");
	game->collectibles = c;
	ft_putstr("P = ");
	ft_putnbr(p);
	ft_putstr(", E = ");
	ft_putnbr(e);
	ft_putstr(", C = ");
	ft_putnbr(c);
	ft_putstr("\n");
	return (1);
}


int	count_rows(const char *filename)
{
	int		fd;
	int		rows = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Erreur d'ouverture de fichier\n");
	while ((line = get_next_line(fd)))
	{
		rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

int	check_map_validity(char **map, t_game *game)
{
	int	i;
	int	width;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			error_exit("Carte invalide : la carte n'est pas rectangulaire.\n");
		i++;
	}
	game->map_width = width;
	if (!check_elements(map, game))
		error_exit("Carte invalide : mauvais éléments ou caractères inconnus.\n");
	if (!is_map_closed(map, width, i))
		error_exit("Carte invalide : la carte n'est pas fermée.\n");
	if (!is_valid_path(game))
		error_exit("Carte invalide : chemins bloqués vers un item ou la sortie.\n");

	return (1);
}

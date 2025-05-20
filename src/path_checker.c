/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:33:03 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/07 12:33:03 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	i = 0;
	if (!map)
		error_exit("Erreur : map est NULL dans copy_map\n");
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Erreur malloc copy_map\n");
	while (i < height)
	{
		if (!map[i])
			error_exit("Erreur : ligne NULL dans copy_map\n");
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			error_exit("Erreur de duplication de ligne dans copy_map\n");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == '\0')
		return;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	is_valid_path(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;
	int		valid;

	valid = 1;
	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		error_exit("Erreur d'allocation mémoire\n");
	flood_fill(map_copy, game->player_x, game->player_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				valid = 0;
			x++;
		}
		y++;
	}
	free_map(map_copy);
	return (valid);
}


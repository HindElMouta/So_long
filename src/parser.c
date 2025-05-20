/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:10:38 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/07 12:10:38 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(const char *file, t_game *game)
{
	char	**map;

	map = read_map(file, game);
	if (!map)
		error_exit("Erreur : lecture de carte échouée\n");
	game->map = map;
	if (!check_map_validity(map, game))
		error_exit("Erreur : carte invalide\n");
	return (1);
}

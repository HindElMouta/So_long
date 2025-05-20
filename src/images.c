/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:05:03 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/07 11:05:03 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Fonction load_images() :
* Charge les images XPM avec mlx_xpm_file_to_image()
* Affecte chaque sprite à son élément (mur, sol, etc.)
*/

#include "so_long.h"

void	load_images(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &size, &size);
	if (!game->img_wall)
		ft_putstr("Erreur image wall\n");
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &size, &size);
	if (!game->img_floor)
		ft_putstr("Erreur image floor\n");
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &size, &size);
	if (!game->img_player)
		ft_putstr("Erreur image player\n");
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &size, &size);
	if (!game->img_exit)
		ft_putstr("Erreur image exit\n");
	game->img_item = mlx_xpm_file_to_image(game->mlx, "assets/item.xpm", &size, &size);
	if (!game->img_item)
		ft_putstr("Erreur image item\n");
}

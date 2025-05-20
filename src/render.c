/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:26:19 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/05/16 by hinel-mo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int x;
	int	y;
	char tile;

	ft_putstr("Rendering map...\n");
	for (y = 0; y < game->map_height && game->map[y]; y++)
	{
		for (x = 0; x < game->map_width && game->map[y][x]; x++)
		{
			tile = game->map[y][x];
			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
			{
				ft_putstr("Fleur visible à : ");
				ft_putnbr(x);
				ft_putstr(", ");
				ft_putnbr(y);
				ft_putstr("\n");
				mlx_put_image_to_window(game->mlx, game->win, game->img_item, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player,
		game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
	char *moves = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0xFFFFFF, moves);
	free(moves);
	char *col = ft_itoa(game->collectibles);
	mlx_string_put(game->mlx, game->win, 10, 25, 0xFF99CC, "Fleurs restantes: ");
	mlx_string_put(game->mlx, game->win, 160, 25, 0xFF99CC, col);
	free(col);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:27:00 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/05/16 by hinel-mo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Fonctions :
* handle_key() : détecte Z, Q, S, D, ESC
* move_player() : déplace Stitch, ramasse les fleurs (C),
  vérifie la victoire si Stitch atteint Lilo (E)
*/

#include "so_long.h"
#include <stdio.h>

int	handle_key(int keycode, t_game *game)
{
	printf("keycode: %d\n", keycode); // Debug clavier (tu peux le retirer)

	if (keycode == 65307) // ESC
		exit_game(game);
	else if (keycode == 122) // Z
		move_player(game, 0, -1);
	else if (keycode == 115) // S
		move_player(game, 0, 1);
	else if (keycode == 113) // Q
		move_player(game, -1, 0);
	else if (keycode == 100) // D
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int new_x = game->player_x + dx;
	int new_y = game->player_y + dy;
	char tile = game->map[new_y][new_x];

	if (tile == '1')
		return ;

	if (tile == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	render_map(game);
	ft_putstr("Moves: ");
	ft_putnbr(game->move_count);
	ft_putstr("\n");
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
	{
		if (game->collectibles == 0)
		{
			ft_putstr("\033[0;32m🎉 TU AS GAGNÉ !\033[0m\n");
			ft_putstr("\033[0;36mNombre de déplacements : ");
			ft_putnbr(game->move_count);
			ft_putstr("\033[0m\n");
			ft_putstr("\033[0;35m★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆\033[0m\n");
			ft_putstr("\033[0;35m    Bravo ! Stitch a retrouvé Lilo 🌺     \033[0m\n");
			ft_putstr("\033[0;35m★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆\033[0m\n");
			exit_game(game);
		}
		else
		{
			ft_putstr("\033[0;31mTu dois cueillir toutes les fleurs avant de retrouver Lilo !\033[0m\n");
		}
	}
}

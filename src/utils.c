/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:04:35 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/07 11:04:35 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Fonctions :
* ft_putstr() : pour afficher les messages
* ft_putnbr() : pour afficher le compteur de mouvements
* error_exit() : quitte le programme proprement en cas d’erreur
* free_map() : libère la mémoire de la map
* exit_game() : quitte le jeu proprement
*/
#include "so_long.h"

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_map(char **map)
{
	int i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	exit(0);
	return (0);
}

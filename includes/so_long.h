/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:58:27 by marvin            #+#    #+#             */
/*   Updated: 2025/04/07 10:58:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Fichier header (déclarations) :
* Structure t_game
* Constante TILE_SIZE
* Prototypes de fonctions
* Includes nécessaires
*/

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
#include "get_next_line.h"
#include "libft.h"


// Taille des tuiles (pour afficher chaque case)
# define TILE_SIZE 64

// Structure principale du jeu
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		move_count;
	int		collectibles;
	int		exit_x;
	int		exit_y;

	// Sprites
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_item;
}	t_game;

// Fonctions de base
int		load_map(const char *file, t_game *game);
char	**read_map(const char *filename, t_game *game);
int		check_map_validity(char **map, t_game *game);

// Affichage et gameplay
void	render_map(t_game *game);
void	load_images(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		exit_game(t_game *game);

// Parsing / map utils
int		count_rows(const char *filename);
int		check_elements(char **map, t_game *game);
int		is_map_closed(char **map, int width, int height);
int		is_valid_path(t_game *game);
char	**copy_map(char **map, int height);

// Utilitaires
void	error_exit(char *msg);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	free_map(char **map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:58:03 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/07 10:58:03 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		len;
	int		fd;

	if (argc != 2)
		error_exit("Usage: ./so_long <map_file.ber>\n");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		error_exit("Erreur : le fichier doit avoir l'extension .ber\n");
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		error_exit("Erreur : impossible d'ouvrir le fichier\n");
	close(fd);
	load_map(argv[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit("Erreur d'initialisation de MiniLibX\n");
	game.win = mlx_new_window(
			game.mlx,
			game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE,
			"so_long" );
	if (!game.win)
		error_exit("Erreur de création de fenêtre\n");
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	printf("MAP WIDTH = %d, HEIGHT = %d\n", game.map_width, game.map_height);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:03:02 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/05/16 11:03:02 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*clean_line(char *line)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	*res = malloc(ft_strlen(line) + 1);
	if (!res)
		error_exit("Erreur malloc ligne nettoyée\n");
	while (line[i])
	{
		if (line[i] != '\r' && line[i] != '\n')
			res[j++] = line[i];
		i++;
	}
	res[j] = '\0';
	free(line);
	return (*res);
}

char	**read_map(const char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	int		rows;

	i = 0;
	rows = count_rows(filename);
	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		error_exit("Erreur malloc map\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Fichier introuvable\n");
	while (line = get_next_line(fd))
	{
		map[i] = clean_line(line);
		if (i == 0)
			game->map_width = ft_strlen(map[0]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	game->map_height = i;
	return (**map);
}

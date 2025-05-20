/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:20:05 by hinel-mo          #+#    #+#             */
/*   Updated: 2024/11/21 16:38:31 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{	
		write(fd, &s[i], 1);
		i++;
	}
}

/*
int main (void)
{
	char *string = "Chaine de caractere\n";

	ft_putstr_fd(string, 1);
}

*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_split_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:57:17 by rababaya          #+#    #+#             */
/*   Updated: 2025/04/22 13:51:17 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	len_count(char **argv)
{
	int	j;
	int	i;
	int	characters_count;

	j = 0;
	characters_count = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			i++;
			characters_count++;
		}
		j++;
		characters_count++;
	}
	return (characters_count);
}

char	*join(char **argv, int argc)
{
	char	*string;
	int		characters_count;
	int		j;
	int		i;
	int		o;

	characters_count = len_count(argv) + argc - 1;
	string = malloc(characters_count * sizeof(char));
	if (!string)
		return (NULL);
	j = 0;
	o = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
			string[o++] = argv[j][i++];
		string[o++] = ' ';
		j++;
	}
	string[o] = '\0';
	return (string);
}

char	**join_split(char **argv, int argc)
{
	char	**args;
	char	*str;

	if (!**argv)
		return (ft_putstr_fd("Error\n", 2), NULL);
	(str = join(argv, argc));
	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	if (!args)
		return (free(str), NULL);
	return (args);
}

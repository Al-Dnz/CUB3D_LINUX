/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:18:49 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/19 15:39:30 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_bool	cardinal_occurence(char **map)
{
	int	x;
	int	y;
	int	occurence;

	y = 0;
	occurence = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (find_index(map[y][x], "NSEW") > -1)
				occurence++;
			x++;
		}
		y++;
	}
	if (occurence != 1)
		return (0);
	return (1);
}

t_bool	valid_symbol(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (find_index(map[y][x], "012NSEW ") == -1)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		map_validation(char **map, t_state *state)
{
	static t_position	coord = {0.0, 0.0, 0};

	set_player_coord(map, &coord, state);
	state->player_coord.x = coord.x + 0.5;
	state->player_coord.y = coord.y + 0.5;
	state->closed_map = true;
	state->validated_symbol = valid_symbol(map);
	state->initial_position = cardinal_occurence(map);
	if (state->initial_position)
		state->map[(int)coord.y][(int)coord.x] = '0';
	if (state->initial_position)
		map_floodfill(map, (int)coord.x, (int)coord.y, &state->closed_map);
	if (!state->validated_symbol ||
!state->initial_position || !state->closed_map)
		return (0);
	return (1);
}

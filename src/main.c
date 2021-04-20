/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 02:26:23 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/19 15:00:02 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	set_parse_flag(t_state *state)
{
	state->n_line = 0;
	state->resolution_valid = true;
	state->resolution_occur = false;
	state->floor_ceil_valid = true;
	state->texture_valid = true;
	state->char_valid = true;
	state->path_valid = true;
	state->n_arg_valid = true;
	state->no_overflow = true;
	state->validated_symbol = true;
	state->initial_position = true;
	state->closed_map = true;
}

int		main(int argc, char **argv)
{
	char	*path;
	t_state state;

	state.str = NULL;
	state.map = NULL;
	state.tab = NULL;
	state.s.order = NULL;
	state.s.dist = NULL;
	state.s.coord = NULL;
	set_parse_flag(&state);
	init_parser(&state);
	path = argv[1];
	arg_error(argc, argv);
	state.save = false;
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		state.save = true;
	file_parser(&state, path);
	if (!map_validation(state.map, &state))
		exit_parse(&state, 1, "INVALID MAP\n");
	cub_3d(&state);
	return (1);
}

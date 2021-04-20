/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:58:49 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/19 15:46:22 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	strclr(char **str)
{
	free(*str);
	*str = NULL;
}

void	file_descritption_switch(t_state *state)
{
	if (!map_line_authentification(state->str))
		state->n_line++;
	if (find_index(state->tab[0][0], "012RNSWEFC") == -1)
		state->char_valid = false;
	if (ft_strcmp(state->tab[0], "R") == 0)
	{
		set_resolution(state, state->str);
		state->resolution_occur = true;
	}
	if (ft_strcmp(state->tab[0], "NO") == 0)
		set_texture(state, &state->no, state->str);
	if (ft_strcmp(state->tab[0], "SO") == 0)
		set_texture(state, &state->so, state->str);
	if (ft_strcmp(state->tab[0], "EA") == 0)
		set_texture(state, &state->ea, state->str);
	if (ft_strcmp(state->tab[0], "WE") == 0)
		set_texture(state, &state->we, state->str);
	if (ft_strcmp(state->tab[0], "S") == 0)
		set_texture(state, &state->sp, state->str);
	if (ft_strcmp(state->tab[0], "F") == 0)
		set_floor_ceil(state, &state->f, state->str);
	if (ft_strcmp(state->tab[0], "C") == 0)
		set_floor_ceil(state, &state->c, state->str);
}

void	description_checker(t_state *state)
{
	if (!state->resolution_valid || !state->floor_ceil_valid ||
!state->texture_valid || !state->char_valid)
		exit_parse(state, 1, "");
	if ((state->no.checked == false) || (state->so.checked == false)
		|| (state->ea.checked == false) || (state->we.checked == false)
		|| (state->f.checked == false) || (state->c.checked == false)
		|| (state->sp.checked == false) || (state->resolution_occur == false))
	{
		exit_parse(state, 1, "MISSING ELEMENTS IN DESCRIPTON\n");
	}
	if (state->n_line > 8)
		exit_parse(state, 1, "TOO MUCH ELEMENTS IN DESCRIPTON\n");
	if (state->map_width <= 1 || state->map_height <= 1)
		exit_parse(state, 1, "2DMAP IS NOT CORRECTLY SET IN DESCRIPTION\n");
}

void	file_parser(t_state *state, char *path)
{
	int	ret;
	int	count;

	ret = 1;
	count = 0;
	state->fd = open(path, O_RDONLY);
	while (ret != 0)
	{
		ret = get_next_line(state->fd, &state->str);
		state->tab = ft_split(state->str, " ,");
		if (state->tab[0] != NULL)
			file_descritption_switch(state);
		if (map_line_authentification(state->str))
			count++;
		free_tab(state->tab);
		strclr(&state->str);
	}
	close(state->fd);
	if (count > 0)
		map_dimension(state, path);
	if (state->map_width > 1 && state->map_height > 1)
		set_map(state, path);
	description_checker(state);
}

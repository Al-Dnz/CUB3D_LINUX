/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:00:31 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/19 15:03:26 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	set_resolution(t_state *state, char *str)
{
	char **tab;

	tab = NULL;
	if (!check_full_line(str, " 0123456789R"))
	{
		state->char_valid = false;
		state->resolution_valid = false;
		return ;
	}
	if (!check_right_dimension(str, 3))
	{
		state->n_arg_valid = false;
		state->resolution_valid = false;
		return ;
	}
	tab = ft_split(str, " ");
	state->win_width = ft_atoi(tab[1]);
	state->win_height = ft_atoi(tab[2]);
	free_tab(tab);
	if (state->win_width < 10 || state->win_height < 10)
	{
		state->no_overflow = false;
		state->resolution_valid = false;
		return ;
	}
}

int		tab_size(char **tab)
{
	int	n;

	n = 0;
	while (tab[n])
		n++;
	return (n);
}

void	set_floor_ceil(t_state *state, t_overlay *overlay, char *str)
{
	int		n;
	char	**tab;
	char	**tab2;

	tab = ft_split(str, " ,");
	n = tab_size(tab);
	if (n == 2)
	{
		set_texture(state, overlay, str);
		free_tab(tab);
		return ;
	}
	free_tab(tab);
	tab = ft_split(str, " ");
	tab2 = ft_split(tab[1], ",");
	n = tab_size(tab2);
	free_tab(tab);
	free_tab(tab2);
	if (n == 3)
	{
		set_color(state, overlay, str);
		return ;
	}
	state->n_arg_valid = false;
	state->floor_ceil_valid = false;
}

void	set_texture(t_state *state, t_overlay *overlay, char *str)
{
	char	**tab;
	int		fd;

	tab = NULL;
	if (check_right_dimension(str, 2) == 0)
	{
		state->n_arg_valid = false;
		state->texture_valid = false;
		return ;
	}
	tab = ft_split(str, " ");
	fd = open(tab[1], O_RDONLY);
	if (fd < 0)
	{
		free_tab(tab);
		state->path_valid = false;
		state->texture_valid = false;
		return ;
	}
	close(fd);
	if (overlay->address == NULL)
		overlay->address = ft_strdup(tab[1]);
	overlay->type = 1;
	overlay->checked = true;
	free_tab(tab);
}

void	set_color(t_state *state, t_overlay *overlay, char *str)
{
	char **tab;

	tab = NULL;
	if (check_full_line(str, " 0123456789FC,") == 0)
	{
		state->char_valid = false;
		state->floor_ceil_valid = false;
		return ;
	}
	tab = ft_split(str, " ,");
	overlay->r = ft_atoi_special(tab[1]);
	overlay->g = ft_atoi_special(tab[2]);
	overlay->b = ft_atoi_special(tab[3]);
	if ((overlay->r < 0 || overlay->r > 255) || (overlay->g < 0 ||
overlay->g > 255) || (overlay->b < 0 || overlay->b > 255))
	{
		free_tab(tab);
		state->floor_ceil_valid = false;
		return ;
	}
	overlay->type = 0;
	if (overlay->address == NULL)
		overlay->address = ft_strdup("./textures/regular/default.xpm");
	overlay->checked = true;
	free_tab(tab);
}

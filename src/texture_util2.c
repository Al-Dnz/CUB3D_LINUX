/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:36:35 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/20 19:38:23 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		check_texture(t_state *state)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (state->texture[i].mlx_img == NULL)
		{
			ft_putstr_fd("Error\nBAD TEXTURE\n", 1);
			destroy_textures(state);
			destroy_overlay(state);
			mlx_clear_window(state->mlx, state->win);
			mlx_destroy_window(state->mlx, state->win);
			mlx_destroy_display(state->mlx);
			free_map(state->map);
			free(state->mlx);
			exit(1);
		}
		i++;
	}
	return (1);
}

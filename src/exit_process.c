/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:22:53 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/18 22:09:59 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	global_free(t_state *state)
{
	if (state->s.z_buffer != NULL)
		free(state->s.z_buffer);
	if (state->s.order != NULL)
		free(state->s.order);
	if (state->s.dist != NULL)
		free(state->s.dist);
	if (state->s.coord != NULL)
		free(state->s.coord);
	if (state->map != NULL)
		free_map(state->map);
	state->map = NULL;
	free(state->mlx);
	state->mlx = NULL;
}

void	destroy_overlay(t_state *state)
{
	if (state->no.address != NULL)
		ft_strclr(&state->no.address);
	if (state->so.address != NULL)
		ft_strclr(&state->so.address);
	if (state->ea.address != NULL)
		ft_strclr(&state->ea.address);
	if (state->we.address != NULL)
		ft_strclr(&state->we.address);
	if (state->f.address != NULL)
		ft_strclr(&state->f.address);
	if (state->c.address != NULL)
		ft_strclr(&state->c.address);
	if (state->sp.address != NULL)
		ft_strclr(&state->sp.address);
}

void	destroy_images(t_state *state)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (state->texture[i].mlx_img != NULL)
			mlx_destroy_image(state->mlx, state->texture[i++].mlx_img);
	}
	mlx_destroy_image(state->mlx, state->texture[7].mlx_img);
	mlx_destroy_image(state->mlx, state->img.mlx_img);
	mlx_destroy_image(state->mlx, state->img2.mlx_img);
	mlx_clear_window(state->mlx, state->win);
	mlx_destroy_window(state->mlx, state->win);
	mlx_destroy_display(state->mlx);
	free(state->mlx);
	state->mlx = NULL;
}

void	exit_process(t_state *state, t_bool error)
{
	destroy_images(state);
	global_free(state);
	destroy_overlay(state);
	if (error)
		ft_putstr_fd("Error\n", 1);
	else
		ft_putstr_fd("CLEAN_EXIT !\n", 1);
	exit(error);
}

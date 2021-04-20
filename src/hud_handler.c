/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:31:16 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/16 15:36:07 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	draw_life(t_state *state)
{
	int n;

	n = 0;
	while (n++ < state->life)
	{
		draw_heart(state, state->win_width - state->hud_margin
		- (n * state->texture[7].width
		/ state->heart_ratio), state->hud_margin);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:32:04 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/16 15:36:07 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	key_press(int keycode, t_state *state)
{
	if (keycode == FORWARD || keycode == ALT_FORW)
		state->key.forward = true;
	else if (keycode == BACK || keycode == ALT_BACK)
		state->key.back = true;
	else if (keycode == LEFT)
		state->key.left = true;
	else if (keycode == RIGHT)
		state->key.right = true;
	else if (keycode == ROT_LEFT)
		state->key.rot_left = true;
	else if (keycode == ROT_RIGHT)
		state->key.rot_right = true;
	else if (keycode == EXIT)
		exit_process(state, 0);
	return (1);
}

int	key_release(int keycode, t_state *state)
{
	if (keycode == FORWARD || keycode == ALT_FORW)
		state->key.forward = false;
	else if (keycode == BACK || keycode == ALT_BACK)
		state->key.back = false;
	else if (keycode == LEFT)
		state->key.left = false;
	else if (keycode == RIGHT)
		state->key.right = false;
	else if (keycode == ROT_LEFT)
		state->key.rot_left = false;
	else if (keycode == ROT_RIGHT)
		state->key.rot_right = false;
	return (1);
}

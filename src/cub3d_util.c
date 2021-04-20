/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:06:19 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/18 21:09:04 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		check_right_dimension(char *str, int target)
{
	char	**tab;
	int		n;

	tab = NULL;
	n = 0;
	tab = ft_split(str, " ,");
	while (tab[n])
		n++;
	free_tab(tab);
	if (n == target)
		return (1);
	else
		return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab != NULL)
	{
		while (tab[++i] != 0)
			free(tab[i]);
		free(tab[i]);
		free(tab);
		tab = NULL;
	}
}

void	error_description(t_state *state, int fd)
{
	if (state->path_valid == false)
		ft_putstr_fd("A WRONG PATH IS SET SOMEWHERE\n", fd);
	if (state->char_valid == false)
		ft_putstr_fd("A FORBIDDEN CHAR APPEARS SOMEWHERE\n", fd);
	if (state->n_arg_valid == false)
		ft_putstr_fd("NUMBER OF ARG INCORRECT SOMEWHERE\n", fd);
	if (state->no_overflow == false)
		ft_putstr_fd("VALUE IS TOO EXTREME SOMEWHERE\n", fd);
	if (state->validated_symbol == false)
		ft_putstr_fd("INVALID SYMBOL IS SET IN MAP\n", fd);
	if (state->initial_position == false)
		ft_putstr_fd("INITIAL POSITION IS NOT CORRECTLY SET\n", fd);
	if (state->closed_map == false)
		ft_putstr_fd("NON CLOSED MAP\n", fd);
}

void	exit_parse(t_state *state, int fd, char *str)
{
	ft_putstr_fd("Error\n", fd);
	ft_putstr_fd(str, fd);
	if (state->resolution_valid == false)
		ft_putstr_fd("IN RESOLUTION\n", fd);
	if (state->texture_valid == false)
		ft_putstr_fd("IN TEXTURE DESCRIPTION\n", fd);
	if (state->floor_ceil_valid == false)
		ft_putstr_fd("IN FLOOR/CEIL DESCRIPTION\n", fd);
	error_description(state, fd);
	if (state->str != NULL)
		ft_strclr(&state->str);
	if (state->map != NULL)
		free_map(state->map);
	destroy_overlay(state);
	close(state->fd);
	exit(0);
}

int		check_full_line(char *str, char *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (find_index(str[i], set) == -1)
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:05:34 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/19 14:05:41 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		display_all_meals_ate(t_data *data)
{
	char			*time;
	char			*dot;
	unsigned int	current_time;

	current_time = get_time(data->t_start_usec, data->t_start_sec);
	dot = ".......";
	time = ft_utoa(current_time);
	write(1, dot, ft_strlen(dot) - len_nb(current_time));
	write(1, time, ft_strlen(time));
	free(time);
	write(1, "   ", 3);
	write(1, "all the meals ate\n\n", 19);
}

void		display_manager(t_stock *s, t_philo *philo, char *event)
{
	char			*time;
	char			*id;
	char			*dot;
	char			*str;
	unsigned int	current_time;

	str = NULL;
	current_time = get_time(s->data->t_start_usec, s->data->t_start_sec);
	dot = ".......";
	time = ft_utoa(current_time);
	id = ft_utoa(philo->id);
	str = strndup(dot, ft_strlen(dot) - len_nb(current_time));
	str = ft_strjoindel(str, time, 3);
	str = ft_strjoindel(str, " ", 1);
	str = ft_strjoindel(str, id, 3);
	str = ft_strjoindel(str, " ", 1);
	str = ft_strjoindel(str, event, 1);
	str = ft_strjoindel(str, "\n", 1);
	write(1, str, ft_strlen(str));
	free(str);
}

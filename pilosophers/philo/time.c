/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:47:07 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/19 12:40:30 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	time_log(t_philo *philo, size_t id, char action)
{
	char	*str;
	long	elapsed_time;

	pthread_mutex_lock(&philo->print_lock);
	elapsed_time = get_time_in_ms() - philo->start_time;
	if (action == 't')
		str = "is thinking";
	else if (action == 'f')
		str = "has taken a fork";
	else if (action == 'e')
		str = "is eating";
	else if (action == 's')
		str = "is sleeping";
	else if (action == 'd')
		str = "died";
	else if (action == 'X')
		str = "putting down to table";
	else
		str = "died";
	printf("%ld %zu %s\n", elapsed_time, id + 1, str);
	pthread_mutex_unlock(&philo->print_lock);
}

// Get current time in milliseconds
time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// Calculate time elapsed since last meal in milliseconds
time_t	time_since_last_meal(t_philo *philo, size_t i)
{
	return (get_time_in_ms() - philo->phil[i].last_meal_time);
}

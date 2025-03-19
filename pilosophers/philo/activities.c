/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:52:58 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/19 14:00:47 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// function that makes sure that the programm
// exits and frees everything
int	endtimes(size_t i, t_philo *philo)
{
	time_log(philo, i, 'd');
	pthread_mutex_lock(&philo->exit_lock);
	// mutexes_unlocker(philo);
	mutex_cleanup(philo, philo->n_philo);
	i = 0;
	while (i < philo->n_philo)
	{
		free(philo->phil[i].threads);
		i++;
	}
	free(philo->phil);
	pthread_mutex_unlock(&philo->exit_lock);
	return (EXIT_SUCCESS);
}

// no mutex locks because multiple need to sleep
void	send_to_sleep(size_t i, t_philo *philo)
{
	time_log(philo, i, 's');
	philo->phil[i].state = IS_SLEEPING;
	sleep_own(i, philo, 's');
}

// unlocks the mutexes so that the next philosophers can continue in the next round with eating
void	put_forks(size_t i, t_philo *philo)
{
	time_log(philo, i, 'X');
	pthread_mutex_unlock(&philo->chop_sticks[philo->phil[i].left_chop]);
	pthread_mutex_unlock(&philo->chop_sticks[philo->phil[i].right_chop]);
}

// no mutex accept for print mutex which is neceassary for stdout
void	eat(size_t i, t_philo *philo)
{
	philo->phil[i].last_meal_time = get_time_in_ms();
	time_log(philo, i, 'e');
	sleep_own(i, philo, 'e');
}

// no mutex locks becasue multiple need to eat
int	attend_to_eat(t_philo *philo, size_t i)
{
	pthread_mutex_lock(&philo->chop_sticks[philo->phil[i].left_chop]);
	pthread_mutex_lock(&philo->chop_sticks[philo->phil[i].right_chop]);
	time_log(philo,i,'f');
	eat(i, philo);
	put_forks(i, philo);
	sleep_own(i,philo,'s');
	return (EXIT_SUCCESS);
}

// Check for starvation - this should ideally be done by a monitor thread
// or before any action that might take time
void	think(size_t i, t_philo *philo)
{
	philo->phil[i].state = IS_THINKING;
	time_log(philo, i, 't');
}

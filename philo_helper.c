#include "philo.h"

void eating2(t_table *table, int philo_id)
{
    pthread_mutex_lock(&table->philo[philo_id].philo_eating_mutex);
	table->philo[philo_id].last_eat_time = current_time();
	table->philo[philo_id].meal_count++;
	pthread_mutex_unlock(&table->philo[philo_id].philo_eating_mutex);
}

int are_philos_full (t_table *table, int *flag)
{
    if (*flag == 1)
    {
        pthread_mutex_lock(&table->die_check_mutex);
        table->die_check_flag = 1;
        pthread_mutex_unlock(&table->die_check_mutex);
        return (1);
    }
    return (0);
}


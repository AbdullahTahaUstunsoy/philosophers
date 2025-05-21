#include "philo.h"

void clear(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->number_of_philosophers)
        pthread_join(table->philo[i].philosopher, NULL);
    i = -1;
    while(++i < table->number_of_philosophers)
        pthread_mutex_destroy(&table->forks[i]);
    i = -1;
    while(++i < table->number_of_philosophers)
        pthread_mutex_destroy(&table->philo[i].philo_eating_mutex);
    pthread_mutex_destroy(&table->write_text);
    pthread_mutex_destroy(&table->die_check_mutex);
    free(table->philo);
    free(table->forks);
    free(table);
}
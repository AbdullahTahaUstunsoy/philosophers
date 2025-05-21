#include "philo.h"


long long current_time(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    long long milliseconds = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
    return (milliseconds);
}
long long time_difference(long long sim_start_time, long long current_time)
{
    return (current_time - sim_start_time);
}

void time_to_die_check(t_philo *philo, long last_eat_time, long long current_time, long long time_to_die)
{
    if (current_time - last_eat_time > time_to_die)
    {
        pthread_mutex_lock(&philo->table->die_check_mutex);
        philo->table->die_check_flag = 1;
        pthread_mutex_unlock(&philo->table->die_check_mutex);
    }
}

void wait (t_table *table, int time_to_x)
{
    long long start_time;
    int should_continue;

    start_time = current_time ();
    should_continue = 1;
    while (should_continue)
    {
        pthread_mutex_lock(&table->die_check_mutex);
        should_continue = !table->die_check_flag;
        pthread_mutex_unlock(&table->die_check_mutex);
        if (!should_continue)
            break;
        if ((long long)time_to_x <= (current_time() - start_time))
            break;
        usleep(50);
    }
}

void wait2(long time)
{
    long long start_time;

    start_time = current_time();
    while (1)
    {
        if ((long long)time <= (current_time() - start_time))
            break;
        usleep(50);
    }
}
//Jay Pandit
#include "lab7.h"

void get_stats(driver_t driver_list[NRACERS],stats_t *race_stats)
{
        int i=0, j=0;
        double racer_best_time, racer_slowest_time, total_best_time;
        double winning_time, slowest_time;

        total_best_time = 0;

        while( i < NRACERS)
        {
          
           while(j < TRIES)
           {
              if (driver_list[i].d_tries[j] < racer_best_time)
                 racer_best_time = driver_list[i].d_tries[j];
                                                                           
              if (driver_list[i].d_tries[j] > racer_slowest_time)
                 racer_slowest_time = driver_list[i].d_tries[j];
                 
              j++;
           }
           
           j=0;

          /* best player */
           total_best_time += racer_best_time;
           driver_list[i].d_best_time = racer_best_time;
        
           /* best winning time */
           if (racer_best_time < winning_time)
              winning_time = racer_best_time;

             /* slowest time*/
           if (racer_slowest_time > slowest_time)
                slowest_time = racer_slowest_time;
                
           i++;
         }

   
    race_stats->average_of_best = total_best_time / NRACERS;
    race_stats->winning_time = winning_time;
    race_stats->slowest_time = slowest_time;

    for (i = 0; i < NRACERS; i++)
      driver_list[i].deviation = (race_stats->winning_time) - (driver_list[i].d_best_time);
}








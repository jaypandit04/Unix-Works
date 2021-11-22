// Jay Pandit

#include "lab7.h"

/* ---------------------------------------------------    */
/* ---------------------------------------------------    */
void get_median(driver_t driver_list[NRACERS],stats_t *race_stats)
{
    int mid_index;
    
     mid_index = NRACERS / 2;

    if(NRACERS % 2 != 0)
       race_stats = driver_list[mid_index].d_best_time;
    else
      race_stats= (driver_list[mid_index].d_best_time + driver_list[mid_index - 1].d_best_time) / 2;
}


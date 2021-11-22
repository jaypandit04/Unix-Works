/*  Jay Pandit               */
/*  lab 7  Structs           */

#include <stdio.h>
#include <stdlib.h>


#define OUT_FILENAME "lab7.txt"
#define TRIES 3

//#define IN_FILENAME "lab7.dat"
#define IN_FILENAME "lab7sample.dat"

//The final data file has a length of 10, sample file has a length of 4.
//#define NRACERS 10	
#define NRACERS 4


/*-----------------------------------------------------------*/
/* Structure Section */

	// Put your two structures here as in the directions.
   typedef struct 
   {
      char d_name[21];
      double d_tries[TRIES];
      double d_best_time;
      double deviation;
   }driver_t;

   typedef struct 
   {
        double average_of_best;
        double winning_time;
        double slowest_time;
        double median;
   }stat_t;

/*-----------------------------------------------------------*/
/* Function Prototypes Section */

	/* get_data is a function to get and read data         */
void get_data (char *filename,                   /* input  */ 
	       driver_t driver_list[NRACERS] );  /* output */

	/* open_out_file is a function to open the output file */
FILE * open_out_file (void);

	/* get_stats is a function to do figure the best time for */
	/* each racer, compute the all-over average of the best   */
	/* times, and find the longest time and the shortest time */
	/* on the track     */
void get_stats(	driver_t driver_list[NRACERS],    /* in & out */
		stats_t *race_stats );            /* in & out */

	/* do_sort is a function to sort the drivers based on     */
	/* their best times                                       */  
void do_sort( driver_t driver_list[NRACERS] ); 

	/*  get_median determines the median or mid value of      */
	/*  the best times.                                       */
void get_median(driver_t driver_list[NRACERS] ,
		stats_t *race_stats ); 
			    
	/*  print_all is a function to print things out.          */
	/*	all of its arguments are input                        */
void print_all(FILE * out_file,
  	       driver_t driver_list[NRACERS] ,
	       stats_t *race_stats ); 
			  
/*-----------------------------------------------------------*/

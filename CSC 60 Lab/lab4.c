/*--------------------------------------------*/
/* Jay Pandit                                 */
/* Lab 4                                      */
/* Figure the area of a parabola using files  */

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE_NAME "lab4.dat"
#define OUT_FILE_NAME "lab4.txt"

int main(void)
{
    double length, depth, area;
    FILE *infile;
    FILE *outfile;
     
    infile = fopen ("lab4.dat","r");
    outfile = fopen ("lab4.txt","w");

    fprintf(outfile, "\nJay Pandit  Lab 4. \n\n");
    fprintf(outfile, "Data on Parabolas \n\n");
    fprintf(outfile, " Length      Depth        Area   \n");
    fprintf(outfile, "--------   ---------   --------- \n");
                               
    while((fscanf(infile,"%lf%lf",&length,&depth))==2)
    {
        area = (2 * length * depth)/3; 

       fprintf(outfile,"%.2f %12.2f %12.3f \n\n",length,depth,area);
    }

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}
/*---------------------------------------------------*/

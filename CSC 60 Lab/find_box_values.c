/* Jay Pandit                     */
/*lab5 calculating volumn and area*/
/*--------------------------------*/

#include "lab5.h"

void find_box_values(FILE *data_out,FILE *data_in,double l,double w,double h,double *vol,double *s_area)
{
  printf("Length    Width     Heigth    Volume     SurfaceArea\n");
  printf("------    -----     ------    ------     -----------\n");
  while((fscanf(data_in,"%lf%lf%lf",&l,&w,&h))==3)
       {
         *vol = l*w*h;
         *s_area = 2*(l*w + w*h + l*h);    
        
         printf("%.2f%12.2f%12.2f%12.2f%12.2f\n\n",l,w,h,*vol,*s_area);
            
       }

       printf("      ");

   return;
}

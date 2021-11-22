/*-----Jay Pandit--------*/
/*--Redirection file-----*/

#include "lab9_10.h"

void Redirection(int argc, char *argv[])
{
  int i,out=0,in=0;
  //loop and loopcounter variables used in for loops
  //variables out and in keep track of location in string
  
  for(i=0;i<argc;i++)
  {
    if(strcmp(argv[i],">")==0)
     {
       
        if(out!=0)
        {
         fprintf(stderr,"Cannot output more than one file-error\n");    
          _exit(EXIT_FAILURE);
        }
        else if(i==0)
        {
         fprintf(stderr,"No command entered,error\n"); 
            _exit(EXIT_FAILURE);    
        }
        out = i;            
     }

     else if(strcmp(argv[i],"<")==0) 
       {
          if(in!=0)
          {   
            fprintf(stderr,"Cannot output more than one file,error\n"); 
            _exit(EXIT_FAILURE);
           } 
           else if(i==0)
           {
             fprintf(stderr,"No command entered,error\n"); 
             _exit(EXIT_FAILURE);              
           }
         in = i;    
       }
   }

   if(out!=0)
   {
      if(argv[out+1]==NULL)
      {
         fprintf(stderr,"There is no file,error\n");
         _exit(EXIT_FAILURE);    
      }
      int fd = open("argv[out+1]",O_RDWR | O_CREAT | O_TRUNC,S_IRUSR | S_IWUSR );
      if (fd == -1)
       {   
         fprintf(stderr,"Error opening file\n");
         _exit(EXIT_FAILURE);
      }

      dup2(fd, 1);
       
      int returnvalue = close(fd);
      if (returnvalue == -1)
       {
           fprintf(stderr,"close file error\n");  
               _exit(EXIT_FAILURE);
        }

      argv[out]=NULL;             
   }
   if(in!=0)
    {
      if(argv[in+1]==NULL)
         {
          fprintf(stderr,"There is no file,error\n");
           _exit(EXIT_FAILURE);
         }
       int fd = open("argv[in+1]",O_RDONLY);
       if (fd == -1)
       {
           
          fprintf(stderr,"Error opening file\n");
          _exit(EXIT_FAILURE);
       }

        dup2(fd, 0);

       int returnvalue = close(fd);
       if(returnvalue == -1)
        {
         fprintf(stderr,"close file error\n");
           _exit(EXIT_FAILURE);
        }

        argv[in]=NULL;
     }              
}

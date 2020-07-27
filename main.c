#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int main(void)
{
   int fd;
   int fd2;
   char *line;

   fd = open("test.txt", O_RDONLY);
   while(get_next_line(42, &line))
      {
         printf("%s\n\n", line);
         free(line);
      }
   printf("%s\n\n", line);
   free(line); 
   
    fd2 = open("test.txt", O_RDONLY);
   while(get_next_line(42, &line))
      {
         printf("%s\n\n", line);
         free(line);
      }
   printf("%s\n\n", line);
   free(line); 
   close(fd);
   close(fd2);
   return 0;
}
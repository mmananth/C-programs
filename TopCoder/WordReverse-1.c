#include<stdio.h>
#include<stdlib.h>
main(){
  char* a = malloc(1000);
  fscanf(stdin, "%[^\0\n]", a);
  int x = 0, y;
  while(a[x]!='\0')
  {
    if (a[x]==' ' || a[x]=='\n')
    {
      x++;
    }
    else
    {
      y=x;
      while(a[y]!='\0' && a[y]!=' ' && a[y]!='\n')
      { 
        y++;
      }
      int z=y;
      while(x<y)
      {
        y--;
        char c=a[x];a[x]=a[y];a[y]=c; 
        x++;
      }
      x=z;
    }
  }

  fprintf(stdout,a);
  return 0;
}

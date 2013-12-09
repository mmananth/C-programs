#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*-----------------------------
Program to reverse the order of words in a sentence
-----------------------------*/
void reverse(char *start, char *end)
{
	char temp;
	while(start < end)
	{
		temp=*start;
		*start++ = *end;
		*end-- = temp;
	}
}

int main()
{
FILE *in_file;
int i,j=0,num,count=0;
char line[100],*ch,*cha;

in_file=fopen("input.txt","r");
if(in_file==NULL)
{
	fprintf(stderr, "Error: Unable to open input file 'input.txt'\n");
	exit(0);
}

fgets(line,sizeof(line),in_file);
printf("The first line in the file is: %s\n", line);
num=atoi(line);

for (i=0;i<num; i++)
{
	count=0;
	fgets(line,sizeof(line),in_file);
	cha=line;
	ch=strtok(line," ");
	while(ch != NULL)
	{
		printf("%s\t",ch);
		ch=strtok(NULL," ");
	} 

	while(*ch)
	{
		ch++;
		if(*ch=='\0')
		{
			reverse(cha,ch-1);
		}
		else if(*ch==' ')
		{
			reverse(cha,ch-1);
			cha=ch+1;
		}
	}
	reverse(line,ch-1);
}

printf("The reversed words are: %s\n", ch);

fclose(in_file);
return (0);
}

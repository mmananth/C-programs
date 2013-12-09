#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/*
	FILE *fp;
	char buf[1024];
	fp=fopen(argv[1],"r");
	while(fgets(buf,1024,fp)!=NULL)
		fputs(buf,stdout);
		*/
	FILE *fr,*fw;
	char *buffer;
	char *name;
	int fileLen,length,i;
	fr=fopen(argv[1],"rb");

	fseek(fr,0,SEEK_END);
	fileLen=ftell(fr);
	fseek(fr,0,SEEK_SET);

	length=strlen(argv[1]);
	name=(char *)malloc(length+1);
	strncpy(name,argv[1],length);
	strcat(name,".copy");
	length=strlen(name);
	for(i=0;i<length;i++)
		printf("%c",name[i]);

	fw=fopen(name,"wb");

	buffer=(char *)malloc(fileLen+1);
	fread(buffer,fileLen,1,fr);
	fwrite(buffer,fileLen,1,fw);
	fclose(fr);
	fclose(fw);
}

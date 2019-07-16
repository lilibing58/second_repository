#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
#include <sys/stat.h>

int main(void)
{
	struct stat statfile;
	FILE *fs=NULL,*fa=NULL;
	char file_append[SLEN];
	char file_source[SLEN];
	char open_style[SLEN];
	size_t bytes;
        long lResult=0;
	char *buffer=NULL;
	int srcsize,dessize,append_size;
	puts("Enter name of destination file:");
	gets(file_append);
	puts("Enter open destination file style:");
	gets(open_style);
	if((fa=fopen(file_append,open_style))==NULL)
	{
		fprintf(stderr,"Can not open :%s\n",file_append);
		exit(1);
	}

	puts("Enter name of source file:");
if(gets(file_source) && file_source!='\0' )
{
	puts("Enter open source file style:");
	gets(open_style);
	if(strcmp(file_source,file_append)==0)
	{
		fputs("Can't append itself\n",stderr);
	}
	else if((fs=fopen(file_source,open_style))==NULL)
        {
                fprintf(stderr,"Can not open file_source:%s\n",file_source);
        }
	else
	{
	
	stat(file_source,&statfile);
	srcsize=statfile.st_size;
	stat(file_append,&statfile);
	dessize=statfile.st_size;

	printf("source size::%d\n",srcsize);
	printf("destination size::%d\n",dessize);

	buffer=(char*)malloc(sizeof(char)*srcsize);
	if(buffer==NULL)
	{fputs ("Memory error",stderr); exit (2);}

        lResult=fread(buffer,sizeof(char),srcsize,fs);
	if(lResult != srcsize)
	{fputs ("Reading error",stderr); exit (3);}

       // printf("temp content:%s\n",buffer);
	if(dessize>srcsize)
	{
		fputs("destination file large source file.\n ",stderr);
		exit(4);
	}
	puts("please input your append bytes.");
        if(scanf("%d\n",&append_size)==0)
	{fputs("input not a positive number\n",stderr);exit(5);}
	printf("appendsize:%d\n",append_size);
	printf("appendsize/srcsize:%d\n",append_size/srcsize);
        for(int i=0;i<append_size/srcsize;i++)
        {	fwrite(buffer,sizeof(char),srcsize,fa);
		if(append_size%srcsize>0)
		{
			fwrite(buffer,sizeof(char),append_size%srcsize,fa);
		}	
	}
		fclose(fs);
		free(buffer);
		puts("appended: ok");
	}
}
	fclose(fa);
	return 0;
}



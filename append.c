#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 10
#define SLEN 81
#include <sys/stat.h>
void append(FILE *source,FILE *dest);

int main(void)
{
	FILE *fs=NULL,*fa=NULL;
	char file_append[SLEN];
	char file_source[SLEN];
	puts("Enter name of destination file:");
	gets(file_append);
	if((fa=fopen(file_append,"a"))==NULL)
	{
		fprintf(stderr,"Can not open :%s\n",file_append);
		exit(2);
	}
	if((setvbuf(fa,NULL,_IOFBF,BUFSIZE))!=0)
	{
		fputs("can't",stderr);
		exit(3);
	}
	puts("Enter name of source file:");
	if(gets(file_source) && file_source!='\0' )
{
	if(strcmp(file_source,file_append)==0)
	{
		fputs("Can't append itself\n",stderr);
	}
	else if((fs=fopen(file_source,"r"))==NULL)
        {
                fprintf(stderr,"Can not open file_source:%s\n",file_source);
        }
	else
	{
		 if((setvbuf(fs,NULL,_IOFBF,BUFSIZE))!=0)
	        {
                fputs("can't",stderr);
		exit(3);
	        }
		append(fs,fa);
		fclose(fs);
		puts("append ...");
	}
}
	fclose(fa);
	return 0;
	
}

void append(FILE *source,FILE *dest)
{
	size_t bytes;
	long i=0;
	static char temp[BUFSIZE];
//	fseek(source,0L,SEEK_END);
//	long size=ftell(source);
//	char *ar=(char *)malloc(sizeof(char)*size);
//	for(int COUNT=0;COUNT<4;COUNT++)
//	{

//		printf("COUNT:%d\n",COUNT);
//		for(i=0;i<size;i++)
//		{
		while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
		//printf("bytes:%ld\n",bytes); 
		fwrite(temp,sizeof(char),BUFSIZE,dest);
//		printf("size:%ld\n",size);
//		}

//	while((fgets(temp,size,source)))
//	fputs(temp,dest);			

//	}
//	free(ar);
}

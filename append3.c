#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
#include <sys/stat.h>

int main(int argc,char *argv[])
{
        struct stat statfile;
        FILE *fs=NULL,*fo=NULL;
        char file_append[SLEN];
        char file_source[SLEN];
        char open_style[SLEN];
        size_t bytes;
        long lResult=0;
        char *buffer=NULL;
        int srcsize,dessize,append_size;
	if(argc!=7)
	{
		printf("Use:%s [-f sourcefile -o outputfile -b appendchar]\n",argv[0]);
		return 1;
	}
    if(strcmp(argv[1],"-f")!=0)
	 {
		fputs("Wrong option(suggest: -f)\n",stderr);
		exit(1);
	 }
	if((fs=fopen(argv[2],"rb"))==NULL)
	{
			fprintf(stderr,"Can not open :%s\n",argv[2]);
			fclose(fs);
			exit(2);
	}
	if(strcmp(argv[3],"-o")!=0)
	{
		fputs("Wrong option(suggest: -o)\n",stderr);
		exit(3);
	}
	if((fo=fopen(argv[4],"ab"))==NULL)
	{
			fprintf(stderr,"Can not open :%s\n",argv[4]);
			fclose(fo);
			exit(4);
	}	
	if(strcmp(argv[2],argv[4])==0)
	{
		fputs("Can't append itself\n",stderr);
		exit(5);
	}
	if(strcmp(argv[5],"-b")!=0)
	{
		fputs("Wrong option(suggest: -b)\n",stderr);
		exit(6);
	}
	buffer=(char*)malloc(sizeof(char)*10);
	if(buffer==NULL)
	{fputs ("Memory error",stderr); exit (7);}
	strcpy(buffer,argv[6]);
	printf("buffer:%s\n",buffer);
	// lResult=fread(buffer,sizeof(char),srcsize,argv[6]);
	// if(lResult != srcsize)
	// {fputs ("Reading error",stderr); exit (8);}
	fwrite(buffer,sizeof(char),10,fo);
	fclose(fs);
	free(buffer);
/* 	else
	{
		stat(argv[2],&statfile);
		srcsize=statfile.st_size;
		stat(argv[4],&statfile);
		dessize=statfile.st_size;
		
		printf("source size::%d\n",srcsize);
		printf("destination size::%d\n",dessize);

		buffer=(char*)malloc(sizeof(char)*srcsize);
		if(buffer==NULL)
		{fputs ("Memory error",stderr); exit (6);}

		lResult=fread(buffer,sizeof(char),srcsize,fs);
		if(lResult != srcsize)
		{fputs ("Reading error",stderr); exit (7);}

		if(dessize>srcsize)
		{
				fputs("destination file large source file.\n ",stderr);
				exit(8);
		}
		puts(" append bytes.");
		if(scanf("%d\n",&append_size)==0)
		{fputs("input not a positive number\n",stderr);exit(9);}
		printf("appendsize:%d\n",append_size);
		printf("appendsize/srcsize:%d\n",append_size/srcsize);
		for(int i=0;i<append_size/srcsize;i++)
		{       fwrite(buffer,sizeof(char),srcsize,fo);
				if(append_size%srcsize>0)
				{
						fwrite(buffer,sizeof(char),append_size%srcsize,fo);
				}
		}
		fclose(fs);
		free(buffer);
		puts("appended: ok");
	} */
			

 

        

        fclose(fo);
        return 0;
}




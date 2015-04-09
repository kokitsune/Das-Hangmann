#include <stdio.h>
#include <string.h>

int main()
{
	int i=0,j=0;
	char current[101]="";
	char input_save[101]="";
	int tnum=1, vocnum=1, tto=0, vocto[11]={0};
	char vocab[11][51][51]={""};
	char hint[11][51][101]={""};
	char title[11][51]={""};
	char desc[11][101]={""};
	char  massive[76500];
	fgets (massive, 51, stdin);
	massive[strcspn(massive, "\n")] = 0;
	strcpy(massive, "+title1+desc1+this+that+this+that+this+that+this+that*title2+desc2+this+that+this+that+this+that+this+that+this+that*title3+desc3+this+that**");
	while(!(massive[i]=='*'&&massive[i+1]=='*'))/*Get Title*/
	{
		strcpy(current, "");
		for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+')); i++)/*Title*/
		{
			current[strlen(current)]=massive[i];printf("ding!1\n");
		}
		current[101]='\0';printf("%s\n",current);
		strcpy(title[tnum], current);
		memset(current,0,strlen(current));
		for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+')); i++)/*Description*/
		{
			current[strlen(current)]=massive[i];printf("ding!2\n");
		}
		current[101]='\0';printf("%s\n",current);
		strcpy(desc[tnum], current);
		memset(current,0,strlen(current));
		while(massive[i]!='*'){
			for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+')); i++)/*Vocab*/
			{
				current[strlen(current)]=massive[i];printf("ding!3\n");
			}
			current[101]='\0';printf("%s\n",current);
			strcpy(vocab[tnum][vocnum], current);
			memset(current,0,strlen(current));
			for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+') || (massive[i]=='*')); i++)/*Hint*/
			{
				current[strlen(current)]=massive[i];printf("ding!4\n");
			}
			current[101]='\0';printf("%s\n",current);
			strcpy(hint[tnum][vocnum], current);
			memset(current,0,strlen(current));
			vocto[tnum]++;
			vocnum++;}
		vocnum=1;
		tto++;
		tnum++;
	}
	for(i=1;i<=tto;i++)
	{
		printf("%s\n",title[i]);
		printf("%s\n",desc[i]);
		for(j=1;j<=vocto[i];j++)
		{
			printf("%s",vocab[i][j]);
			printf(" --> %s\n",hint[i][j]);
		}
	}
}

#include <stdio.h>
#include <string.h>

int main()
{
	create();
}
int create()
{
	FILE *txt; 
	char input[101]="";
	char input_save[101]="";
	char massive[76500]="";

	while(1)
	{
		printf("1 = Create New File.\n");
		printf("2 = Load a File.\n");
		printf("3 = Back.\n");
		printf("Command: ");
		fgets (input, 51, stdin);
		input[strcspn(input, "\n")] = 0;
		if(input[0]=='1')/*New File*/
		{
			fgets (input, 51, stdin);
			strcat(input, ".txt");
			txt = fopen(input , "r");
			if (txt==NULL)
				{
					txt = fopen(input , "w");
					printf("%s created successfully.\n", input);
				}
			else
			{
				printf("file already exist do you wish to overwrite and start from scratch.(Y/N): ");
				strcpy(input_save, input);
				strcpy(input,"A");
				while(!(input[0]=='Y' || input[0]=='N'))
				{
					fgets (input, 51, stdin);
					if(input[0]=='Y')
					{
						txt = fopen(input , "w");
						fclose(txt);
						edit(0,massive,input);
					}
					if(input[0]=='N')
					{
						break;
					}
				}
			}
		}
		if(input[0]=='2')/*Load File*/
		{
			printf("Input Filename: ");
			fgets (input, 51, stdin);
			input[strcspn(input, "\n")] = 0;
			strcat(input, ".txt");
			txt = fopen(input , "r");
			if (txt==NULL)
			{
				printf("%s does not exist.\n", input);
			}
			else
			{
				txt = fopen(input , "r");
				printf("%s loaded successfully.\n", input);
				fgets(massive, 76500, (FILE*)txt);
				/*Get data*/
				fclose(txt);
				edit(1, massive,input);
			}	
		}
	
		if(input[0]=='3')/*Back*/
			return 0;
	}
	
}

int edit(int mode, char massive[], char filename[])/*Load and edit things*/ /*Forbid * , + */
{
	int i=0;
	char current[101]="";
	char input_save[101]="";
	int tnum=1, vocnum=1, tto=0, vocto[11]={0};
	char vocab[11][51][51]={""};
	char hint[11][51][101]={""};
	char title[11][51]={""};
	char desc[11][101]={""};
	
	while(mode==1)/*Load things*/
	{
		current[strlen(current)]=massive[i];
		current[501]='\0';
		if(strcmp(current, "+"))
		{
			while(massive[i]!='*'&&massive[i+1]!='*')/*Get Title*/
			{
				strcpy(current, "");
				for(i++;i<strlen(massive) || massive[i]!='+'; i++)/*Title*/
				{
					current[strlen(current)]=massive[i];
				}
				current[501]='\0';
				strcpy(title[tnum], current);
				strcpy(current, "");
				for(i++;i<strlen(massive) || massive[i]!='+'; i++)/*Description*/
				{
					current[strlen(current)]=massive[i];
				}
				current[501]='\0';
				strcpy(desc[tnum], current);
				strcpy(current, "");
				while
					for(i++;i<strlen(massive) || massive[i]!='+'; i++)/*Vocab*/
					{
						current[strlen(current)]=massive[i];
					}
					current[501]='\0';
					strcpy(vocab[tnum][vocnum], current);
					strcpy(current, "");
					for(i++;i<strlen(massive) || massive[i]!='+'; i++)/*Hint*/
					{
						current[strlen(current)]=massive[i];
					}
					current[501]='\0';
					strcpy(hint[tnum][vocnum], current);
					strcpy(current, "");
				
				
			}
		}
		else
		{
			printf("Invalid Files.");
			return 0;
		}
	}
	while(1)
	{
		fgets (current, 51, stdin);
		current[strcspn(current, "\n")] = 0;
		if(strcmp(current, "new")==0);
		{
			while(strcmp(current, "back")!=0)
			{
				printf("Insert Category Name: ");
				fgets (current, 51, stdin);
				current[strcspn(current, "\n")] = 0;
				strcpy(title[tnum], current);
			}
		}
		if(strcmp(current, "edit")==0);
		{
			while(strcmp(current, "back")!=0)
			{
				printf("Type in Category number: ");
				fgets (current, 51, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current, "back"))
				{
					printf("Back.");
				}
				else if(atoi(current)>10 || strlen(title[atoi(current)])==0 || atoi(current)<1)
				{
					printf("That Category does not exist. Please try again.");
				}
				else
				{
					while(strcmp(current, "back")!=0)
					{
						
					}
				}
			}
		}
		if(strcmp(current, "remove")==0);
		{
			while(strcmp(current, "back"))
			{
				printf("Select a Category to remove: ");
				for(i=1;i<=tto;i++)
				{
					printf("%d: %s\n", i,title[i]);
				}
				fgets (current, 51, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current, "back"))
				{
					printf("Back.");
				}
				else if(atoi(current)>10 || strlen(title[atoi(current)])==0 || atoi(current)<1)
				{
					printf("That Category does not exist. Please try again.");
				}
				else
				{
					strcpy(input_save, current);
					while(strcmp(current, "back")!=0)
					{
						printf("Remove this Category(%s) and all of its content?(yes/back): ", title[atoi(current)]);
						if(strcmp(current,"yes")==0)
						{
							printf("Removing...");
							strcpy(title[atoi(input_save)],"");
							for(i=1;i<=vocto[atoi(input_save)];i++)
							{
								strcpy(vocab[atoi(input_save)][i], "");
							}
							printf("Remove Completed.");
						}
					}
				}
			}
		}
		if(strcmp(current, "quit")==0);
		{
			return 0;
		}
	}
}

int in(char string[], char cha[])/*If any character of cha in string, return 1*/ /*Excerpt from Python's in*/
{
	int i=0, j;
	for(i;i<strlen(cha); i++)
	{
		for(j=0;j<strlen(string);j++)
		{
			if(string[j]==cha[i])
			{
				return 1;
			}
		}
	}
	return 0;
}

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
		printf("Welcome to category creation mode.\n");
		printf("Here you can create your own sets of vocabulary to be used in the game\n");
		printf("Bear in mind that games from custom category's highscore will not be kept.\n");
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
					fclose(txt);
					printf("%s created successfully.\n", input);
					edit(0,massive,input);
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
						rintf("%s recreated successfully.\n", input);
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
	int i=0,j=0;
	char current[101]="";
	char input_save[101]="";
	int tnum=1, vocnum=1, tto=0, vocto[11]={0};
	char vocab[11][51][51]={""};
	char hint[11][51][101]={""};
	char title[11][51]={""};
	char desc[11][101]={""};
	char cha[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	if(mode==1)/*Load things*/
	{
		if(massive[0]=='+')
		{
			while(!(massive[i]=='*'&&massive[i+1]=='*'))/*Get Title*/
			{
				strcpy(current, "");
				for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+')); i++)/*Title*/
				{
					current[strlen(current)]=massive[i];
				}
				current[101]='\0';
				strcpy(title[tnum], current);
				memset(current,0,strlen(current));
				for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+')); i++)/*Description*/
				{
					current[strlen(current)]=massive[i];
				}
				current[101]='\0';
				strcpy(desc[tnum], current);
				memset(current,0,strlen(current));
				while(massive[i]!='*'){
					for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+')); i++)/*Vocab*/
					{
						current[strlen(current)]=massive[i];
					}
					current[101]='\0';
					strcpy(vocab[tnum][vocnum], current);
					memset(current,0,strlen(current));
					for(i+=1;!((i>=strlen(massive)) || (massive[i]=='+') || (massive[i]=='*')); i++)/*Hint*/
					{
						current[strlen(current)]=massive[i];
					}
					current[101]='\0';
					strcpy(hint[tnum][vocnum], current);
					memset(current,0,strlen(current));
					vocto[tnum]++;
					vocnum++;}
				vocnum=1;
				tto++;
				tnum++;
			}
		}
		else
		{
			printf("Error - Unrecognised Files.");
			return 0;
		}
		for(i=1;i<=tto;i++)/*Debug Only*//*Remove this when release.*/
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
	while(1)
	{
		printf("*-File Menu-*\n");
		printf("new: Create a New category\n");
		printf("edit: Edit existing category\n");
		printf("remove: Remove a category\n");
		printf("display: Display all existing categories.\n");
		printf("save: Save data into file.\n");
		printf("back: Back to menu.\n");
		fgets (current, 101, stdin);
		current[strcspn(current, "\n")] = 0;
		if(strcmp(current, "new")==0)
		{
			while(strcmp(current, "back")!=0)
			{
				printf("back: return to filemenu\n");
				printf("Insert Category Name: ");
				fgets (current, 51, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current,"back")==0)
				{
					printf("Back.\n");
				}
				else if(strlen(current)!=0)
				{
					for(i=1;i<=10;i++)
					{
						if(strlen(title[i])==0)
						{
							printf("Created new category (%s) on slot %d.\n",current, i);
							strcpy(title[i],current);
							printf("Insert Category Description: ");
							fgets (current, 101, stdin);
							current[strcspn(current, "\n")] = 0;
							strcpy(desc[i],current);
							if(i>tto)
							tto++;
							printf("Creation complete. Once you've created to your heart content, type 'back' and use 'edit' to proceed with vocabulary creation.\n");
							break;
						}
					}
					if(i>10)
					{
						printf("There is no empty slot left. Use edit or remove from the File menu instead.\n");
						break;
					}
				}
				else
				{
					printf("You cannot create a category without any names.\n");
				}
			}
		}
		if(strcmp(current, "edit")==0)
		{
			while(strcmp(current, "back")!=0)
			{
				printf("Type in Category number: ");
				fgets (current, 101, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current, "back"))
				{
					printf("Back.\n");
				}
				else if(atoi(current)>tto  || atoi(current)<1)
				{
					printf("That Category does not exist. Please try again.\n");
				}
				else
				{
					while(strcmp(current, "back")!=0)
					{
						printf("*-Edit Menu-*\n");
						printf("new: Create a New category\n");
						printf("edit: Edit existing category\n");
						printf("remove: Remove a category\n");
						printf("display: Display all existing categories.\n");
						printf("save: Save data into file.\n");
					}
				}
			}
		}
		if(strcmp(current, "remove")==0)
		{
			while(strcmp(current, "back"))
			{
				for(i=1;i<=tto;i++)
				{
					if(strlen(title[i])!=0)
					printf("%d: %s\n", i,title[i]);
					else
					printf("%d: -.EMPTY TITLE.-",i);
				}
				printf("Select a Category to remove: ");
				fgets (current, 51, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current, "back")==0)
				{
					printf("Back.\n");
				}
				else if(atoi(current)>10 || strlen(title[atoi(current)])==0 || atoi(current)<1)
				{
					printf("That Category does not exist. Please try again.\n");
				}
				else
				{
					strcpy(input_save, current);
					while(strcmp(current, "back")!=0)
					{
						printf("Remove this Category(%s) and all of its content?(yes/back): ", title[atoi(current)]);
						fgets (current, 51, stdin);
						current[strcspn(current, "\n")] = 0;
						if(strcmp(current,"yes")==0)
						{
							printf("Removing...\n");
							strcpy(title[atoi(input_save)],"");
							strcpy(desc[atoi(input_save)],"");
							for(i=1;i<=vocto[atoi(input_save)];i++)
							{
								strcpy(vocab[atoi(input_save)][i], "");
								strcpy(hint[atoi(input_save)][i], "");
							}
							if(atoi(input_save)==tto)
							{
								tto--;
							}
							printf("Remove Completed.\n");
							break;
						}
					}
				}
			}
		}
		if(strcmp(current, "display")==0)
		{
			for(i=1;i<=tto;i++)/*Debug Only*//*Remove this when release.*/
			{
				if(strlen(title[i])!=0)
				printf("%d: %s\n",i,title[i]);
				else
				printf("%d -.EMPTY TITLE.-\n",i);
				if(strlen(desc[i])!=0)
				printf("%s\n",desc[i]);
				else
				printf("-.EMPTY DESCRIPTION.-\n");
			}
		}
		if(strcmp(current, "save")==0)
		{
			
		}
		if(strcmp(current, "quit")==0)
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

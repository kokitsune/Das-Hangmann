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
		printf("Welcome to category creation mode.\n\n");
		printf("Here you can create your own sets of vocabulary to be used in the game\n");
		printf("Bear in mind that highscores from custom category will not be kept.\n\n");
		printf("1 = Create New File.\n");
		printf("2 = Load a File.\n");
		printf("3 = Back.\n");
		printf("\nCommand: ");
		fgets (input, 51, stdin);
		input[strcspn(input, "\n")] = 0;
		if(input[0]=='1')/*New File*/
		{
			printf("Input Filename: ");
			fgets (input, 51, stdin);
			input[strcspn(input, "\n")] = 0;
			strcat(input, ".txt");
			txt = fopen(input , "r");
			if (txt==NULL)
				{
					system("cls");
					txt = fopen(input , "w");
					fclose(txt);
					if(txt!=NULL){system("cls");
					printf("%s created successfully.\n", input);
					edit(0,massive,input);}
					else{
						printf("File cannot be created. Check your name and try again.\n");
					}
				}
			else
			{
				strcpy(input_save, input);
				strcpy(input,"A");
				while(!(input[0]=='Y' || input[0]=='N'))
				{
					printf("file already exist do you wish to overwrite and start from scratch.(Y/N): ");
					fgets (input, 51, stdin);
					input[strcspn(input, "\n")] = 0;
					if(input[0]=='Y')
					{
						txt = fopen(input , "w");
						fclose(txt);
						system("cls");
						printf("%s recreated successfully.\n", input_save);
						edit(0,massive,input_save);
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
				system("cls");
				printf("%s does not exist.\n", input);
			}
			else
			{
				system("cls");
				txt = fopen(input , "r");
				system("cls");
				printf("%s loaded successfully.\n", input);
				fgets(massive, 76500, (FILE*)txt);
				/*Get data*/
				fclose(txt);
				edit(1, massive,input);
			}	
		}
	
		if(input[0]=='3')/*Back*/
		{
			system("cls");
			return 0;
		}
	}
	
}

int edit(int mode, char massive[], char filename[])/*Load and edit things*/ /*Forbid * , + */
{
	FILE *txt;
	int i=0,j=0;
	char current[101]="";
	char input_save[101]="", edit_save[101]="";
	int tnum=1, vocnum=1, tto=0, vocto[11]={0};
	char vocab[11][51][51]={""};
	char hint[11][51][101]={""};
	char title[11][51]={""};
	char desc[11][101]={""};
	char cha[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char forbid[]="*+";
	
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
		/*for(i=1;i<=tto;i++)/*Debug Only*//*Remove this when release.*/
		/*{
			printf("%s\n",title[i]);
			printf("%s\n",desc[i]);
			for(j=1;j<=vocto[i];j++)
			{
				printf("%s",vocab[i][j]);
				printf(" --> %s\n",hint[i][j]);
			}
		}*/
	}
	while(1)
	{
		printf("\n*-File Menu-*\n");
		printf("new: Create a New category\n");
		printf("edit: Edit existing category\n");
		printf("remove: Remove a category\n");
		printf("display: Display all existing categories.\n");
		printf("save: Save data into file.\n");
		printf("quit: Back to menu.\n");
		printf("\nCommand: ");
		fgets (current, 101, stdin);
		current[strcspn(current, "\n")] = 0;
		if(strcmp(current, "new")==0)
		{
			system("cls");
			while(strcmp(current, "back")!=0)
			{
				printf("back: return to filemenu\n");
				printf("Insert Category Name(Max 50 character): ");
				fgets (current, 51, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current,"back")==0)
				{
					system("cls");
					printf("Back.\n");
				}
				else if(strlen(current)!=0 && in(current, forbid)!=1)
				{
					for(i=1;i<=10;i++)
					{
						if(strlen(title[i])==0)
						{
							system("cls");
							printf("Created new category (%s) on slot %d.\n",current, i);
							strcpy(title[i],current);
							do{printf("Insert Category Description(Max 100 characters, can be blank, forbid *,+.): ");
							fgets (current, 101, stdin);
							current[strcspn(current, "\n")] = 0;}while(in(current,forbid));
							strcpy(desc[i],current);
							if(i>tto)
							tto++;
							printf("Creation complete. Once you've created to your heart content, type 'back' and use 'edit' to proceed with vocabulary creation.\n");
							break;
						}
					}
					if(i>10)
					{
						system("cls");
						printf("There is no empty slot left. Use edit or remove from the File menu instead.\n");
						break;
					}
				}
				else
				{
					system("cls");
					printf("You cannot create a category without any names.\n");
					printf("And your word cannot include \"*\" or \"+\".\n");
				}
			}
		}
		if(strcmp(current, "edit")==0)
		{
			system("cls");
			while(strcmp(current, "back")!=0)
			{
				for(i=1;i<=tto;i++)
				{
					if(strlen(title[i])==0)
						printf("%d: -.EMPTY.-\n", i);
					else
						printf("%d: %s\n", i, title[i]);
				}
				printf("Type in Category number(#/back): ");
				fgets (current, 101, stdin);
				current[strcspn(current, "\n")] = 0;
				if(strcmp(current, "back")==0)
				{
					system("cls");
					printf("Back.\n");
				}
				else if(atoi(current)>tto  || atoi(current)<1)
				{
					printf("That Category does not exist. Please try again.\n");
				}
				else
				{
					strcpy(input_save,current);
					while(strcmp(current, "back")!=0)
					{
						printf("\n*-Edit Menu-*\n\n");
						printf("Current Category: %d: %s\n",atoi(input_save), title[atoi(input_save)]);
						printf("Description: %s\n\n", desc[atoi(input_save)]);
						printf("title edit: Edit category name.\n");
						printf("desc edit: Edit description.\n");
						printf("new: Create a new vocabulary.\n");
						printf("edit: Edit an existing vocabulary.\n");
						printf("remove: remove a vocabulary.\n");
						printf("display: Display all vocabulary.\n");
						printf("back: Return to File menu.\n");
						printf("\nCommand: ");
						fgets (current, 101, stdin);
						current[strcspn(current, "\n")] = 0;
						if(strcmp(current, "title edit")==0)
						{
							system("cls");
							while(strcmp(current,"back")!=0)
							{
								printf("back : Return to edit menu.\n");
								printf("Rename this category: \n");
								fgets (current, 51, stdin);
								current[strcspn(current, "\n")] = 0;
								if(strcmp(current,"back")==0)
								{
									system("cls");
									strcpy(current,"");
									break;
								}
								if(strlen(current)==0)
								{
									system("cls");
									printf("You may not have a title without any title...\nIf you wish to remove a title please use remove command instead.\n");
								}
								if(in(current,forbid))
								{
									printf("Your word cannot include \"*\" or \"+\".\n");
								}
								else
								{
									strcpy(title[atoi(input_save)], current);
									system("cls");
									printf("Successfully renamed title %d to %s", atoi(input_save), title[atoi(input_save)]);
									break;
								}
							}
						}
						if(strcmp(current, "desc edit")==0)
						{
							while(strcmp(current,"back")!=0)
							{
								printf("back : Return to edit menu.\n");
								printf("Change this category's description(Max 100 characters, can be blank): \n");
								fgets (current, 101, stdin);
								current[strcspn(current, "\n")] = 0;
								if(strcmp(current,"back")==0)
								{
									system("cls");
									strcpy(current,"");
									break;
								}
								else if(in(current, forbid))
								{
									printf("Your word cannot include \"*\" or \"+\".\n");
								}
								else
								{
									strcpy(desc[atoi(input_save)], current);
									system("cls");
									printf("Successfully renamed Description %d to %s", atoi(input_save), desc[atoi(input_save)]);
									break;
								}
							}
						}
						if(strcmp(current, "new")==0)
						{
							system("cls");
							while(strcmp(current,"back")!=0)
							{
								printf("back : Return to edit menu.\n");
								printf("New Vocabulary(Max 50 characters): \n");
								fgets (current, 51, stdin);
								current[strcspn(current, "\n")] = 0;
								if(strcmp(current,"back")==0)
								{
									system("cls");
									strcpy(current,"");
									break;
								}
								if(strlen(current)==0 ||in(current, cha)==0 ||in(current,forbid))
								{
									system("cls");
									printf("You cannot have a Vocabulary without any English letter.\n");
									printf("And your word cannot include \"*\" or \"+\".\n");
									
								}
								else
								{
									for(i=1;i<=50;i++)
									{
										if(strlen(vocab[atoi(input_save)][i])==0)
										{
											system("cls");
											printf("Successfully added \"%s\" into %s\n", current, title[atoi(input_save)]);
											strcpy(vocab[atoi(input_save)][i],current);
											printf("Insert hint(Max 100 characters, can be blank): ");
											fgets (current, 101, stdin);
											current[strcspn(current, "\n")] = 0;
											strcpy(hint[atoi(input_save)][i],current);
											if(i>vocto[atoi(input_save)])
											vocto[atoi(input_save)]++;
											printf("Creation complete. Once you've added to your heart content, type 'back'\n");
											break;
										}
									}
									if(i>50)
									{
										system("cls");
										printf("There is no empty slot left. Use edit or remove from the edit menu instead.\n");
										break;
									}
								}
							}
						}
						if(strcmp(current, "edit")==0)
						{
							system("cls");
							while(strcmp(current, "back")!=0)
							{
								for(i=1;i<=vocto[atoi(input_save)];i++)
								{
									if(strlen(vocab[atoi(input_save)][i])!=0)
									printf("%d: %s\n", i,vocab[atoi(input_save)][i]);
									else
									printf("%d: -.EMPTY VOCAB.-\n",i);
								}
								printf("Type in Vocabulary number: ");
								fgets (current, 101, stdin);
								current[strcspn(current, "\n")] = 0;
								if(strcmp(current, "back")==0)
								{
									system("cls");
									strcpy(current,"");
									printf("Back.\n");
									break;
								}
								else if(atoi(current)>vocto[atoi(input_save)]  || atoi(current)<1)
								{
									printf("That Vocabulary does not exist. Please try again.\n");
								}
								else
								{
									strcpy(edit_save, current);
									while(strcmp(current,"back")!=0)
									{
										printf("back : Return to edit menu.\n");
										printf("Edit Vocabulary(Max 50 characters): \n");
										fgets (current, 51, stdin);
										current[strcspn(current, "\n")] = 0;
										if(strcmp(current,"back")==0)
										{
											system("cls");
											strcpy(current,"");
											break;
										}
										if(strlen(current)==0 ||in(current, cha)==0 ||in(current,forbid)==1)
										{
											system("cls");
											printf("You cannot have a Vocabulary without any English letter.\n");
											printf("And your word cannot include \"*\" or \"+\".\n");
										}
										else
										{
											system("cls");
											strcpy(vocab[atoi(input_save)][atoi(edit_save)], current);
											printf("Changed %d's vocab to %s.\n", atoi(edit_save), current);
											do{
											printf("Edit hint(Max 101 characters, can be blank, forbid *,+.): \n");
											fgets (current, 101, stdin);
											current[strcspn(current, "\n")] = 0;}while(in(current, forbid));
											strcpy(hint[atoi(input_save)][atoi(edit_save)], current);
											strcpy(current,"");
											break;
										}
									}
								}
							}
						}
						if(strcmp(current, "remove")==0)
						{
							system("cls");
							while(strcmp(current, "back")!=0)
							{
								for(i=1;i<=vocto[atoi(input_save)];i++)
								{
									if(strlen(vocab[atoi(input_save)][i])!=0)
									printf("%d: %s\n", i,vocab[atoi(input_save)][i]);
									else
									printf("%d: -.EMPTY VOCAB.-\n",i);
								}
								printf("Select a Vocabulary to remove: ");
								fgets (current, 51, stdin);
								current[strcspn(current, "\n")] = 0;
								if(strcmp(current, "back")==0)
								{
									system("cls");
									strcpy(current,"");
									break;
								}
								else if(atoi(current)>50 || strlen(vocab[atoi(input_save)][atoi(current)])==0 || atoi(current)<1)
								{
									system("cls");
									printf("That Vocabulary does not exist. Please try again.\n");
								}
								else
								{
									system("cls");
									strcpy(edit_save, current);
									while(strcmp(current, "back")!=0)
									{
										printf("Remove this Vocabulary(%s) and all of its hint?(yes/back): ", vocab[atoi(input_save)][atoi(current)]);
										fgets (current, 51, stdin);
										current[strcspn(current, "\n")] = 0;
										if(strcmp(current,"yes")==0)
										{
											printf("Removing...\n");
											strcpy(vocab[atoi(input_save)][atoi(edit_save)],"");
											strcpy(hint[atoi(input_save)][atoi(edit_save)],"");
											if(atoi(edit_save)==vocto[atoi(input_save)])
											{
												vocto[atoi(input_save)]--;
											}
											printf("Remove Completed.\n");
											break;
										}
										strcpy(current,"");
									}
								}
							}
						}
						if(strcmp(current, "display")==0)
						{
							system("cls");
							for(i=1;i<=vocto[atoi(input_save)];i++)
							{
								if(strlen(vocab[atoi(input_save)][i])==0)
									printf("%d: -.EMPTY.-\n", i);
								else
									printf("%d: %s\n", i, vocab[atoi(input_save)][i]);
								if(strlen(hint[atoi(input_save)][i])==0)
									printf("-.EMPTY HINT.-\n");
								else
									printf("%s\n", hint[atoi(input_save)][i]);
							}
						}
						if(strcmp(current, "back")==0)
						{
							system("cls");
							break;
						}
					}
				}
			}
		}
		if(strcmp(current, "remove")==0)
		{
			system("cls");
			while(strcmp(current, "back")!=0)
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
					system("cls");
				}
				else if(atoi(current)>10 || strlen(title[atoi(current)])==0 || atoi(current)<1)
				{
					system("cls");
					printf("That Category does not exist. Please try again.\n");
				}
				else
				{
					system("cls");
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
			system("cls");
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
			system("cls");
			txt = fopen(filename, "w");
			fputs("+", txt);
			for(i=1;i<=tto;i++)
			{
				if(strlen(title[i])==0||vocto[i]==0){}
				else
				{
					fputs(title[i], txt);
					fputs("+", txt);
					fputs(desc[i], txt);
					for(j=1;j<=vocto[i];j++)
					{
						if(strlen(vocab[i][j]))
						{
							fputs("+", txt);
							fputs(vocab[i][j], txt);
							fputs("+", txt);
							fputs(hint[i][j], txt);
						}
					}
					fputs("*", txt);
				}
			}
			fputs("*", txt);
			printf("Data Saved in %s.", filename);
			fclose(txt);
		}
		if(strcmp(current, "quit")==0)
		{
			system("cls");
			printf("Are you sure? Unsaved data will be discard(yes/any): ");
			fgets (current, 51, stdin);
			current[strcspn(current, "\n")] = 0;
			if(strcmp(current,"yes")==0)
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

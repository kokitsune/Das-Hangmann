#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*All function except stated otherwise should be treated as primary objective*/
/*Best of Luck*/
int main()
{
	system("mode 100,45");/*fixed window size*/
	
	while(1){
	printf("                                                           \n");
	printf("        +11O88      1OO       +   8     ++11OO88           \n");
	printf("      ++          +1   88    + 1O8 8   ++                  \n");
	printf("      ++   O88   ++     88  ++  O  88  ++11OO88            \n");
	printf("      ++      8  ++ 1OO 88  ++     88  ++                  \n");
	printf("        +11O88   ++     88  ++     88   ++11OO88           \n\n");
	printf("                     +1O88    ++11OO888                    \n");
	printf("                   ++     88  ++                           \n");
    printf("                   ++     88  ++11O88                      \n");
	printf("                   ++     88  ++                           \n");
	printf("                     +1O88    ++                           \n\n");
	printf("       ++     88     1O8     ++     88    +11O88           \n");
	printf("       ++     88   +1   88   ++ 1   88  ++                 \n");
	printf("       ++11OO888  ++     88  ++  1O 88  ++   O88           \n");
	printf("       ++     88  ++ 1O8 88  ++    O88  ++      8          \n");
	printf("       ++     88  ++     88  ++     88    +11O88           \n");
	printf("\n __________________________________________________________\n\n");
	printf("                   1. Single Player\n");
	printf("                   2. Multiplayer\n");
	printf("                   3. Create Mode\n");
	printf("                   4. Scores\n");
	printf("                   5. Credit\n");
	printf("                   6. Quit\n");
	
	char input[52];
	printf("\nEnter a number 1-6: ");
	fgets (input, 51, stdin);
	input[strcspn(input, "\n")] = 0;
	
	

		if(input[0]=='1')
		{
			clear();
			single();/*Singleplayer*/
		}
		if(input[0]=='2')
		{
			clear();
			multi();/*Multiplayer*/
		}
		if(input[0]=='3')
		{
			clear();
			create();/*Create-a-category*/
		}
		if(input[0]=='4')
		{
			clear();
			score();/*Print scores*/
		}
		if(input[0]=='5')
		{
			credit();/*Print our awesome names*/
		}
		if(input[0]=='6')
		{
			clear();
			return 31337;
		}
		clear();
	}
}

int single()
{
	FILE *txt;
	char massive[76500]="";
	char input[52]="";
	unsigned int i=0;
	unsigned int tnum=1, vocnum=1, tto=0, vocto[11]={0};
	char vocab[11][51][52]={""};
	char hint[11][51][102]={""};
	char title[11][52]={""};
	char desc[11][102]={""};
	
	
	printf("*-Singleplayer Mode-*\n\n");
	printf("Play with pre-created category of vocabs.\n");
	printf("Can you beat the maker of this game?\n");
	printf("Or if someone had used create-a-mode. Perhaps you can try to beat them.\n");
	while(strcmp(input,"q")!=0)
	{
		printf("\nPlease type down filename below to load custom category.\n");
		printf("If left blank, it will load original category for you.\n");
		printf("Type \'q\' to go back to mainmenu.\n");
		printf("\nEnter filename: ");
		fgets (input, 51, stdin);
		input[strcspn(input, "\n")] = 0;
		
		if(strcmp(input,"q")==0)
		{
			clear();
			return 0;
		}
		if(strlen(input)==0)
			strcpy(input, "Official");
		strcat(input, ".txt");
		txt = fopen(input, "r");
		
		fgets(massive, 76500, (FILE*)txt);
		if(massive[0]=='+')
		{
			char current[102]="";
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
			}break;
		}
		else
		{
			clear();
			printf("Error - Unrecognised Files.");
			return 0;
		}
	}
	fclose(txt);/*END OF LOAD*/
	while(1)
	{
		clear();
		for(i=1;i<=tto;i++)
		{
			printf("%d: %s\n", i, title[i]);
			printf("%s\n", desc[i]);
		}
		printf("\nChoose a category(#/q to quit): ");
		fgets (input, 51, stdin);
		input[strcspn(input, "\n")] = 0;
		
		if(input[0]=='q')
		{
			clear();
			return 0;/*Back*/
		}
		if(atoi(input)> tto || atoi(input)<1)
		{
			clear();
			printf("That category does not exist.\n");
		}
		else
		{
			play(title[atoi(input)], vocab[atoi(input)], hint[atoi(input)], desc[atoi(input)], vocto[atoi(input)]);
		}
	}
	
}

int multi()
{
	int score=45,life=0,all=0,j=0,k=0,stat=1;
	char word[51],alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},state[51];
	
	printf("Welcome to Two-player Mode\n");
	printf("Here one player will type a word.\n");
	printf("And the other will guess what it is.\n");
	printf("\n");
	
	while(life<9){
		
		printf("Please insert your word: ");
		fgets (word, 51, stdin);
		word[strcspn(word, "\n")] = 0;
		clear();
			
		
		char now[strlen(word)+1];
		int i=0,check=0,pop=0;
		int myalpha[26]={0}, length;
		length=strlen(word);
		for(i=0;i<strlen(word);i++){
			now[i]='_';
			if (tolower(word[i])<97 || tolower(word[i])>122)
			{
				now[i]=word[i];
				length--;
			}
		}
		char input[3]="";
		stat=1;
		if (count_alpha(word)==0){
			printf("\nYour word must have at least 1 character.\n\n");stat=0;}
		else
		{
			do
			{
				i=0;
							
				for(i;i<strlen(word);i++)
				{
					if(tolower(input[0]) == tolower(word[i]))
					{
						now[i]=input[0];
						check++;
						pop=1;
						clear();
					}	
				}
				if(!pop && strlen(input))
				{
					life++;
					printf("\nWrong. Wrong. WRONG!\n");
					clear();
				}
				pop=0;
				printf("%s",man(life));
				printf("\nCurrently the question is..\n");
					
				i=0;
				if(!(life >=9 ))
				{
					for(i;i<strlen(word);i++)
					{
						if(now[i] == '_')
						{
							printf(" _ ");
						}
						else if (now[i] == ' ')
						{
							printf("   ");
						}
						else /*if (word[i] == '-')*/
						{
							printf("   ");
						}				
					}
					printf("\n");
							
					for(i=0;i<strlen(word);i++)
					{
						if(now[i]== '_')
						{
							printf("|_|");					
						}
						else if (now[i] == ' ')
						{
							printf("   ");
						}
						else
						{
							printf(" %c ",word[i]);
						}
					}
				}
				else
				{
					printf("\n\n");
					for(i=0;i<strlen(word);i++)
					{
						printf(" %c ",word[i]);
					}
				}
				
				printf("\n");
				printf("\n");
				strcpy(input,"");
				if (!(check>=length || life >=9)){
					fgets (input, 3 , stdin);
					input[strcspn(input, "\n")] = 0;
					if(tolower(input[0])>96 && tolower(input[0])<123){
					for(i=0;i<26;i++)
					{
						if(input[0]==alpha[i])
						{
							if(myalpha[i]==1)
							{
								strcpy(input,"");
								printf("\nYou have already used this letter. Please choose again.\n");
							}
							else{
								myalpha[i]=1;
							}
							break;
						}
					}
					}
					else{
						printf("\nYou can only type English alphabets only. Please try again\n");
						strcpy(input, "");
					}
				}
			}while (!(check>=length || life >=9  ));
				if(stat)
				{
					all+=score-(life*5);
					printf("Score %d\n\n",all);
				}
				life=0;
		}
	}
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

int score()/*Secondary Objective*/
{
	/*Score for each category using sort algorithm (qsort should be easiest)*/
	char score[5][52];/*Show only first fifty highest score*/
	FILE *txt;
}

int write_score(char name[], int point)
{
	char score[6][52];
	FILE *txt;
}

int credit()
{
	/*Just print massively*/
	getch();
	return 31337;
}

int play(char title[52], char vocab[51][52], char hint[51][102], char desc[102], int vocto)/*Actually play the singleplayer*/
{
	char input[52]="", current[52]="", message[101]="";
	char word[52]="", cha[]="abcdefghijklmnopqrstuvwxyz";
	int rng=1;/*Random Number God*/
	int i=1,j=0, vocnum=vocto, score=0;
	time_t t;
	srand((unsigned) time(&t));
	
	while(!(strcmp(input,"quit")==0 || vocnum==0))
	{
		int voc_al[vocto+1], cha_al[26]={0} , life=0;
		for(i=0;i<=vocto;i++)
			voc_al[i]=0;
		char alpha[27]=" ";
		
		do{
		rng = rand() % vocto +1;
		}while(voc_al[rng]==1);
		strcpy(word, vocab[rng]);
		voc_al[rng]=1;
		vocnum--;
		
		char mhint[102];
		strcpy(mhint, hint[rng]);
		
		clear();
		/*strcpy(word,"MammmMaaammmMgjfkogjlmMAGJFKOGL");*/
		for(i=0;i<strlen(word);i++)
		{
			if(find(cha, tolower(word[i]))!=-1){
				current[i]='*';
				if(check(tolower(word[i]), alpha)==0)
					alpha[strlen(alpha)]=tolower(word[i]);
			}
			else
				current[i]=word[i];
		}
		current[i]='\0';
		i=1;
		if(strlen(alpha)<2)
			i--;
		if(strlen(alpha)>6)
			i++;
		if(strlen(alpha)>12)
			i++;
		for(i;i>0;i--)
		{
			rng = rand() % (strlen(alpha)-1)+1;
			printf("%c\n", alpha[rng]);
			for(j=0;j<strlen(current);j++)
			{
				if(tolower(word[j])==alpha[rng])
				{
					current[j]=word[j];
				}
			}
			cha_al[find(cha, tolower(alpha[rng]))]=1;
		}
		printf("%s %s\n",current, word);
		printf("%s\n", alpha);
		while(!(strcmp(input, "skip")==0 ||check('*', current)==0 || life==9))
		{
			memset(message, 0, strlen(message));
			/*clear();*/
			printf("+*-Singleplayer.*+\n");
			printf("Current Category: %s\n", title);
			printf("%s\n\n", desc);
			printf("Your current score is: %d\n",score);
			man(life);
			printboxes(current, '*');
			printf("Characters already used: ");
			for(i=0;i<26;i++)
				if(cha_al[i]==1)
					printf(" %c", cha[i]);
			printf("\n%s\n",message);
			printf("\n\nAnswer: ");
			fgets (input, 52, stdin);
			input[strcspn(input, "\n")] = 0;
			for(i=0;i<strlen(input);i++)
			{
				if(life==9||strcmp(input, "quit")==0||check('*', current)==0)
				{
					break;
				}
				if(strcmp(input, "hint")==0)
				{
					strcpy(message, mhint);
					break;
				}
				if((tolower(input[i])<97 || tolower(input[i])>122))
				{
				}
				else if(cha_al[find(cha, input[i])]==1)
				{
					strcpy(message, "You have already used ");
					strcat(message, "\'");
					message[strlen(message)]=input[i];
					message[strlen(message)]='\'';
					message[strlen(message)]='.';
					message[strlen(message)]='\0';
				}
				else
				{
					if(check(tolower(input[i]), word))
					{
						for(j=0;j<strlen(word);j++)
							if(input[i]==tolower(word[j]))
								current[j]=word[j];
						cha_al[find(cha, input[i])]=1;
						score+=5;
					}
					else
					{
						life++;
						man(life);
					}
				}
				clear();
			}
		}
		memset(input, 0, strlen(input));
		if(life==9 || vocnum==0){
			printf("\nGame Over.\n");
			if(vocnum==0)
				printf("Congratulations! You have beaten this entire category.\n");
			printf("Your score is: %d\n", score);
			printf("Type \'r\' to replay.\n");
			printf("Type \'n\' to Proceed to highscore.\n");
			printf("Type \'q\' to quit to category selection.\n");
			while(1){
			fgets (input, 52, stdin);
			input[strcspn(input, "\n")] = 0;
				if(strcmp(input,"r")==0)
				{
					vocnum=vocto;
					break;
				}
				if(strcmp(input,"n")==0)
				{
					printf("Insert your name: ");
					fgets (input, 52, stdin);
					input[strcspn(input, "\n")] = 0;
					write_score(input, score);
					return 0;
				}
				if(strcmp(input,"q")==0)
				{
					return 0;
				}
			}
		}
	}
	
}

int clear()
{
	/*printf("DING DONG\n");*/
	system("cls");
}

int man(int in)
{
		
		if (in == 1)
		{
		 printf("      **\n");
		 printf("      **\n");
		 printf("      **		            \n");
		 printf("      **                            \n");
		 printf("      **		           \n");							
		 printf("      **		             \n");
		 printf("      **		              \n");
		 printf("      **		              \n");
		 printf("      **	                     \n");
		 printf("      **                           \n");
		 printf("      **			 \n");
		 printf("      **	                    \n");
		 printf("      **	                     \n");
		 printf("      **	                  	  \n");
		 printf("      **                            \n");
		 printf("      **                            \n");
		 printf("      **	                  \n");
		 printf("      **	                    \n");
		 printf("      **                        \n");
		 printf("      **                       \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 2)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            \n");
		 printf("      **                            \n");
		 printf("      **		           \n");							
		 printf("      **		            \n");
		 printf("      **		              \n");
		 printf("      **		              \n");
		 printf("      **	                     \n");
		 printf("      **                           \n");
		 printf("      **			 \n");
		 printf("      **	                \n");
		 printf("      **	                    \n");
		 printf("      **	                 	 \n");
		 printf("      **                           \n");
		 printf("      **                           \n");
		 printf("      **	                  \n");
		 printf("      **	                     \n");
		 printf("      **                            \n");
		 printf("      **                              \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 3)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           \n");							
		 printf("      **		         \n");
		 printf("      **		        \n");
		 printf("      **		        \n");
		 printf("      **	                \n");
		 printf("      **                         \n");
		 printf("      **			 \n");
		 printf("      **	                \n");
		 printf("      **	               \n");
		 printf("      **	              \n");
		 printf("      **                          \n");
		 printf("      **                          \n");
		 printf("      **	                 \n");
		 printf("      **	                 \n");
		 printf("      **                     \n");
		 printf("      **                      \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 4)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           ****\n");							
		 printf("      **		         **    **\n");
		 printf("      **		        **      **\n");
		 printf("      **		        **      **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                           ****\n");
		 printf("      **			 \n");
		 printf("      **	                \n");
		 printf("      **	               \n");
		 printf("      **	              \n");
		 printf("      **                           \n");
		 printf("      **                          \n");
		 printf("      **	                 \n");
		 printf("      **	                 \n");
		 printf("      **                        \n");
		 printf("      **                       \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 5)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           ****\n");							
		 printf("      **		         **    **\n");
		 printf("      **		        **      **\n");
		 printf("      **		        **      **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                           ****\n");
		 printf("      **			    **\n");
		 printf("      **	                    **  \n");
		 printf("      **	                    **   \n");
		 printf("      **	                    **	  \n");
		 printf("      **                            **\n");
		 printf("      **                            **\n");
		 printf("      **	                    \n");
		 printf("      **	                    \n");
		 printf("      **                              \n");
		 printf("      **                               \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 6)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           ****\n");							
		 printf("      **		         **    **\n");
		 printf("      **		        **      **\n");
		 printf("      **		        **      **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                           ****\n");
		 printf("      **			 *****\n");
		 printf("      **	                **  **  \n");
		 printf("      **	               **   **   \n");
		 printf("      **	              **    **	  \n");
		 printf("      **                            **\n");
		 printf("      **                            **\n");
		 printf("      **	                  \n");
		 printf("      **	                     \n");
		 printf("      **                        \n");
		 printf("      **                       \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 7)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           ****\n");							
		 printf("      **		         **    **\n");
		 printf("      **		        **      **\n");
		 printf("      **		        **      **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                           ****\n");
		 printf("      **			 ********\n");
		 printf("      **	                **  **  **\n");
		 printf("      **	               **   **   **\n");
		 printf("      **	              **    **	  **\n");
		 printf("      **                            **\n");
		 printf("      **                            **\n");
		 printf("      **	                  \n");
		 printf("      **	                 \n");
		 printf("      **                        \n");
		 printf("      **                       \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 8)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           ****\n");							
		 printf("      **		         **    **\n");
		 printf("      **		        **      **\n");
		 printf("      **		        **      **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                           ****\n");
		 printf("      **			 ********\n");
		 printf("      **	                **  **  **\n");
		 printf("      **	               **   **   **\n");
		 printf("      **	              **    **	  **\n");
		 printf("      **                            **\n");
		 printf("      **                            **\n");
		 printf("      **	                  **  \n");
		 printf("      **	                 **    \n");
		 printf("      **                        **      \n");
		 printf("      **                       **        \n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
		else if (in == 9)
		{
		 printf("      ********************************\n");
		 printf("      ********************************\n");
		 printf("      **		            **\n");
		 printf("      **                            **\n");
		 printf("      **		           ****\n");							
		 printf("      **		         **    **\n");
		 printf("      **		        **      **\n");
		 printf("      **		        **      **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                           ****\n");
		 printf("      **			 ********\n");
		 printf("      **	                **  **  **\n");
		 printf("      **	               **   **   **\n");
		 printf("      **	              **    **	  **\n");
		 printf("      **                            **\n");
		 printf("      **                            **\n");
		 printf("      **	                  **  **\n");
		 printf("      **	                 **    **\n");
		 printf("      **                        **      **\n");
		 printf("      **                       **        **\n");
		 printf("      **\n");
		 printf("     ****\n");
	     printf("  **********\n");
	     printf(" ************\n");
         printf("**************\n\n");
     	}
        else if (in == 0)
        {
         printf("\n\n");	
		}
}

int check(int input, char word[])/*Excerpt from Python's "in"*/
{
	int i=0;
	
	for(i;i<strlen(word);i++)
	{
		if(input == tolower(word[i]))
		{
			return 1;
		}
		
	}
	return 0;
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

int count_alpha(char word[])/*Return number of alphabet in string word*/
{
	int i=0,count=0;
	for(i;i<strlen(word);i++)
	{
		if((word[i]>96 && word[i]<123) || (word[i]>=65 && word[i]<=90))
		{
			count++;
		}
	}		
	return count;
}

int find(char string[], int cha)/*If cha in string, return index - Excerpt from Python's find*/
{
	int i=0;
	for(i=0;i<strlen(string); i++)
	{
		if(string[i]==cha)
		{
			return i;
		}
	}
	return -1;
}

int printboxes(char current[], int box)
{
	int i;
	for(i=0;i<strlen(current);i++)
	{
		if(current[i]==box)
			printf(" _ ");
		else
			printf("   ");
	}
	printf("\n");
	for(i=0;i<strlen(current);i++)
	{
		if(current[i]==box)
			printf("|_|");
		else
			printf(" %c ", current[i]);
	}
	printf("\n");
}

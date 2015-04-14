#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*All function except stated otherwise should be treated as primary objective*/
/*Best of Luck*/
void main(void)
{
	system("mode 60,45");/*fixed window size*/
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
	
	char input[2];
	printf("\nEnter a number 1-6: ");
	scanf("%s", input);
	system("cls");
	
	if(input[0]=='1')
	{
		printf("single");/*Singleplayer*/
	}
	if(input[0]=='2')
	{
		printf("multi");/*Multiplayer*/
	}
	if(input[0]=='3')
	{
		printf("create");/*Create-a-category*/
	}
	if(input[0]=='4')
	{
		printf("score");/*Print scores*/
	}
	if(input[0]=='5')
	{
		printf("credit");/*Print our awesome names*/
	}
	if(input[0]=='6')
	{
		printf("quit");/*Remove if impossible*/
	}
}

int single()
{
	FILE *txt;
	char input[2];
	char vocab[51][101][51]={""};/*50 categories / 100 Vocabs per category*/
	char hint[51][101][501]={""};/*50 categories / 100 Hints per category*/
	char desc[51][501]={""};/*Description for category*/
	unsigned int category=0, show_desc=1, ready=0;
	
	/*Insert File Read here*/
	/*No function since no string return.*/
	/*Leap of faith: File I/O*/
	
	while(1)
	{
		/*Don't forget to print the interface*/
		printf("Input: ");
		scanf("%s", input);
		if(input[0]=='')
		{
			category=random();/*Random category*//*Leap of faith:random*/
		}
		if(input[0]=='')
		{
			show_desc-=1;
		}
		if(input[0]=='')
		{
			;/*print title and desc of all category*/
			/*print error if not possible*/
		}
		if(input[0]=='')
		{
			printf("Input Category: ");
			scanf("%d", category);
			/*print error if not possible*/
		}
		if(input[0]=='')
		{
			play(1, category, vocab, hint, desc, show_desc);
			/*print error if not possible*/
		}
		if(input[0]=='')
		{
			return 0;/*Back*/
		}
	}
}

int multi()
{
	play(2,0,"", "", "", 0);
}

int create()
{
	FILE *txt; 
	char input[501];
	char vocab[51][101][51]={""};/*50 categories / 100 Vocabs per category*/
	char hint[51][101][501]={""};/*50 categories / 100 Hints per category*/
	char desc[51][501]={""};/*Description for category*/
	/*Don't forget to print the interface*/
}

int score()/*Secondary Objective*/
{
	/*Score for each category using sort algorithm (qsort should be easiest)*/
	char score[/*Scan number of category from file first*/1][52];/*Show only first fifty highest score*/
	FILE *txt;
}

int credit()
{
	/*Just print massively*/
}

int play(unsigned int mode, unsigned int category, char vocab[][][], char hint[][][], char desc[][])
{
	char word[51];
	char input[51];
	int life=5;/*can't remember... please recount.*/
	int score=0;
	int number;
	char adv1[101];/*Player name*//*Secondary Objective*/
	char adv2[101];/*Question giver name(Multiplayer)*//*Secondary Objective*/
	int correct; /*0 = wrong 1 = correct*/
	int i;
	char already[27];/*Save character that are already used*/
	if(mode==1)/*Singleplayer*/
	{
		while(strcmp(input,"q")!=0)
		{
			/*Don't forget to print the interface*/
			number=random(); 
			strcpy(word, vocab[category][number]); 
			while(strcmp(input,"q")!=0)
			{
				/*Don't forget to print the interface*/
				printf("Your input: ");
				scanf("%s", input);
				for(i=0;i<strlen(input);i++)
				{
					correct = check(input, word);/*check if corrrect return 1 otherwise 0*/
					if(!(correct))
					{
						life--;
						man(life);
					}
					if(life==0)
					{
						printf("You are dead, Mazel tov.");
						break;
					}
				}
			}
		}
	}
	elif(mode==2)/*Multiplayer*/
	{
	int score=45,life=0,all=0,j=0,k=0,stat=1;
	char word[51],alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},state[51];
	while(life<9){
		
		printf("Please insert your word: ");
		fgets (word, 51, stdin);
		clear();
			
		word[strcspn(word, "\n")] = 0;
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


void clear(void)/*clear screen. please measure screen first.*/
{
	system("cls");
}

int score=45,life=0,all=0,j=0,k=0,stat=1;
	char word[51],alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},state[51];
	while(life<9){
		
		printf("Please insert your word: ");
		fgets (word, 51, stdin);
		clear();
			
		word[strcspn(word, "\n")] = 0;
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

int find(char string[], int cha)/*If cha in string, return index*/ /*Excerpt from Python's find*/
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

void clear(void)/*clear screen. please measure screen first.*/
{
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

int check(char input[], char word[])/*Excerpt from Python's "Find"*/
{
	int i=0;
	
	for(i;i<strlen(word);i++)
	{
		if(input == word[i])
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

int find(char string[], int cha)/*If cha in string, return index*/ /*Excerpt from Python's find*/
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

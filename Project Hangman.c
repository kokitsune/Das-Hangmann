#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*All function except stated otherwise should be treated as primary objective*/
/*Best of Luck*/
void main(void)
{
	char input[2];
	while(1)
	{
		/*print mainmenu interface*/
		printf("Command: ");
		scanf("%s", input);
		if(input[0]=='')
		{
			single();/*Singleplayer*/
		}
		if(input[0]=='')
		{
			multi();/*Multiplayer*/
		}
		if(input[0]=='')
		{
			create();/*Create-a-category*/
		}
		if(input[0]=='')
		{
			score();/*Print scores*/
		}
		if(input[0]=='')
		{
			credit();/*Print our awesome names*/
		}
		if(input[0]=='')
		{
			quit();/*Remove if impossible*/
		}
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
	char word[51];
	fgets (word, 51, stdin);
	word[strcspn(word, "\n")] = 0;
	char now[strlen(word)+1];
	int i=0,check=0,life=0,pop=0;
	for(i=0;i<strlen(word);i++)
		now[i]='_';
	char input[3];
	
	do
	{
		i=0;
		

		for(i;i<strlen(word);i++)
		{
			if(input[0] == word[i])
			{
				now[i]=input[0];
				check++;
				pop=1;
			}	
			else 
			if (word[i] == ' ')
			{
				now[i]=' ';
			}
			else
			{	
				
			}
		}
		if(!pop)
		{
			life++;
			pop=0;
		}

		i=0;
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
		printf("\n");
		printf("\n");
		if (!(check>=strlen(word) || life >=10))
			fgets (input, 3 , stdin);
	}while (!(check>=strlen(word) || life >=10));
}

void clear(void)/*clear screen. please measure screen first.*/
{
	printf("/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n");
}

int man(int life)/*Print a picture of a hangman*/
{
	if(life==0)/*Please measure screen size first*/
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("= =\n");
		printf(" w \n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
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

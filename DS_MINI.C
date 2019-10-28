#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<dos.h>
#include<time.h>
#include<graphics.h>

int score = 0;

void print_score(score)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
circle(323,199,30);
line(300,200,345,200);
printf("\n\n\n\n\n\n\tYour score is:\n");
gotoxy(41,12);
printf("%d",score);
gotoxy(41,14);
printf("25");
getch();
closegraph();
}
// #######################  ClearScreen  ##################################

void ClearScreen()
{
	clrscr();

	printf("\t\t\t\tWELCOME TO QUIZ\n\n");
}


// #######################  Instructions Page  #########################
char instructions()
{       char ch;
	ClearScreen();

	printf("\n\n\t\t\t\t INSTRUCTIONS ");
	printf("\n\t 1. Quiz contains total 10 Questions");
	printf("\n\t 2. Each Question has 4 options in which one is correct.");
	printf("\n\t 3. Each question has a defined Rating which tells its difficulty level.");
	printf("\n\t 4. Each correct answer is rewarded with +5 and wrong answer with -1.");
	printf("\n\n\n\n\t\t\tWant to Play the Quiz(Y/N).\n");
	scanf("%s",&ch);
	return ch;
}

//#########################  STRUCTURE DEFINITION  #######################
struct Node{

  struct Node *left;
  struct Node *right;
  char Quest[100];      //The Question
  char option1[80];
  char option2[80];
  char option3[80];
  char option4[80];
  int rating;           //The difficulty of the question
  int key;              //Index of the correct answer
};


//######################### CREATING THE NODE ###############################

struct Node *create( char Ques[], int key ,char option1[],char option2[],char option3[],char option4[], int rating)
{

    struct Node *ptr= (struct Node*)malloc(sizeof( struct Node ));

    ptr->key=key;
    strcpy(ptr->Quest,Ques);
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->rating = rating;
    strcpy(ptr->option1,option1);
    strcpy(ptr->option2,option2);
    strcpy(ptr->option3,option3);
    strcpy(ptr->option4,option4);

 return ptr;

}

//#########################  INSERTING A NODE  #############################

 struct Node *insert( struct Node *root, struct Node *ptr)
{
    if(!root)
       root = ptr;

    else if(ptr->rating < root->rating)
	root->left = insert(root->left , ptr);
    else
	root->right = insert(root->right, ptr);
    return root;

 }

// #######################   DRIVER FUNCTION   ############################
void run(struct Node *root)
{   int ans,d=10;
    if(root)
	{
	    ClearScreen();             // Clear Screen for every NEW Question.
	    printf("\n\n\t\t\t%s\n\n",root->Quest);
	    delay(1000);
	    printf("\t\t\t%s",root->option1);
	    delay(1000);
	    printf("\t\t\t\t\t%s",root->option2);
	    delay(1000);
	    printf("\n\n\t\t\t%s",root->option3);
	    delay(1000);
	    printf("\t\t\t\t\t%s\n\n",root->option4);
	    scanf("%d",&ans);

	    if(ans==root->key)
		{   score+=5;
		    printf("Right answer!   :)");
		    getch();
		    run(root->right);
		}
	    else
		{
		    score--;
		    printf("Wrong answer    :(");
		    printf("\n\nThe right answer was option %d\n",root->key);
		    getch();
		    run(root->left);
		}
	}
}



// #######################   MAIN FUNCTION   ###############################

int main()
{
  int ans,rating;
  char ch,ques[100],option1[80],option2[80],option3[80],option4[80];
  struct Node *root = NULL;
  struct Node *ptr = NULL;
  // printf("\t\t\t\tWELCOME TO QUIZ\n\n");


    strcpy(ques,"How many players are in a cricket team?");
    strcpy(option1,"1.  10");
    strcpy(option2,"2.  11");
    strcpy(option3,"3.  12");
    strcpy(option4,"4.  9");
    root = create(ques,2,option1,option2,option3,option4,3);


	strcpy(ques,"How many planets are in our solar syatem?");
    strcpy(option1,"1.  9");
    strcpy(option2,"2.  8");
    strcpy(option3,"3.  10");
    strcpy(option4,"4.  7");
    ptr = create(ques,1,option1,option2,option3,option4,2);
	root = insert( root, ptr );


    strcpy(ques,"What is the boiling point of water in F?");
    strcpy(option1,"1.  198");
    strcpy(option2,"2.  206");
    strcpy(option3,"3.  212");
    strcpy(option4,"4.  219");
    ptr = create(ques,3,option1,option2,option3,option4,5);
	root = insert( root, ptr );


	ch = instructions();

	if(ch=='Y'|| ch=='y')
	{	run(root);
		clrscr();
		print_score(score);
	   }

    else
	printf("\n\t\t\t\t Thanks for coming Here");

getch();
return 0;
}

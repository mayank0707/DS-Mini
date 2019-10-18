#include<stdio.h>
#include<conio.h>
#include<malloc.h>

//#########################  STRUCTURE DEFINITION  #######################

struct Node{

  struct Node *left;
  struct Node *right;
  char Quest[100];
  int ans;
  int key;

};

//######################### CREATING THE NODE ###############################

struct Node *create( char Ques[], int ans , int key )
{

 struct Node *ptr= (struct Node*)malloc(sizeof( struct Node ));

 ptr->key=key;
 strcpy(ptr->Quest,Ques);
 ptr->ans=ans;
 ptr->left=NULL;
 ptr->right=NULL;

 return ptr;

}

//#########################  Insertion Of NODE  #############################

 struct Node *insert( struct Node *root, char Ques[] , int ans, int key )
{
    if(!root)
    {
       root=create( Ques, ans, key);
    }

    else
    {
	root->left= insert( root->left , Ques , ans , key);

    }

    return root;

 }


//##############################  PreOrder  ####################################

 void preorder( struct Node *root )
 {
      int ans;

      if(root)
      {
	 printf("\n\nQuestion: %s ",root->Quest);
	 printf("\nYour Answer:  ");
	 scanf("%d", &ans);



	 if( ans==root->ans )
	 {
	     printf("\n\nGood Work !!!! ");
	     preorder(root->left);
	 }

	 else
	 {
	   printf("\n\nSorry Wrong Answer.Best Of Luck Next Time!!!!");
	   printf("\n\nThanks for Playing With US.");

	 }

      }



 }


// #######################   MAIN FUNCTION   ###############################

void main()
{
  int n=0,ans;	           // n here is No. of Questions..
  char ques[100];          //  Questions
  struct Node *root=NULL;

  clrscr();

  while(n<2){

	printf("Question No. %d : ",n+1);
	scanf("%s",&ques);
	printf("Answer %d : ",n+1);
	scanf("\n%d",&ans);

	root=insert( root, ques, ans , (2-n) );

	n++;

  }

  clrscr();

  printf("\t\t\tWELCOME TO QUIZ\n\n");

  preorder(root);


getch();

}





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>



#define MAXSTACK 30

// Stack implementation
typedef int StackEntry;
typedef struct{
 int top;
 StackEntry entry[MAXSTACK];
 }Stack;


 void CreateStack(Stack *s){

        s->top=-1;
}

//This funtion not neccecary
bool IsStackFull(const Stack *s){
 
    return (s->top==MAXSTACK-1);
}

bool IsStackEmpty( Stack *s){

    return(s->top==-1);
}

void Push(StackEntry item, Stack *s){
   
    
     s->top++;
     s->entry[s->top]=item;
 }

 void pop( Stack *s){
    
    s->top--;
 }

// function for preview stack element
 void display(Stack *s){
     
     for (int i = 0; i <= s->top; i++)
     {
         printf(" %d ",s->entry[i]);
     }
     
 }
 

 //Random number set genation  

void randomNumbers(int size, Stack *s){

    printf("\t\tSystem generated number set  : ");
    for (int i = 0; i < size; i++)
    {
        int randNum=rand()%(0-10 + 1);


        Push(randNum,s);
        printf(" %d ",randNum);
    }

}

//Assign values to b stack in vererse of generated number set oder 

void stackReverse(Stack *c, Stack *b, int range){
    for (int i = 0; i < range; i++)
    {

        Push(c->entry[c->top],b);

        pop(c);



    }


}

//Copmpare and pop high and same values of A and B stacks
void comparison(Stack * s, Stack * b){
        printf("\n\n\n\t\tOutput :");
        while (!(IsStackEmpty(s) || IsStackEmpty(b)))
        {


            if (s->entry[s->top]> b->entry[b->top])
            {
                
                 pop(s);

                 printf(" 2 ");

            }
            else if(s->entry[s->top]<b->entry[b->top]){

              
                pop(b);

                printf(" 1 ");


            }
            else
            {
                pop(s);
                pop(b);


                 printf(" 0 ");

            }

        }

}

// I got most tied results so i decided add match tied conditions but it didn't mentioned in senario

void winner(Stack * s, Stack *b){
    if (IsStackEmpty(s) && IsStackEmpty(b))
    {
        printf("\n\t\t\t Game is tied");

    }
    else if(IsStackEmpty(s))
    {
         printf("\n\t\t\t A is the Winner");

    }
    else if (IsStackEmpty(b)){
         printf("\n\t\t\t B is the Winner");

    }
}

// choose winner without tied condition 
/*
void winner(Stack *s, Stack *b) {
    
    if(IsStackEmpty(s))
    {
         printf("\n\t\t\t A is the Winner");
    }
    else{
         printf("\n\t\t\t B is the Winner");
    }
}   */





void main()
{
    Stack A,B,c;
    CreateStack(&A);
    CreateStack(&B);
    CreateStack(&c);
    

    srand(time(0));
    int numsetSize;
    printf("\t\tEnter the size of number set : ");
    scanf("%d",&numsetSize);

    randomNumbers(numsetSize,&A);
    
    c=A;// Asign A values to C stack 
    stackReverse(&c,&B,numsetSize);

    printf("\n\n\t\tA's number set is :");
    display(&A);
    printf("   ( %d is at the top of the box)",A.entry[A.top]);

    printf("\n\t\tB's number set is :");
    display(&B);
    printf("   ( %d is at the top of the box)",B.entry[B.top]);
    printf("\n\n\t\t\t\t-----------------------------------");

    comparison(&A,&B);
    winner(&A,&B);


    


}

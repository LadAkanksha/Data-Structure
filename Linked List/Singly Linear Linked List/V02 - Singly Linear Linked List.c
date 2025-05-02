#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cnt = 0;
struct node{
    int Data;
    struct node *Next;
};

void Insert_First(struct node **First , int no)
{
    struct node *NewN = NULL;

    NewN = (struct node *)malloc(sizeof(struct node));

    if(NewN == NULL)
    {
        printf("\nMalloc Failed....");
        return;
    }

    NewN -> Data = no;
    NewN -> Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        NewN -> Next = *First;
        *First = NewN;
    }
    printf("\n%d is Successfully Inserted at First.",no);
    cnt++;
}

void Insert_Last(struct node **First , int no)
{
    struct node *NewN = NULL , *Temp = *First;

    NewN = (struct node *) malloc(sizeof(struct node));

    if(NewN == NULL)
    {
        printf("\nMalloc Failed...");
        return;
    }

    NewN -> Data = no;
    NewN -> Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
    }
    printf("\n%d is Successfully Inserted at First." , no);
    cnt++;
}

void Display_LL(struct node *First)
{
    if(First == NULL)
    {
        printf("\nList is Empty..");
    }
    else
    {
        printf("\n\nElements in Linked List ->\n\t");
       while( First != NULL)
        {
            printf(" | %d | -> ",First -> Data);
            First = First -> Next;
        }
        printf(" NULL \n");
    }
}

int main()
{
    struct node *Head = NULL;

    Display_LL(Head);
    Insert_First(&Head , 21);
    Insert_First(&Head , 32);
    Insert_First(&Head , 99);
    Display_LL(Head);

    Insert_Last(&Head , 45);
    Insert_Last(&Head , 56);
    Insert_Last(&Head , 23);
    Display_LL(Head);
    getch();
    return 0;
}

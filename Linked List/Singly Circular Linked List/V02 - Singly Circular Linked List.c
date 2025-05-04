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
        NewN -> Next = *First;
    }
    else
    {
        struct node *Temp = *First;

        NewN -> Next = *First;
        while(Temp -> Next != *First)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
        *First = NewN;
    }
    printf("\n%d is Successfully Inserted at First.",no);
    cnt++;
}

void Insert_Last(struct node **First , int no)
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
        NewN -> Next = *First;
    }
    else
    {
        struct node *Temp = *First;

        NewN -> Next = *First;
        while(Temp -> Next != *First)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
    }
    printf("\n%d is Successfully Inserted at Last.",no);
    cnt++;
}

void Display_LL(struct node *First)
{
    struct node *Temp = First;
    if(Temp == NULL)
    {
        printf("\nList is Empty...");
    }
    else
    {
        printf("\n\nElements in Linked List ->\n\t");
        while(Temp -> Next != First)
        {
            printf(" | %d | -> ",Temp -> Data);
            Temp = Temp -> Next;
        }
        printf(" | %d | ",Temp -> Data);
    }
    printf("\nhello");
}
int main()
{
    struct node *Head = NULL;

    Display_LL(Head);
    Insert_First(&Head , 21);
    Insert_First(&Head , 32);
    Insert_First(&Head , 99);
    Display_LL(Head);

    Insert_Last(&Head , 78);
    Insert_Last(&Head , 5);
    Insert_Last(&Head , 96);
    Display_LL(Head);

    getch();
    return 0;
}

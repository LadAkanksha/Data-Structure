#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cnt = 0;
struct node{
    struct node *Prev;
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
    NewN -> Prev = NULL;
    NewN -> Data = no;
    NewN -> Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        NewN -> Next = *First;
        (*First) -> Prev = NewN;
        *First = NewN;
    }
    printf("\n%d is Successfully Inserted at First.",NewN->Data);
    cnt++;
}

void Insert_Last(struct node **First , int no)
{
    struct node *NewN = NULL;
    NewN = (struct node *) malloc(sizeof(struct node));

    if(NewN == NULL)
    {
        printf("\nMalloc Failed....");
        return;
    }
    NewN -> Prev = NULL;
    NewN -> Data = no;
    NewN -> Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        struct node *Temp = *First;
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
        NewN -> Prev = Temp;
    }
    printf("\n%d is Successfully Inserted at Last.",NewN->Data);
    cnt++;
}

void Insert_At_Position(struct node **First , int no , int pos)
{
    if(pos < 1 || pos > cnt+1)
    {
        printf("\nInvalid Position...");
    }
    else if(pos == 1)
    {
        Insert_First(First,no);
    }
    else if(pos == cnt+1)
    {
        Insert_Last(First , no);
    }
    else
    {
        struct node *NewN = NULL , *Temp = *First;

        NewN = (struct node *) malloc(sizeof(struct node));
        if(NewN == NULL)
        {
            printf("\nMalloc Failed...");
            return;
        }
        NewN -> Prev = NULL;
        NewN -> Data = no;
        NewN -> Next = NULL;

        while(pos > 2)
        {
            Temp = Temp -> Next;
            pos--;
        }
        NewN -> Prev = Temp;
        NewN -> Next = Temp -> Next;
        Temp -> Next -> Prev = NewN;
        Temp -> Next = NewN;

        printf("\n%d is Successfully Inserted at Given Position by IAP.",NewN->Data);
        cnt++;
    }
}

void Delete_First(struct node **First)
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is Already Empty...");
    }
    else
    {
        *First = Temp -> Next;
        printf("\nDeleted Node is %d from First.",Temp -> Data);
        free(Temp);
        //(*First) -> Prev = NULL;

        cnt--;
    }
}

void Delete_Last(struct node **First)
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is Already Empty...");
    }
    else
    {
        if(Temp -> Next == NULL)
        {
            printf("\nDeleted Node is %d from Last.",Temp -> Data);
            free(Temp);
            *First = NULL;
        }
        else
        {
            while(Temp -> Next -> Next != NULL)
            {
                Temp = Temp -> Next;
            }
            printf("\nDeleted Node is %d from Last.",Temp -> Next -> Data);
            free(Temp -> Next);
            Temp -> Next = NULL;
        }
        cnt--;
    }
}

void Delete_At_Position(struct node **First , int pos)
{
    if(pos < 1 || pos > cnt+1)
    {
        printf("\nInvalid Position...");
    }
    else if(pos == 1)
    {
        Delete_First(First);
    }
    else if(pos == cnt)
    {
        Delete_Last(First);
    }
    else
    {
        struct node *Temp = *First;

        while(pos > 2)
        {
            Temp = Temp -> Next;
        }
        Temp = Temp -> Next;
        Temp -> Prev -> Next = Temp -> Next;
        Temp -> Next -> Prev = Temp -> Prev;
        printf("\nDeleted Node is %d from Given Position by DAP.",Temp -> Data);
        free(Temp);
        cnt--;
    }
}
void Display_LL(struct node *First)
{
    struct node *Temp = First;
    if(Temp == NULL)
    {
        printf("\nList is Empty..");
    }
    else
    {
        printf("\n\nElements in Linked List ->\n\t NULL <- ");
       while( Temp != NULL)
        {
            printf(" | %d | <==> ",Temp -> Data);
            Temp = Temp -> Next;
        }
        printf("\b\b\b\b\b-> NULL ");
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

    Insert_Last(&Head , 12);
    Insert_Last(&Head , 45);
    Insert_Last(&Head , 88);
    Display_LL(Head);

    Insert_At_Position(&Head , 200,-9);
    Insert_At_Position(&Head , 300,8);
    Insert_At_Position(&Head , 400,2);
    Insert_At_Position(&Head , 500,8);
    Display_LL(Head);

    Delete_First(&Head);
    Delete_First(&Head);
    Display_LL(Head);

    Delete_Last(&Head);
    Delete_Last(&Head);
    Display_LL(Head);

    Delete_At_Position(&Head ,-9);
    Delete_At_Position(&Head ,8);
    Delete_At_Position(&Head ,4);
    Delete_At_Position(&Head ,2);
    Display_LL(Head);
    getch();
    return 0;
}

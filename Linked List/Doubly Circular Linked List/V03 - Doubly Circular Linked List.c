#include<stdio.h>
#include<conio.h>
int cnt = 0;
struct node
{
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
        printf("\nMalloc Failed...");
        return;
    }

    NewN -> Prev = NULL;
    NewN -> Data = no;
    NewN -> Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
        NewN -> Prev = NewN;
        NewN -> Next = NewN;
    }
    else
    {
        NewN -> Next = *First;
        NewN -> Prev = (*First) -> Prev;
        (*First) -> Prev -> Next = NewN;
        (*First) -> Prev = NewN;
        *First = NewN;
    }
    printf("\n\n%d Inserted Successfully at First.",NewN -> Data);
    cnt++;
}

void Insert_Last(struct node **First , int no)
{
    struct node *NewN = NULL;
    NewN = (struct node *)malloc(sizeof(struct node));

    if(NewN == NULL)
    {
        printf("\nMalloc Failed...");
        return;
    }

    NewN -> Prev = NULL;
    NewN -> Data = no;
    NewN -> Next = NULL;

    if(*First == NULL)
    {
        *First = NewN;
        NewN -> Prev = NewN;
        NewN -> Next = NewN;
    }
    else
    {
        NewN -> Prev = (*First) -> Prev;
        NewN -> Next = (*First);
        (*First) -> Prev -> Next = NewN;
        (*First) -> Prev = NewN;
    }
    printf("\n\n%d Inserted Successfully at Last.",NewN -> Data);
    cnt++;
}

void Insert_At_Position(struct node **First , int no , int pos)
{
    struct node *NewN = NULL;
    NewN = (struct node *)malloc(sizeof(struct node));

    if(NewN == NULL)
    {
        printf("\nMalloc Failed...");
        return;
    }

    NewN -> Prev = NULL;
    NewN -> Data = no;
    NewN -> Next = NULL;

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
        struct node *Temp = *First;
        while(pos > 2)
        {
            Temp = Temp -> Next;
            pos--;
        }
        NewN -> Prev = Temp;
        NewN -> Next = Temp -> Next;
        Temp -> Next -> Prev = NewN;
        Temp -> Next =  NewN;

        printf("\n\n%d Inserted Successfully at Given position by IAP.",NewN -> Data);
        cnt++;
    }
}

void Display_LL(struct node *First)
{
    struct node *Temp = First;

    if(First == NULL)
        printf("\nList is Empty...");
    else
    {
        printf("\nNodes in Linked List --\n\n\t");
        while(Temp -> Next != First)
        {
            printf(" |%d|  <==>" , Temp -> Data);
            Temp = Temp -> Next;
        }
        printf(" |%d| ",Temp -> Data);
    }
}
int main()
{
    struct node *Head = NULL;

    Insert_First(&Head , 78);
    Insert_First(&Head , 54);
    Insert_First(&Head , 99);
    Display_LL(Head);

    Insert_Last(&Head , 52);
    Insert_Last(&Head , 63);
    Insert_Last(&Head , 74);
    Display_LL(Head);

    Insert_At_Position(&Head , 52,12);
    Insert_At_Position(&Head , 63,-2);
    Insert_At_Position(&Head , 20,4);
    Insert_At_Position(&Head , 30,2);
    Display_LL(Head);

    getch();
    return 0;
}

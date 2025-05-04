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

void Insert_At_Position(struct node **First , int no , int pos)
{
    if( pos < 1 || pos > cnt+1 )
    {
        printf("\nInvalid Position....");
    }
    else if(pos == 1)
    {
        Insert_First(First , no);
    }
    else if(pos == cnt+1)
    {
        Insert_Last(First , no);
    }
    else
    {
        struct node *NewN = NULL , *Temp = *First;

        NewN = (struct node*) malloc(sizeof(struct node));

        if(NewN == NULL)
        {
            printf("\nMalloc Failed...");
            return;
        }

        NewN -> Data = no;
        NewN -> Next = NULL;

        while(pos > 2)
        {
            Temp = Temp -> Next;
            pos--;
        }
        NewN -> Next = Temp -> Next;
        Temp -> Next = NewN;
        printf("\n%d is Successfully Inserted at First." , no);
        cnt++;
    }
}

void Delete_First(struct node **First)
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is Already Empty");
    }
    else
    {
        printf("\n%d is Successfully Deleted From First." ,Temp -> Data);
        *First = Temp -> Next;
        free(Temp);
        cnt--;
    }
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

void Delete_Last(struct node **First)
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is Already Empty");
    }
    else
    {
        if(Temp -> Next != NULL)
        {
            while(Temp -> Next-> Next != NULL)
            {
                Temp = Temp -> Next;
            }
            printf("\n%d is Successfully Deleted From Last." ,Temp -> Next -> Data);
            free(Temp -> Next);
            Temp -> Next = NULL;
        }
        else
        {
            free(Temp);
            *First = NULL;
        }
        cnt--;
    }
}

void Delete_At_Position(struct node **First , int pos)
{
        if(pos < 1 || pos > cnt)
        {
            printf("\nInvalid Position....");
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
            struct node *Temp1 = *First , *Temp2 = NULL;

            while(pos > 2)
            {
                Temp1 = Temp1 -> Next;
                pos--;
            }
            Temp2 = Temp1 -> Next;
            Temp1 -> Next = Temp2 -> Next;
            printf("\n%d is Successfully Deleted From DAP." ,Temp2 -> Data);
            free(Temp2);
            cnt--;
        }
}

void LL_Node_Count()
{
    printf("\nAvailable Node in LL = %d" , cnt);
}

void Search_Node(struct node *First , int no)
{
    int flag = 0;
    if(First == NULL)
    {
        printf("\nLinked List is Already Empty !!!\nCan't Found %d in Linked List" , no);
    }
    else
    {
        while(First != NULL)
        {
            if(First -> Data == no)
            {
                flag = 1;
            }
            First = First -> Next;
        }
        if(flag == 1)
        {
            printf("\n%d is Found in Linked List" , no);
        }
        else
        {
            printf("\n%d is Not Found in Linked List" , no);
        }
    }
}

void Free_All_Node(struct node **First)
{
    printf("\nInvalid Position....");
    struct node *Temp = NULL;
    while(*First != NULL)
    {
        Temp = *First;
        *First = Temp -> Next;
        free(Temp);
        cnt--;
    }
    printf("\nInvalid Position....");
}
int main()
{
    struct node *Head = NULL;

    LL_Node_Count();
    Search_Node(Head , 77);

    Display_LL(Head);
    Insert_First(&Head , 21);
    Insert_First(&Head , 32);
    Insert_First(&Head , 99);
    Display_LL(Head);
    LL_Node_Count();
    Search_Node(Head , 77);

    Insert_Last(&Head , 45);
    Insert_Last(&Head , 56);
    Insert_Last(&Head , 23);
    Display_LL(Head);
    LL_Node_Count();

    Insert_At_Position(&Head , 85 , -5);
    Insert_At_Position(&Head ,90 , 15);
    Insert_At_Position(&Head , 31 , 4);
    Display_LL(Head);

    Delete_First(&Head);
    Display_LL(Head);

    Delete_Last(&Head);
    Display_LL(Head);

    Delete_At_Position(&Head , -5);
    Delete_At_Position(&Head , 15);
    Delete_At_Position(&Head , 4);
    Display_LL(Head);
    LL_Node_Count();
    Search_Node(Head , 23);
    Search_Node(Head , 32);

    Free_All_Node(&Head);
    LL_Node_Count();
    getch();
    return 0;
}

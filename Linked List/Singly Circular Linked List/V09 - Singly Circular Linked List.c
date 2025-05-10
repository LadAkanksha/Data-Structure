#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cnt = 0;
struct node{                                                                             /// Structure Creation
    int Data;
    struct node *Next;
};

void Insert_First(struct node **First , int no)                                         /// Insert_First Function
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

void Insert_Last(struct node **First , int no)                                         /// Insert_Last Function
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

void Insert_At_Position(struct node **First , int no , int pos)                           /// Insert_At_Position Function
{
    if(pos < 1 || pos > cnt+1)
    {
        printf("\nInvalid Position");
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

        NewN = (struct node *)malloc(sizeof(struct node));

        NewN -> Data = no;
        NewN -> Next = NULL;

        while(pos > 2)
        {
            Temp = Temp -> Next;
            pos--;
        }

        NewN -> Next = Temp -> Next;
        Temp -> Next = NewN;
        printf("\n%d is Successfully Inserted at Position.",no);
        cnt++;
    }
}

void Delete_First(struct node **First)                                         /// Delete_First Function
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is Already Empty");
    }
    else
    {
        if(Temp -> Next != *First)
        {
            while(Temp -> Next != *First)
            {
                Temp = Temp -> Next;
            }
            *First = (*First) -> Next;
            printf("\n%d is Deleted Successfully from First",Temp -> Next -> Data);
            free(Temp -> Next);
            Temp -> Next = (*First);
        }
        else
        {
            printf("\n%d is Deleted Successfully from First",Temp -> Data);
            free(Temp);
            *First = NULL;
        }
        cnt--;
    }
}

void Delete_Last(struct node **First)                                         /// Delete_Last Function
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is Already Empty");
    }
    else
    {
        if(Temp -> Next != *First)
        {
            while(Temp -> Next -> Next != *First)
            {
                Temp = Temp -> Next;
            }
            printf("\n%d is Deleted Successfully from Last",Temp -> Next -> Data);
            free(Temp -> Next);
            Temp -> Next = (*First);
        }
        else
        {
            printf("\n%d is Deleted Successfully from Last",Temp -> Data);
            free(Temp);
            *First = NULL;
        }
        cnt--;
    }
}

void Delete_At_Position(struct node **First , int pos)                              /// Delete_At_Position Function
{
    if(pos < 1 || pos > cnt)
    {
        printf("\nInvalid Position");
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
        printf("\n%d is Deleted Successfully from DAT",Temp2 -> Data);
        free(Temp2);
        cnt--;
    }
}

void Display_LL(struct node *First)                                                  /// Display_Nodes_In_LL Function
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
}

void LL_Node_Count()                                                                    /// Count_Node_In_LL Function
{
    printf("\nCount Of Nodes in Linked List = %d",cnt);
}

void Search_Node(struct node *First , int no)                                            /// Search_Node_In_LL Function
{
    struct node *Temp = First;

    if(First == NULL)
    {
        printf("\nList is Empty...");
    }
    else
    {
        int flag = 0;
        if(Temp -> Next != First)
        {
            while(Temp -> Next != First)
            {
                if(Temp -> Data == no)
                {
                    flag = 1;
                }
                Temp = Temp -> Next;
            }
        }
        else
        {
            if(Temp -> Data == no)
            {
                flag = 1;
            }
        }
        if(flag == 1)
            printf("\n%d is Available in Given Linked List",no);
        else
            printf("\n%d is Not Available in Given Linked List",no);
    }
}

void Free_All_Node(struct node **First)                                              /// Free_Node_In_LL Function
{
    struct node *Temp1 = *First , *Temp2 = *First;
    if(*First == NULL)
    {
        printf("\nList is Empty !!!");
    }

    while((Temp1) -> Next != *First)
    {
        Temp1 = Temp1 -> Next;
        printf("\n%d is Free From Linked List.",Temp2 -> Data);
        free(Temp2);
        Temp2 = Temp1;
        cnt--;
    }
    printf("\n%d is Free From Linked List.",(Temp2 -> Data));
    free(*First);
    *First = NULL;
    printf("\nAll Nodes are Free Now !!!");
    cnt--;
}
int main()                                                                                  /// Ignition Point / Entry Point Function
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

    Insert_At_Position(&Head , 22 , -5);
    Insert_At_Position(&Head , 32 , 10);
    Insert_At_Position(&Head , 40 , 5);
    Display_LL(Head);

    Delete_First(&Head);
    Display_LL(Head);
    Delete_First(&Head);
    Display_LL(Head);
    Delete_Last(&Head);
    Delete_Last(&Head);
    Display_LL(Head);

    LL_Node_Count();
    Search_Node(Head , 40);
    Search_Node(Head , 21);
    Display_LL(Head);

    Free_All_Node(&Head);
    LL_Node_Count();
    Display_LL(Head);

    getch();
    return 0;
}

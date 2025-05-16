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
        printf("\n Malloc Failed...");
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

void Delete_First(struct node **First)
{
    struct node *Temp = *First;
    if(*First == NULL)
    {
        printf("\nList is Empty...");
    }
    else if(Temp -> Next != *First)
    {
        *First = Temp -> Next;
        Temp -> Prev -> Next = *First;
        (*First) -> Prev = Temp -> Prev;
        printf("\n\n%d Deleted Successfully From First.",Temp -> Data);
        free(Temp);
    }
    else
    {
        *First = NULL;
        printf("\n\n%d Deleted Successfully From First.",Temp -> Data);
        free(Temp);
    }
    cnt--;
}

void Delete_Last(struct node **First)
{
    struct node *Temp = *First;
    if(*First == NULL)
    {
        printf("\nList is Empty...");
    }
    else
    {
        if((*First) -> Next == *First)
        {
            *First = NULL;
            printf("\n\n%d Deleted Successfully From Last..",Temp -> Data);
            free(Temp);
        }
        else
        {
            Temp = (*First) -> Prev;
            Temp -> Prev -> Next = *First;
            (*First) -> Prev = Temp -> Prev;
            printf("\n\n%d Deleted Successfully From Last.",Temp -> Data);
            free(Temp);
        }
    }
    cnt--;
}

void Delete_At_Position(struct node **First , int pos)
{
    if(pos < 1 || pos > cnt)
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
        struct node *Temp1 = *First , *Temp2 = *First;
        while(pos > 2)
        {
            Temp1 = Temp1 -> Next;
            pos--;
        }
        Temp2 = Temp1 -> Next;
        Temp1 -> Next = Temp2 -> Next;
        Temp2 -> Next -> Prev = Temp1;
        printf("\n\n%d Deleted Successfully From List by DAP.",Temp2 -> Data);
        free(Temp2);
        cnt--;
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
void LL_Node_Count()
{
    printf("\n%d Nodes Available in Linked List.",cnt);
}

void Search_Node(struct node *First , int no)
{
    int flag = 0;
    if(First == NULL)
    {
        printf("\nList is Empty.So,%d Not Found !!!",no);
    }
    else
    {
        if(First -> Next == First && First -> Data == no)
            flag = 1;
        while(First -> Next != First)
        {
            if(First -> Data == no)
            {
                flag = 1;
                break;
            }
            First = First -> Next;
        }

        if(flag == 1)
            printf("\n%d is Found in Linked List",no);
        else
            printf("\n%d is Not Found in Linked List.",no);
    }
}
int main()
{
    struct node *Head = NULL;
    LL_Node_Count();
    Search_Node(Head , 56);
    Insert_First(&Head , 78);
    Insert_First(&Head , 54);
    Insert_First(&Head , 99);
    Display_LL(Head);

    Delete_First(&Head);
    Delete_First(&Head);
    Display_LL(Head);
    Search_Node(Head , 83);
    Insert_Last(&Head , 52);
    Insert_Last(&Head , 63);
    Insert_Last(&Head , 74);
    Display_LL(Head);
    LL_Node_Count();
    Insert_At_Position(&Head , 52,12);
    Insert_At_Position(&Head , 63,-2);
    Insert_At_Position(&Head , 20,4);
    Insert_At_Position(&Head , 30,2);
    Display_LL(Head);

    Delete_Last(&Head);
    Delete_Last(&Head);
    Display_LL(Head);
    Search_Node(Head , 30);
    Delete_At_Position(&Head , -9);
    Delete_At_Position(&Head , 10);
    Delete_At_Position(&Head , 3);
    Delete_At_Position(&Head , 2);
    Display_LL(Head);
    LL_Node_Count();
    getch();
    return 0;
}

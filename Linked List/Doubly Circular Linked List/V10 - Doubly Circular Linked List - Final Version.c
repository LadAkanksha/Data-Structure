#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cnt = 0;
struct node                                                                                /// Structure Creation
{
    struct node *Prev;
    int Data;
    struct node *Next;
};

void Insert_First(struct node **First , int no)                                             /// Insert_First Function
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

void Insert_Last(struct node **First , int no)                                              /// Insert_Last Function
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

void Insert_At_Position(struct node **First , int no , int pos)                             /// Insert_At_Position Function
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

void Delete_First(struct node **First)                                                      /// Delete_First Function
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

void Delete_Last(struct node **First)                                                       /// Delete_Last Function
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

void Delete_At_Position(struct node **First , int pos)                                      /// Display_Nodes_In_LL Function
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

void Display_LL(struct node *First)                                                         /// Display_Nodes_In_LL Function
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

void LL_Node_Count()                                                                        /// Count_Node_In_LL Function
{
    printf("\n%d Nodes Available in Linked List.",cnt);
}

void Search_Node(struct node *First , int no                                               /// Search_Node_In_LL Function
{
    struct node *Temp = First;
    int flag = 0;
    if(First == NULL)
    {
        printf("\nHii...");
        printf("\nList is Empty.So,%d Not Found !!!",no);
    }
    else
    {
        if(Temp -> Next == Temp && Temp -> Data == no)
        {
            printf("\nHii...1");
            flag = 1;
        }
        while(Temp -> Next != First)
        {
            printf("\nHii...2");
            if(Temp -> Data == no)
            {
                flag = 1;
                break;
            }
            Temp = Temp -> Next;
        }

        if(flag == 1)
            printf("\n%d is Found in Linked List",no);
        else
            printf("\n%d is Not Found in Linked List.",no);
    }
}

void Free_All_Node(struct node **First)                                                     /// Free_Node_In_LL Function
{
    if(*First == NULL)
    {
        printf("\nList is Already Empty...");
    }
    else
    {
        struct node *Temp1 = *First , *Temp2 = NULL;
        while(Temp1 -> Next != *First)
        {
            Temp2 = Temp1;
            Temp1 = Temp1 -> Next;
            printf("\n%d is Free from Linked List.", Temp2 -> Data);
            free(Temp2);
            cnt--;
        }
        *First = NULL;
        printf("\n%d is Free from Linked List.", Temp1 -> Data);
        free(Temp1);
        cnt--;
        printf("\nAll Nodes are Free Now !!!");
    }
}

int main()                                                                                  /// Ignition Point / Entry Point Function
{
    struct node *Head = NULL;
    int choice = 0 , num = 0 , loc = 0;
    char cVal = '\0';

    while(1)
    {
        printf("\n------------------------------------------------------------");
        printf("\n\t\t 1. Insert From First\n\t\t 2. Insert From Last\n\t\t 3. Insert At position");
        printf("\n\t\t 4. Delete From First\n\t\t 5. Delete From Last\n\t\t 6. Delete At position");
        printf("\n\t\t 7. Display All Nodes\n\t\t 8. Search Node in LL\n\t\t 9. Count Node in LL\n\t\t 10. Free All Node\n\t\t 11. Exit");

        printf("\n------------------------------------------------------------");
        printf("\n\n Enter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Value For Node : ");
                scanf("%d",&num);
                Insert_First(&Head , num);
                break;

            case 2:
                printf("\nEnter Value For Node : ");
                scanf("%d",&num);
                Insert_Last(&Head , num);
                break;

            case 3:
                printf("\nEnter Value For Node : ");
                scanf("%d",&num);
                printf("\nEnter Position For Insertion : ");
                scanf("%d",&loc);
                Insert_At_Position(&Head , num, loc);
                break;

            case 4:
                Delete_First(&Head);
                break;

            case 5:
                Delete_Last(&Head);
                break;

            case 6:
                printf("\nEnter Position For Deletion : ");
                scanf("%d",&loc);
                Delete_At_Position(&Head ,loc);
                break;
            case 7 :
                    Display_LL(Head);
                    break;

            case 8 :
                printf("\nEnter Value For Node Search : ");
                scanf("%d",&num);
                Search_Node(Head,num);
                break;

            case 9:
                LL_Node_Count();
                break;

            case 10:
                printf("\n!!!  Are You Sure To Free All Node in Linked List ?\t");
                fflush(stdin);
                cVal = getchar();

                if(cVal == 'Y' || cVal == 'y')
                {
                    Free_All_Node(&Head);
                }
                LL_Node_Count();
                break;

            case 11 :
                printf("\n!!!  Are You Sure To Exit Form Application ?\t");
                fflush(stdin);
                cVal = getchar();

                if(cVal == 'Y' || cVal == 'y')
                {
                    goto DOWN;
                }
                break;
            default:
                printf("\nInvalid Choice !!!");
                break;
        }

    }
    DOWN:
    printf("\n\n-----   Thanks For Using Our Application    -----");
    printf("\n\n\t-----   Visit Again    -----");
    getch();
    return 0;
}


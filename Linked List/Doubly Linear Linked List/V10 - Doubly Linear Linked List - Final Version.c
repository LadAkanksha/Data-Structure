#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int cnt = 0;
struct node{                                                                                /// Structure Creation
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

void Insert_Last(struct node **First , int no)                                              /// Insert_Last Function
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

void Insert_At_Position(struct node **First , int no , int pos)                             /// Insert_At_Position Function
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

void Delete_First(struct node **First)                                                      /// Delete_First Function
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

void Delete_Last(struct node **First)                                                       /// Delete_Last Function
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

void Delete_At_Position(struct node **First , int pos)                                      /// Delete_At_Position Function
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
        struct node *Temp = *First;

        while(pos > 2)
        {
            Temp = Temp -> Next;
            pos--;
        }
        Temp = Temp -> Next;
        Temp -> Prev -> Next = Temp -> Next;
        Temp -> Next -> Prev = Temp -> Prev;
        printf("\nDeleted Node is %d from Given Position by DAP.",Temp -> Data);
        free(Temp);
        cnt--;
    }
}
void Display_LL(struct node *First)                                                         /// Display_Nodes_In_LL Function
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

void LL_Node_Count()                                                                        /// Count_Node_In_LL Function
{
    printf("\nCount Of Nodes in Linked List = %d",cnt);
}

void Search_Node(struct node *First,int no)                                                 /// Search_Node_In_LL Function
{
    struct node *Temp = First;

    if(First == NULL)
    {
        printf("\n%d is not Found Bcz List is Empty...");
    }
    else
    {
        while(Temp != NULL)
        {
            if(Temp -> Data == no)
            {
                printf("\n%d is Found in Linked List",Temp -> Data);
                break;
            }
            Temp = Temp -> Next;
        }
        if(Temp == NULL)
        {
            printf("\n%d is Not Found in Linked List",no);
        }
    }
}

void Free_All_Node(struct node **First)                                                     /// Free_Node_In_LL Function
{
    struct node *Temp = *First;

    if(*First == NULL)
    {
        printf("\nList is already Empty...");
    }
    else
    {
        while(Temp != NULL)
        {
            printf("\n%d is Free from Linked List.",Temp -> Data);
            *First = Temp -> Next;
            free(Temp);
            Temp = *First;
            cnt--;
        }
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


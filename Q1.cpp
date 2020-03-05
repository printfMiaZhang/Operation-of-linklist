#include<stdio.h>
#include<stdlib.h>

struct listNode
{
    int data;
    struct listNode *nextPtr;
};

  
typedef ListNode *ListNodePtr;

void instructions(void);
void InsertAtFirst(ListNodePtr *sPtr, int value);
void DeleteTheFirstNode(ListNodePtr *sPtr);
int  isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr *sPtr);
void InsertNodeKbeforeD(ListNodePtr *sPtr, int value);
void Copyalinkedlistintoanother(ListNodePtr *sPtr, ListNodePtr *bPtr);
void ReverseTheLinkedList(ListNodePtr *sPtr);
void ConcatenateTwoLinkedList(ListNodePtr *sPtr, ListNodePtr*bPtr);
void Append(ListNodePtr * pHead,int val);
int DeleteASpecificNode(ListNodePtr *sPtr, int value);
void DeleteEntireLinkedList(ListNodePtr *sPtr);

int main(void)
{
    ListNodePtr startPtr = NULL;
    int node,nextPtr;
    
    char choice;
    
    while (1)
    {
        instructions();
        printf("%s","?");
        scanf("%c",&choice);
        
        while((getchar() != '\n'));
        
        switch (choice)
        {
            case '1':
            {
                printf("%s\n", "< add a new node before the first node >\nPlease enter a number for equipment part:");
                scanf("\n%d", &node);
                while((getchar() != '\n'));
                InsertAtFirst(&startPtr, node);
                printList(startPtr);
                break;
            }
                
            case '2':
            {
                if(!isEmpty(startPtr))
                {
                    DeleteTheFirstNode(&startPtr);
                    printList(startPtr);
                }
                else
                {
                    puts("L-NULL");
                }
                while((getchar() != '\n'));
                break;
            }
                
            case '3':
            {
                printf("< insert a K node before D node >\nPlease enter a number for D :");
                int position = 0;
                scanf("%d", &position);
                while((getchar() != '\n'));
                InsertNodeKbeforeD(&startPtr, position);
                printList(startPtr);
                break;
            }
            case '4':
            {
                ListNodePtr bPtr = NULL;
                Copyalinkedlistintoanother(&startPtr,&bPtr);
                printList(startPtr);
                printList(bPtr);
                break;
            }
            case '5':
            {
                printf("Given linked list\n");
                printList(startPtr);
                ReverseTheLinkedList(&startPtr);
                printf("\nReversed linked list\n");
                printList(startPtr);
                getchar();
                break;
            }
                
            case '7':
            {
                ListNodePtr aPtr = NULL;
                InsertAtFirst(&aPtr,4);
                InsertAtFirst(&aPtr,5);
                ListNodePtr bPtr = NULL;
                printf("The two linked lists are merged into:");
                InsertAtFirst(&bPtr,2);
                InsertAtFirst(&bPtr,3);
                printf("Linked List A,");
                printList(aPtr);
                printList(bPtr);
                ConcatenateTwoLinkedList(&aPtr, &bPtr);
                printList(aPtr);
                break;
            }
                
            case 'A':
            {
                printf("< add a new node >\nplease enter a number for equipment part:");
                scanf("\n%d", &node);
                while((getchar() != '\n'));
                Append(&startPtr, node);
                printList(startPtr);
                break;
            }
                
            case 'D':
            {
                if(!isEmpty(startPtr))
                {
                    printf("%s","Which node you want to delete?:");
                    scanf("\n%d", &node);
                    while((getchar() != '\n'));
                    
                    if(DeleteASpecificNode(&startPtr, node))
                    {
                        printf("%d deleted.\n", node);
                        printList(startPtr);
                    }
                    else
                    {
                        printf("%d not found.\n\n", node);
                    }
                }
                else
                {
                    puts("L-NULL");
                }
                break;
            }
                
            case 'K':
                {
                DeleteEntireLinkedList(&startPtr);
                
                    if(startPtr == NULL){
                    printf("List deleted");
                    }
                break;
                }
                
            case'Q':
            {
                if(choice=='Q')
                {
                    exit(0);
                }
                else
                {
                    printf("Forget Code Retains");
                }
                return 0;
                break;
            }
            default:
            {
                puts("Invalid choice.\n");
                break;
            }
        }
        puts("End of run.");
    }
}
void instructions(void)
{
    puts("1. InsertAtFirst\n"
         "2. Delete The First Node\n"
         "3. Insert node K before D\n"
         "4. Copy a linked list into another\n"
         "5. Reserve The Linked List\n"
         "7. Concatenate Two Linked Lists\n"
         "A. Append a node for next\n"
         "D. Delete a specific node\n"
         "K. Delete the entire Link List\n"
         "Q. Quit");
    
    printf("SELECT:\n");
    
}

void InsertAtFirst(ListNodePtr *sPtr, int value)
{
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNodePtr));
    
    if (newPtr!=NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
    else
    {
        printf("%d not inserted. No memory available.\n", value);
    }
}

void DeleteTheFirstNode(ListNodePtr *sPtr)
{
    ListNodePtr currentPtr = *sPtr;
    *sPtr = (*sPtr)->nextPtr;
    free(currentPtr);
}

int isEmpty(ListNodePtr nansPtr)
{
    return sPtr == NULL;
}
void printList(ListNodePtr *sPtr)
{
    ListNodePtr currentPtr=sPtr;
    if(isEmpty(currentPtr))
    {
        puts("L-NULL\n");
    }
    else
    {
        puts("The list is:");
    }
    while (currentPtr!=NULL)
    {
        printf("%d -", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
        
    }
    puts("NULL\n");
    
    
}

void InsertNodeKbeforeD(ListNodePtr *sPtr, int position)
{
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNodePtr));
    
    
    if(newPtr!=NULL)
    {
        
        if (position==1)
        {
            printf("< add a new code before the first node >\nPlease enter a number for equipment part:");
            int value=0;
            scanf("%d", &value);
            while((getchar() != '\n'));
            InsertAtFirst(sPtr,value);
        }
        else if (position!=1)
        {
            printf("< add a node >\nPlease enter a number for equipment part:");
            int value=0;
            scanf("%d", &value);
            while((getchar() != '\n'));
            
            newPtr->data=value;
            newPtr->nextPtr=NULL;
            
            ListNodePtr previousPtr = NULL;
            ListNodePtr currentPtr = *sPtr;
            
            int count=0;
            while(currentPtr!=NULL && count!=position-1)
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
                count++;
            }
            if(count == position-1)
            {
                previousPtr->nextPtr = newPtr;
                newPtr->nextPtr = currentPtr;
            }
        }
        
        else
        {
            printf("No memory available.\n");
        }
    }
}


void Copyalinkedlistintoanother(ListNodePtr *sPtr, ListNodePtr *bPtr)
{
    ListNodePtr currentPtr=*sPtr;
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNodePtr));
    
    while(currentPtr!=NULL){
        int value= currentPtr->data;
        Append(bPtr,value);
        currentPtr = currentPtr->nextPtr;
    }
}

void ReverseTheLinkedList(ListNodePtr *sPtr)
{
    ListNodePtr previousPtr=NULL;
    ListNodePtr currentPtr=*sPtr;
    ListNodePtr nextPtr=NULL;
    
    while(currentPtr!=NULL)
    {
        nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr=previousPtr;
        previousPtr = currentPtr;
        currentPtr=nextPtr;
    }
    *sPtr = previousPtr;
}

void ConcatenateTwoLinkedList(ListNodePtr *sPtr, ListNodePtr *bPtr)
{
    ListNodePtr currentPtr=*sPtr;
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNodePtr));
    if(newPtr == NULL)
    {
        printf("New node allocation failed, program aborted!\n");
        exit(-1);
    }
    if (newPtr!=NULL)
    {
        newPtr->nextPtr=NULL;
        
        if(currentPtr!=NULL)
        {
            while(currentPtr->nextPtr != NULL)
            {
                currentPtr=currentPtr->nextPtr;
            }
            currentPtr->nextPtr=*bPtr;
            
        }
        else
        {
            *bPtr=newPtr;
        }
    }
}

void Append(ListNodePtr *sPtr,int val)
{
    ListNodePtr currentPtr=*sPtr;
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNodePtr));
    if(newPtr == NULL)
    {
        printf("New node allocation failed, program aborted!\n");
        exit(-1);
    }
    if (newPtr!=NULL)
    {
        newPtr->data=val;
        newPtr->nextPtr=NULL;
        
        if(currentPtr!=NULL)
        {
            while(currentPtr->nextPtr != NULL)
            {
                currentPtr=currentPtr->nextPtr;
            }
            currentPtr->nextPtr=newPtr;
        }
        else
        {
            *sPtr=newPtr;
        }
    }
}
int DeleteASpecificNode(ListNodePtr *sPtr, int value)
{
    ListNodePtr previousPtr = *sPtr;
    ListNodePtr currentPtr = (*sPtr)->nextPtr;
    
    ListNodePtr tempPtr= *sPtr;
    int tempValue = tempPtr->data;
    if((*sPtr)->data==value){
        *sPtr=(*sPtr)->nextPtr;
        free(tempPtr);
        return tempValue;
    }
    
    while(currentPtr != NULL && currentPtr->data!= value)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if(currentPtr != NULL)
    {
        ListNodePtr tempPtr = currentPtr;
        previousPtr->nextPtr = currentPtr->nextPtr;
        free(tempPtr);
        return value;
    }
    return '\0';
}


void DeleteEntireLinkedList(ListNodePtr *sPtr)
{
    ListNodePtr currentPtr = *sPtr;
    
    while (*sPtr!=NULL)
    {
        *sPtr = (*sPtr)->nextPtr;
        free(currentPtr);
        currentPtr = *sPtr;
    }
}




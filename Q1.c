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


Muyao Zhang 0882423
Assignment2 Question1
"I created a structure called ListNode as a single node which contains the data field and the pointer field. Then I named struct listNode as ListNode and ListNode as *ListNodePtr. I declared 12 functions from line 13 to 24. In the main function, it inializes a linkedlist and shows us a menu."

"In the instruction function, it displays each character for the menu and lets the user enter these characters which is line 37."

"In the InsertAtFirst function, I used if statement to determine whether newPtr is null, then I wrote three statements to insert a node at the first place. If there is no internal storage, the output will display no memory."

"For DeleteTheFirstNode function, I also wrote three statements to directly delete the first node."

"For isEmpty function, it is used to determine whether the linkedlist is empty."

"For the printList function, it prints the linkedlist after the user enters the numbers."

"For the InsertNodeKbeforeD function, first apply for memory, if there is memory, traversal linked list, find the location of the D node to be inserted, create a new node K, make the node in front of D point to K, and then make K point to D."

" For the Copyalinkedlistintoanother function, I let currentPtr point to *sPtr  which to iterate through the list and act as a pointer and created a memory space for newPtr. I created a pointer to the header node of linked list s and a new node b to iterate over linked list continuously. Each time the linked list s iterates over a node, assigns the data of the node to the temporary variable value and calls append function to insert value in linked list b. The replication of linked list a can be completed after the completion of traversal."

" For the ReverseTheLinkedList function, I initialized three pointers previousPtr as NULL, currentPtr as *sPtr and nextPtr as NULL. Then I iterates through the linked list. In the while loop, I stored next node before changing next of current. Then I changed next of current. "currentPtr->nextPtr=previousPtr" is where actual reversing happens. Then I moved previousPtr and currentPtr one step forward."

" For the ConcatenateTwoLinkedList function, traversing the list a to the last node, point the nextPtr of the last node to the list b header."

" For the Append function, first apply for memory, if there is memory, traversal linked list, until the last node, a new node added to the last node, otherwise prompt memory shortage."

" For the DeleteASpecificNode function, I let previousPtr point to the first node and currenrPtr point to the second node. First, determine whether the value of the first node is equal to the value to be deleted. If so, push the first node forward one by one and delete the first node to return the value of the first node.And make the previous node point directly to the latter node. Second,find if there is a node in the list whose value is equal to the value to be deleted. If there is, free the node, return the value, and make the previous node point directly to the later node. Otherwise, return '\0'."

" For the DeleteEntireLinkedList function, I let currentPtr point to the first node. When the first node isn't null, walk through the list and delete each node in turn."

How to run the program: "When you run the program, enter the main function and display the menu, prompt the user to enter options. The user enters optional options, the program is executed according to the options entered by the user. After running, let the user enter again, until the user exits the program."

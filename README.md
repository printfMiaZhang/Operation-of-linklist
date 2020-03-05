# Operation-of-linklist
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

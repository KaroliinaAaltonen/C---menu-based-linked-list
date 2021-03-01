/* Karoliina Aaltonen 01032021*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number; //DATA
    struct node *next; //ADDRESS
}*head;

void createList(int list_range)
{
    struct node *newNode, *temp;
    int data, i;
    for(i=1; i<=list_range; i++) //i=1 because first item in list is 1 not 0
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        
        if(newNode == NULL)
        {
            printf("Failed allocating memory.\n");
            exit(0);
            /* If memory is not allocated for newNode */
        }
        else
        {

            newNode->number = i; // Link data field of newNode with data
            newNode->next = NULL; // Link address field of newNode with NULL

            if(head==NULL)
            {
                head = newNode;
            }
            else
            {
                temp = head;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                temp->next=newNode;
            }
            
        }
    }
}

void appendToBeginning(int list_range)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); //create newNode
    newNode->number=list_range; //newNode value
    newNode->next=head; //next of newNode is head
    head=newNode; //newNode is now the head node
}

void appendToMiddle(int list_range, int list_index)
{
    int i;
    struct node *temp = head;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        perror("Failed allocating memory.\n");
        exit(0);
    }
    else
    {
        newNode->number=list_range;
        newNode->next=NULL;
    }
    for(i=2; i<list_index;i++)
    {
        temp=temp->next;

        if(temp==NULL)
        {
            printf("Error\n");
            exit(0);
        }
    }
    if(temp!=NULL)
    {
        newNode->next=temp->next; //linking address part of newNode
        temp->next=newNode; //linking address part of n-1 node
    }
    else
    {
        printf("Error appending data.\n");
    }
    
}

void appendToEnd(int list_range)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); //new Node
    newNode->number=list_range; //link data field with data
    newNode->next=NULL; //link address field with NULL
    if(head==NULL) //if list is empty
    {
        head=newNode; //new node is first node
    }
    else
    {
        struct node *lastNode = head; //find the last node and add new node
        while(lastNode->next!=NULL) //last node's address will be NULL
        {
            lastNode=lastNode->next;
        }
        lastNode->next=newNode; //newNode is added to the end of the linked list
    }  
}

void removeLastElement(int list_range)
{
    struct node *temp;
    if(head == NULL)
    {
        printf("The list is empty.\n");
        //The list is already empty
    }
    else if(head->next==NULL) //if next item is null release head
    {
        head=NULL;
    }
    else //traversing to the 2nd last element
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
    }

    struct node *lastNode = temp->next; 
    temp->next =NULL;//changing next of the 2nd last node to NULL
    free(lastNode); //deleting the last node
}

void printList(void)
{
    struct node *temp;

    if(head==NULL) //if first node(=the list) is empty
    {
        printf("");
    }
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            printf("%d ", temp->number); //current node information
            temp = temp->next; //next node
        }
    }
    printf("\n");
}

void emptyList(void)
{
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        head=temp->next;
        free(temp);
        temp=head;
    }
}

int main(void)
{
    int option, list_range, list_index;

    printf("This program controls a linked list.\n");
    while(1)
    {
        printf("1) Create a list\n2) Append an element to the end of the list\n3) Append an element in the middle of the list\n4) Clear list\n5) Delete an element\n6) Print list\n0) End\n");
        printf("Your option: ");
        scanf("%d",&option);

        if(option == 0)
        {
            printf("Thank you for using the program.\n");
            exit(0);
        }

        else if(option==1)
        {
            printf("Input list range: ");
            scanf("%d", &list_range);
            createList(list_range);
            printList();
        }

        else if(option==2)
        {
            list_range++;
            appendToEnd(list_range);
            printList();
        }

        else if(option==3)
        {
            list_range++;
            printf("Input list index for new list node: ");
            scanf("%d", &list_index);
            if(list_index==1)
            {
                appendToBeginning(list_range);
                printList();
            }
            else
            {
                appendToMiddle(list_range, list_index);
                printList();
            }   
        }

        else if(option == 4)
        {
            emptyList();
        }

        else if(option == 5)
        {
            removeLastElement(list_range);
            printList();
        }

        else if(option == 6)
        {
            printList();
        }

    }
    return 0;
}

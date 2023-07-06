/*what is doubly linked list ?
DLL is a one of the type of  linked list which having two direction path for traversing. each node has three parts like one of prev pointer and data 
and next pointer.*/



#include <stdio.h>
#include <stdlib.h>


// this is double linked list which having two way pointers so bring the picuture into mind and then see the code same for singly linked list 




struct node 
{
    int info;
    struct node *next;   // because of doubly linked list we have two pointers one is fornt and one is back next is back 
    struct node *prev;  // prev is fornt pointer 
}

//insert at beg of doubly linked list
struct node *insert_at_beg(struct node *head , int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node))
    temp->info = data;
    temp->prev = NULL;
    temp->next = head;
    if(head)
    {
        head->prev = temp;
    temp = head;
    return head;
    }
}

//insert at end of doubly linked list
struct node *insert_at_end(struct node *head , int data)
{
    struct node *temp , *p;
    temp->info = data;
    p = head;
    if(p)
    {
        while(p->next != NULL)
        {
            p->next = p;
            p->next = temp;
            temp->next = NULL;
            temp->prev = p;
        }
        else
        {
            head = temp;
            return head;
        }

    }
}

// insert in middle of linked list 
struct node *insert_in_middle(struct node *head , int data , int item)
{
    struct node *temp , *p;  // delcare of pointers 
    temp = (struct node *)malloc(sizeof(struct node));    // space for the node which is going to be inserted 
    temp->info = data;    // sending the data which should be in the info part of the node 
    p = head;      // firstly make pointer p equal to head
    if(p)       // means *p is not NULL
    {
        while(p->next != NULL)     // thorugh which we will move to the next node of the linked list 
        {
            if(p->info == item)   // the node which we want to insert after certian node info  element then we have to match it 
            {
                temp->next = p->next;  // this all are the steps for inseeting the node into linked list 
                p = temp->prev;
                if(p->next != NULL)
                {
                    temp = p->next->prev;
                temp = p->next;
                }
            }
            p->next = p;   // this is used when the eleement is not found in the given node and to move to next node for search 
        }
    }
}


// delection of the node in linked list 

/*case 1: if list is null 
case 2: if list is having only one node 
case 3 : if we want to delete first node in the list 
case 4 : if we ant to delete middle node in list 
case 5 : if we want to delete last node in the list */

struct node *delete_at_(struct node *head , int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    //case 1
    if(head == NULL)
    {
        printf("list is no more:\n");
        return head;
    }

    //case 2
    if(head->next == NULL) 
    {
        if(head->info == data)
        {
            temp = head;
            head = NULL;
            free(temp);
        }
            else 
            {
                printf("element %d is not there", data);
                return head;
            }
    }
    
    // case 3
    if(head->info == data)
    {
        head = temp;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head ;
    }

//case 4
    p = head;
    if(p)
    {
        while(p->next != NULL)
        {
            if(p->info == data)
            {
                p->prev->next = p->next ;
                p->next->prev = p->prev;
                free(p);
                return head;

            }
            p->next = p;
        }
    }

    //case 5
    p =  head ;
    if(p)
    {
        while(p->next != NULL)
        {
               p->prev->next = NULL;
               free(p);
               return head ;
        }
    }

}

/*disadvantages :
1 this will occpy more space and memroy is used more than SLL
2 we have to modify more no of pointer if u what to insert ot delete in list */
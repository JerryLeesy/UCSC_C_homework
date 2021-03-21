#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}node;

node * DlListcreation(int n);
node * sort_lined_list(node *head);
node * remove_repeated_num(node * head);
void displaylist(node *head);
void deleteNode(node * head, node * del);

int main()
{
    int n = 100;
    node * stnode = NULL;
    node * ennode = NULL;
    node * sorted_HEAD = NULL;
    node * cleaned_HEAD = NULL;
    stnode = DlListcreation(n);
    printf("the original list is: \n");
    displaylist(stnode);
    sorted_HEAD = sort_lined_list(stnode);
    printf("\nthe sorted list is: \n");
    displaylist(sorted_HEAD);
    cleaned_HEAD = remove_repeated_num(stnode);
    printf("\nthe cleanned list is: \n");
    displaylist(cleaned_HEAD);

    return 0;
}

node * DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;
    node * stnode = NULL;
    node * ennode = NULL;
    if(n >= 1)
    {
        stnode = (node *)malloc(sizeof(struct node));

        if(stnode != NULL)
        {
           // printf(" Input data for node 1 : "); // assigning data in the first node
           // scanf("%d", &num);
            num = rand() %(49 - 0 + 1) + 0;

            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;
// putting data for rest of the nodes
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                  //  printf(" Input data for node %d : ", i);
                   // scanf("%d", &num);
                    num = rand() %(49 - 0 + 1) + 0;
                    fnNode->num = num;
                    fnNode->preptr = ennode;    // new node is linking with the previous node
                    fnNode->nextptr = NULL;

                    ennode->nextptr = fnNode;   // previous node is linking with the new node
                    ennode = fnNode;            // assign new node as last node
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
    return stnode;
}

void displaylist(node * head)
{
    node * p = head;
    int i =0;
    while(p !=NULL)
    {
    printf("%d ", p->num);
    i++;
    if (i == 5) //print every 5 values in a row
    {
        printf("\n");
        i = 0;
    }
    p = p->nextptr;
    }

}

node * sort_lined_list(node * head)
{
    while(1)
    {

    int swapped = 0;
    node * p = head;
    while(p->nextptr !=NULL)
     {
      int p1 = p->num;
      int p2 = p->nextptr->num;
      if(p1 > p2)
        {
            p->num = p2;
            p->nextptr->num = p1;
            swapped = 1;
        }

      p = p->nextptr;
     }
        if (swapped == 0) //if swapped == 0, there is no values need to be swapped, thus the list is sortd
        {
            break;
        }

    }

    return head;
}


void deleteNode(node * head, node * del)   // del: pointer to node to be deleted.
{
    /* base case */
    if (head == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (head == del)
        head = del->nextptr;

    /* Change next only if node to be deleted
        is NOT the last node */
    if (del->nextptr != NULL)
        del->nextptr->preptr = del->preptr;

    /* Change prev only if node to be deleted
       is NOT the first node */
    if (del->preptr != NULL)
        del->preptr->nextptr = del->nextptr;

    /* Finally, free the memory occupied by del*/
    free(del);
}

node * remove_repeated_num(node * head)
{
    //node * current_node = NULL;
    if(head == NULL)
    {
        return head;
    }

    node * current_node = head;

    while(current_node->nextptr != NULL)
    {
        // if current node equals to its next node, delete the next node
        if(current_node->num == current_node->nextptr->num)
        {
            deleteNode(head, current_node->nextptr);
        }
        else
        {
            current_node = current_node->nextptr;
        }
    }
    return head;
}

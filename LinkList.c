#include<stdio.h>
#include<malloc.h>


struct node
{
    int item;
    struct node * next;
};

struct node * head;

int main()
{
    head = NULL;
    input_function();
}

/*

This an insert function, will insert element at the end of link list.
If the list is initially empty, will create a new node.
*/

void insert()
{
    int element;
    printf("Please enter a number\n");
    scanf("%d", &element);

     struct node * temp;
     temp = (struct node*)malloc(sizeof(struct node));

     temp->item = element;
     temp->next = NULL;

     if(head == NULL)
     {
         head = temp;
     }
     else
     {
         struct node * prev = head;

        while(prev->next != NULL)
            prev = prev-> next;
         temp->next = prev->next;
         prev->next = temp;
     }

}

/*Insert element after specific element*/

void insert_specific_element()
{

}


/*Insert element at the beginning of list*/
void insert_beginning()
{
    int item;
    printf("Enter a number\n");
    scanf("%d",&item);

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->item = item;
    temp-> next = NULL;

    if(head == NULL)
        head = temp;
    temp->next = head;
    head = temp;


}


/*Print the entire list */
void printList()
{
    struct node * temp;

    if(head == NULL)
    {

        printf("\n\nThere is no element in the list\n\n\n");
        return ;
    }

    printf("\n\nThe elements in the list : \n");
    if(head->next == NULL)
    {
        printf("%d\n\n",head->item);

    }
    else
    {

        temp = head;

        while(temp -> next != NULL)
        {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("%d ",temp->item);
        printf("\n\n");

    }

}

/*Delete element at the beginning of the list*/

void delete_beginning()
{
    struct node * temp;

    if(head == NULL)
    {
        printf("There is no element in the list to delete\n");
        return;
    }

    temp = head;
    head = head-> next;
    free(temp);
}

/*Delete element from the end of list*/
void delete_from_end()
{
    struct node * temp, * prev;

    if(head == NULL)
    {
        printf("There is no element in the list to delete\n");
        return;
    }
     temp = head;
     while(temp->next != NULL)
     {
        prev = temp;
        temp = temp->next;
     }
     prev->next = temp->next;
     free(temp);
}




/*This function will print options and take input from user*/
void input_function()
{
    int option = 0;
    while(1)
    {
        printf("Choose the following option:\n");
        printf("1.Insert element in link list\n");
        printf("2.Print the link list\n");
        printf("3.Insert element after a specific element\n");
        printf("4.Insert element at the beginning of link list\n");
        printf("5.Delete element at the beginning of link list\n");
        printf("6.Delete element at the end of link list\n");
        printf("7.Delete a specific element from link list\n");
        printf("8. Search an element from link list\n");

        scanf("%d",&option);

        switch(option)
        {
            case 1 :
                {
                    insert();
                    break;
                }
            case 2 :
                {
                    printList();
                    break;
                }
            case 3:
                {
                    insert_specific_element();
                    break;
                }
            case 4:
                {
                    insert_beginning();
                }
            case 5:
                {
                    delete_beginning();
                    break;
                }
            case 6:
                {
                    delete_from_end();
                    break;
                }

        }

    }


}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void driverf(int choice, int value);
void display();
int checkEmpty();

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAtPosition(int value, int position);

void deleteAtBeginning(int value);
void deleteAtEnd(int value);
void deleteAtPosition(int value, int position);

int main()
{
    int choice;
    int value;
    char c;
    do
    {
        printf("Enter:\n1-Insert at beginning.\n");
        printf("2-Insert at the end.\n");
        printf("3-Insert at a position.(count strated from 0)\n");
        printf("\n4-Delete at beginning.\n");
        printf("5-Delete at the end.\n");
        printf("6-Delete at a position.(count strated from 1)\n");
        printf("\n7-display.\n\n");

        printf("Choice: ");
        scanf("%d", &choice);

        driverf(choice, value);

        printf("Enter 'y' to continue else any letter: ");
        fflush(stdin);
        c = getche();
        printf("\n");

    } while (c == 'y' || c == 'Y');

    return 0;
}

//**************** Inserting at the beginning ****************
void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("%d iserted successfully at the beginning.\n", value);
}

// **************** Inserting at the end ****************

void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted successfully at the end.\n", value);
}

// **************** Inserting at a specified position ****************

void insertAtPosition(int value, int position)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp;
        temp = head;
        if (position == 0)
        {
            insertAtBeginning(value);
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    printf("%d inserted at %d successfully.\n", value, position);
}

// **************** Deleting at the beginning ****************

void deleteAtBeginning(int value)
{
    if (head == NULL)
        printf("List is already empty.\n");
    else
    {
        struct Node *temp;
        temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
            printf("** Deleted successfully at the beginning.\n");
        }
    }
}

// **************** Deleting at the end ****************

void deleteAtEnd(int value)
{
    if (head == NULL)
        printf("List is already empty!");
    else
    {
        struct Node *temp, *temp1;
        temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = NULL;
            free(temp);
            printf("** Deleted successfully at the end.\n");
        }
    }
}

// **************** Deleting at a specified position ****************

void deleteAtPosition(int value, int position)
{
    int i, flag = 0;
    struct Node *temp1 = head, *temp2;
    if (position == 1)
    {
        head = temp1->next;
        free(temp1);
        printf("Node deleted");
    }
    else
    {
        for (i = 0; i < position - 1; i++)
        {
            if (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            temp2->next = temp1->next;
            free(temp1);
            printf("\nNode deleted.\n");
        }
        else
        {
            printf("Position exceeds linked list. please try again!");
        }
    }
}

// driver program
void driverf(int choice, int value)
{
    switch (choice)
    {
        int position;
    case 1:
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtBeginning(value);
        break;
    case 2:
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtEnd(value);
        break;
    case 3:
        printf("Enter value: ");
        scanf("%d", &value);
        printf("Enter position: ");
        scanf("%d", &position);
        insertAtPosition(value, position);
        break;

    case 4:
        deleteAtBeginning(value);
        break;
    case 5:
        deleteAtEnd(value);
        break;
    case 6:
        printf("Enter position: ");
        scanf("%d", &position);
        deleteAtPosition(value, position);
        break;

    case 7:
        display();
        break;
    default:
        printf("Enter a valid choice!");
        break;
    }
}

void display()
{
    int flag = checkEmpty();
    if (flag == 1)
    {
        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
        printf("\n");
    }
    else
        printf("NO list is avialable! \n");
}

int checkEmpty()
{
    if (head == NULL)
        return 0;
    else
        return 1;
}

// edit by: Mohammed El Idrissi Laoukili, Student at FSDM
// check out idri.netlify.app
// YouTube1 idriLogic
// YouTube2 idriCoding
// Instagram idriLogic

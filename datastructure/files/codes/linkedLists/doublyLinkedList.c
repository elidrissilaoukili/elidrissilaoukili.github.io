#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *head = NULL;

void driverf(int choice);
int getValue(int value);
int getPostion(int position);
int getDelValue(int delValue);
void display();

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAtPosition(int value, int position);

void deleteAtBeginning();
void deleteAtEnd();
void deleteAtSpecific(int delValue);
void deleteAtPosition(int position);

int main()
{
    int choice;
    char c;

    do
    {
        printf("Enter:\n1-Insert at the beginning.\n");
        printf("2-Insert at the end.\n");
        printf("3-Insert at a position.(Count from 0)\n\n");
        printf("4-Delete at the beginning.\n");
        printf("5-Delete at the end.\n");
        printf("6-Delete specific value.\n");
        printf("7-Delete at a position.\n\n8-Display.\n");

        printf("\nChoice: ");
        scanf("%d", &choice);

        driverf(choice);

        printf("Enter Y to continue else any letter: ");
        fflush(stdin);
        c = getche();
        printf("\n");
    } while (c == 'y' || c == 'Y');

    return 0;
}

// **************** Inserting at the beginning ****************
void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}

// **************** Inserting at the end ****************
void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;

    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("%d inserted at the end.\n", value);
}

// **************** Inserting at specified position ****************
void insertAtPosition(int value, int position)
{
    int flag = 1;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        if (position == 0)
            insertAtBeginning(value);
        else
        {
            struct Node *temp = head;
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->next;
                if (temp->next == NULL)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
                printf("%d inserted at position %d.\n", value, position);
            }
            else
            {
                printf("Position not correct.\n");
            }
        }
    }
}

// **************** Deletion at the beginning ****************
void deleteAtBeginning()
{
    if (head == NULL)
        printf("List is empty.\n");
    else
    {
        struct Node *temp = head;
        if (temp->prev == temp->next)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            temp->prev = NULL;
            free(temp);
        }
        printf("Element deleted from the beginnig.\n");
    }
}

// **************** Deletion at the end ****************
void deleteAtEnd()
{
    if (head == NULL)
        printf("List is empty.\n");

    else
    {
        struct Node *temp = head;
        if (temp->prev == temp->next)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
                temp = temp->next;

            temp->prev->next = NULL;
            free(temp);
        }
        printf("Element remove from the end of the list.\n");
    }
}

// **************** Deletion at a specified position ****************
void deleteAtPosition(int position)
{
    struct Node *temp;
    int i;
    temp = head;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (position == 1)
        deleteAtBeginning();

    else
    {
        if (temp != NULL)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            free(temp); // Delete the n Node
        }
    }
}

// **************** Delete a specified value ****************
void deleteAtSpecific(int delValue)
{
    if (head == NULL)
        printf("List is already empty.\n");

    else
    {
        struct Node *temp = head;
        while (temp->data != delValue)
        {
            if (temp->next == NULL)
                printf("Given node is not found!\n");
            else
                temp = temp->next;
        }
        if (temp == head)
        {
            head == NULL;
            free(temp);
        }
        else
        {
            temp->prev->next = temp->next;
            free(temp);
        }
        printf("%d deleted successfully.\n", delValue);
    }
}

void driverf(int choice)
{
    int value, position, delValue;
    switch (choice)
    {
    case 1:
        value = getValue(value);
        insertAtBeginning(value);
        break;
    case 2:
        value = getValue(value);
        insertAtEnd(value);
        break;
    case 3:
        value = getValue(value);
        position = getPostion(position);
        insertAtPosition(value, position);
        break;

    case 4:
        deleteAtBeginning();
        break;
    case 5:
        deleteAtEnd();
        break;
    case 6:
        delValue = getDelValue(delValue);
        deleteAtSpecific(delValue);
        break;
    case 7:
        position = getPostion(position);
        deleteAtPosition(position);
        break;

    case 8:
        display();
        break;

    default:
        printf("Enter a valid choice!\n");
        break;
    }
}

int getValue(int value)
{
    printf("Value: ");
    scanf("%d", &value);
    return value;
}

int getPostion(int position)
{
    printf("Position: ");
    scanf("%d", &position);
    return position;
}

int getDelValue(int delValue)
{
    printf("Deleted value: ");
    scanf("%d", &delValue);
    return delValue;
}

void display()
{
    if (head == NULL)
        printf("List is empty.\n");
    else
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
}

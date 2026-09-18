#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Insert at Start
void insertStart()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at End
void insertEnd()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert in Middle
void insertMiddle()
{
    int value, pos;

    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter value: ";
    cin >> value;

    if (pos == 1)
    {
        insertStart();
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete at Start
void deleteStart()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;

    cout << "Node deleted\n";
}

// Delete at End
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    delete temp;

    cout << "Node deleted\n";
}

// Delete in Middle
void deleteMiddle()
{
    int pos;

    cout << "Enter position: ";
    cin >> pos;

    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (pos == 1)
    {
        deleteStart();
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;

    cout << "Node deleted\n";
}

// Display Normal
void displayNormal()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    cout << "Normal: ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Display Reverse
void displayReverse()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    cout << "Reverse: ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n----- DOUBLY LINKED LIST -----\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert in Middle\n";
        cout << "3. Insert at End\n";
        cout << "4. Delete at Start\n";
        cout << "5. Delete in Middle\n";
        cout << "6. Delete at End\n";
        cout << "7. Display Normal\n";
        cout << "8. Display Reverse\n";
        cout << "9. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertStart();
                break;

            case 2:
                insertMiddle();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteStart();
                break;

            case 5:
                deleteMiddle();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                displayNormal();
                break;

            case 8:
                displayReverse();
                break;

            case 9:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}
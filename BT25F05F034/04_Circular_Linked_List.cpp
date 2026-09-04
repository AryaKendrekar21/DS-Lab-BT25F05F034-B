#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at end
void insert()
{
    int value;

    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Delete first node
void deleteNode()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    delete temp;

    cout << "Node deleted\n";
}

// Display
void display()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    cout << "Circular Linked List: ";

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    while (temp != head);

    cout << "HEAD\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
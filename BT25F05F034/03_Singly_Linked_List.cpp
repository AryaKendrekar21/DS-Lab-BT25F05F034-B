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
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
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

    Node *temp = head;
    head = head->next;

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

    cout << "Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
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
#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Insert
void insert()
{
    int value;

    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is Full\n";
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}

// Delete
void deleteElement()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Deleted: " << queue[front] << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Display
void display()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";

    int i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
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
                deleteElement();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
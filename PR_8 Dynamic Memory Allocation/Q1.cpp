#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

class LinkList
{
public:
    Node *head;

    LinkList()
    {
        this->head = nullptr;
    }

    void InsertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << endl
             << value << " " << "Insert Value!" << endl;
    }

    void search(int key)
    {
        cout << endl;
        Node *current = head;
        int position = 0;

        while (current)
        {
            if (current->data == key)
            {
                cout << endl;
                cout << key << " " << "Found the Position" << " " << position << endl;
                return;
            }
            current = current->next;
            position++;
        }
    }

    void deleteNode(int key)
    {
        if (!head)
            return;

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next && current->next->data != key)
        {
            current = current->next;
        }

        if (current->next)
        {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << key << " " << "Delete Value!"<<endl;
        }
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;

        while (current)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << endl;
        cout << endl
             << "List Reveresed" << endl;
    }

    void Display()
    {
        Node *current = head;
        cout << endl;
        cout << "Link List:" << endl;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
    }
};

int main()
{
    LinkList list;
    int choice, value;

    do
    {
        cout << endl;
        cout << "*** Menu ***" << endl;
        cout << "1. Insert At Beginning" << endl;
        cout << "2. Search For Value" << endl;
        cout << "3. Delete A Value" << endl;
        cout << "4. Reverse The List" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Enter Your Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value To Insert:";
            cin >> value;
            list.InsertAtBeginning(value);
            break;

        case 2:
            cout << "Enter Value To Search:";
            cin >> value;
            list.search(value);
            break;

        case 3:
            cout << "Enter Value To Delete:";
            cin >> value;
            list.deleteNode(value);
            break;

        case 4:
            list.reverse();
            break;

        case 5:
            list.Display();
            break;

        case 6:
            cout << "Exit Program" << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
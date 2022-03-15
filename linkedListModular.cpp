#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *nextLink;
};
node *head = NULL;
int count = 0;
void insertAtEnd()
{
    int x;
    cout << "\nEnter element " << endl;
    cin >> x;
    node *temp, *value;
    value = new node();
    value->data = x;
    if (head == NULL)
    {
        head = value;
        //  value->nextLink = NULL;
        head->nextLink = NULL;
        value->nextLink = NULL;
    }
    else
    {
        temp = head;
        while (temp->nextLink != NULL)
        {
            temp = temp->nextLink;
        }

        temp->nextLink = value;
        value->nextLink = NULL;
    }
    count++;
}

void insertAtindex()
{
    int element, x;
    cout << "\nEnter element" << endl;
    cin >> element;
    cout << "Enter position (You can not enter At first and last position)" << endl;
    cin >> x;
    node *temp = head, *val;
    val = new node();
    val->data = element;
    if (x == 1 || x == count + 1)
    {
        cout << "\nChoose valid index for this function";
    }
    else
    {
        int i = 1;
        while (i != (x - 1))
        {
            temp = temp->nextLink;
            i++;
        }
        val->nextLink = temp->nextLink;
        temp->nextLink = val;
        cout << endl
             << element << " Successfully inserted at " << x << " postion";
        count++;
    }
}

void insertAtBeg()
{
    node *val;
    int value;
    cout << "\nEnter Value to enter " << endl;
    cin >> value;
    val = new node();
    val->data = value;

    val->nextLink = head;
    head = val;
}

void deleteAtBeg()
{
    node *temp;
    temp = head;
    head = head->nextLink;
    delete temp;
    count--;
}

void display()
{
    node *temp;
    temp = head;
    if (temp == NULL)
        cout << "\nList is Empty";
    else
    {
        cout << endl;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->nextLink;
        }
        cout << "NULL";
        cout << "\nThere are " << count << " elements in this list";
    }
}
void deleteAtEnd()
{
    node *del, *temp = head;
    while (temp->nextLink->nextLink != 0)
    {
        temp = temp->nextLink;
    }
    del = temp->nextLink;
    temp->nextLink = NULL;
    delete del;
    count--;
    display();
}
bool search()
{
    int key;
    cout << "\nEnter value " << endl;
    cin >> key;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->nextLink;
    }
    return false;
}
void deleteAtPos()
{
    node *temp = head, *del = head->nextLink;
    int pos, i = 1;
    cout << "\nEnter position of element";
    cin >> pos;
    if (temp == NULL)
    {
        cout << "\nList is underFlow";
    }
    else if (pos == 1)
        deleteAtBeg();
    else if (pos == count)
        deleteAtEnd();
    else
    {
        for (i; i < (pos - 1); i++)
        {
            temp = temp->nextLink;
            del = del->nextLink;
        }
        temp->nextLink = del->nextLink;

        delete del;
        count--;
        cout << "\ndeleted Succuessfully!";
    }
}
int main()
{
    /*
    node *val1, *val2, *val3, *val4, *head, *tail;
    val1 = (class node *)malloc(sizeof(node));

    head = val1;
    val1->data = 10;
    val2 = (class node *)malloc(sizeof(node));
    val2->data = 20;
    val3 = (class node *)malloc(sizeof(node));
    val3->data = 30;
    val1->nextLink = val2;
    val2->nextLink = val3;
    val3->nextLink = NULL;
    tail = val3;

    display(head);

    insertAtEnd(5);
    insertAtEnd(4);
    insertAtEnd(1);
    insertAtEnd(15);
    insertAtEnd(8);
    //  insertAtBeg(3);
    //  insertAtBeg(2);
    //  delFromEnd();
    display();
    insertAtindex(50, 4);
    insertAtindex(100, 6);
    display();

    if (search(2))
        cout << "\nElement is in the List ";
    else
        cout << "\nElement not found in the List ";

    //   insertAtPos(3);

    // deleteAtBeg();
    // display();
    // deleteAtEnd();
*/

    int key, i;
    i = 0;
    do
    {
        cout << "\n1.insertAtEnd     2.insertAtBeg   3.insertAtindex    4.Display  " << endl;
        cout << "5.deleteAtBeg     6.deleteAtEnd      7.Search    8.Exit    9.deleteAtPos " << endl;
        cin >> key;
        switch (key)
        {
        case 1:
            insertAtEnd();
            break;
        case 2:
            insertAtBeg();
            break;
        case 3:
            insertAtindex();
            break;
        case 4:
            display();
            break;
        case 5:
            deleteAtBeg();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            if (search())
                cout << "\nElement is in the List ";
            else
                cout << "\nElement not found in the List ";

            break;

        case 8:
            return i = 8;
            break;
        case 9:
            deleteAtPos();
            break;
        default:
            cout << "\nChoose valid option";
        }
    } while (i != 9);

    return 0;
}
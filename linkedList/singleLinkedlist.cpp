#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
    static void print(node *&head)
    {
        node *t = head;
        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
    }
    static void addAtHead(node *&head, int d)
    {
        node *t = new node(d);
        t->next = head;
        head = t;
    }
    static void addAtTail(node *&tail, int d)
    {
        node *t = new node(d);
        tail->next = t;
        tail = t;
    }
    static void addPos(node *&head, node *&tail, int pos, int d)
    {
        if (pos == 1)
        {
            addAtHead(head, d);
            return;
        };
        node *t = head;
        node *temp = new node(d);
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        if (t->next == NULL)
        {
            addAtTail(tail, d);
            return;
        }
        temp->next = t->next;
        t->next = temp;
    }
    static void deleteAthead(node *&head)
    {
        if (head == NULL)
            return;
        node *t = head;
        head = head->next;
        delete t;
    }
    static void deleteAtTail(node *&head, node *&tail)
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        node *cur = head;
        node *prev = NULL;
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        tail = prev;
        delete cur;
    }
    static void deleteAtpos(node *&head, int pos)
    {
        if (pos == 1)
        {
            deleteAthead(head);
            return;
        }
        node *cur = head;
        node *prev = NULL;
        for (int i = 1; i < pos; i++)
        {
            prev = cur;
            cur = cur->next;
            if (cur == NULL)
                return;
        }
        prev->next = cur->next;
        delete cur;
    }
    static void Reverse(node *&head)
    {
        node *prev = NULL;
        node *cur = head;
        node *forward = NULL;
        while (cur != NULL)
        {
            forward = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forward;
        }
        head = prev;
    }
};
int main()
{
    node *n1 = new node(20);
    node *head = n1;
    node *tail = n1;
    // node::print(head);
    node::addAtHead(head, 10);
    node::addAtTail(tail, 30);
    node::addPos(head, tail, 2, 40);
    node::print(head);
    node::Reverse(head);
    cout << endl; 
    node::print(head);
    return 0;
}  

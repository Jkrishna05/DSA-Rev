#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
    static void print(Node *&head)
    {
        Node *t = head;
        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
    }
    static void addatHead(Node *&head,Node *&tail, int d)
    {
        if(head == NULL)
        {
            head = new Node(d);
            tail = head;
            return;
        }
        Node *t = new Node(d);
        t->next = head;
         head->prev = t;
        head = t;
    }
    static void addatTail(Node *&head,Node *&tail, int d)
    {
        if(tail == NULL)
        {
            tail = new Node(d);
            head = tail;
            return;
        }
        Node *t = new Node(d);
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
    static void addatPos(Node *&head,Node *&tail, int pos, int d)
    {
        if(pos == 1)
        {
            addatHead(head,tail,d);
            return;
        }
        Node *t = head;
        Node *temp = new Node(d);
        for(int i=1;i<pos-1;i++)
        {
            t = t->next;
        }
        if(t->next == NULL)
        {
            addatTail(head,tail,d);
            return;
        }
        temp->next = t->next;
        t->next->prev = temp;
        t->next = temp;
        temp->prev = t;
    }   
     static void deleteAthead(Node *&head)
    {
        if (head == NULL)
            return;

        Node *t = head;
        head = head->next;
        head->prev = NULL;
        delete t;
    }
    static void deleteAtTail(Node *&head,Node *&tail)
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *cur = head;
        Node *back = NULL;
        while (cur->next != NULL)
        {
            back = cur;
            cur = cur->next;
        }
        back->next = cur->next;
        tail = back;
        delete cur;
    }
    static void deleteAtpos(Node *&head, int pos)
    {
        if (pos == 1)
        {
            deleteAthead(head);
        }
            Node *cur = head;
        Node *back = NULL;
        for (int i = 1; i < pos; i++)
        {
            back = cur;
            cur = cur->next;
            if (cur == NULL)
                return;
        }
        back->next = cur->next;
        cur->next->prev = back;
        delete cur;
    }

};
int main(){
        Node *head = NULL;
        Node *tail = NULL;
        Node::addatHead(head,tail,10);
        Node::addatTail(head,tail,20);
        Node::addatTail(head,tail,30);
        Node::addatTail(head,tail,40);
        Node::addatTail(head,tail,50);
        Node::addatTail(head,tail,60);
        Node::addatTail(head,tail,70);
        Node::addatTail(head,tail,80);
        Node::addatTail(head,tail,90);
        Node::addatTail(head,tail,100);
        cout<<"Before deletion: ";
        Node::print(head);
        cout<<endl;
        cout<<"After deletion at head: ";
        Node::deleteAthead(head);
        Node::print(head);
         cout<<endl;
  cout<<"head : "<<head->data<<endl;
  cout<<"tail : "<<tail->data<<endl;
    return 0;
}
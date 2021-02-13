#include<iostream>
#include<stdlib.h>
using namespace std;
class SinglyLinkedList
{
    struct node
    {
        int data;
        node* next;
    };
    struct node* head = NULL;

    int temp_reverse(struct node* temp)
    {
        if(temp==NULL)
        {
            cout<<"reverse: ";
            return 0;
        }
        temp_reverse(temp->next);

        cout<<temp->data<<" ";
    }

    public:
    void insert_beg(int x)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));

        if(head == NULL)
        {
            new_node->data = x;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            new_node->data = x;
            new_node->next = head;
            head = new_node;
        }
        display();
    }
    void insert_end(int x)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        if(head == NULL)
        {
            new_node->data = x;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            new_node->data = x;
            new_node->next = NULL;

            struct node* temp = head;

            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        display();
    }
    void insert_at_n(int x, int n)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        if(head == NULL && n==0)
        {
            new_node->data = x;
            new_node->next = NULL;
            head = new_node;
        }
        else if(head == NULL && n>0)
        {
            cout<<"Invalid Index"<<endl;
        }
        else if(n==0)
        {
            insert_beg(x);
        }
        else
        {
            struct node* temp = head;
            bool valid = true;

            while(--n)
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    cout<<"Invalid Index"<<endl;
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                new_node->data = x;

                new_node->next = temp->next;
                temp->next = new_node;
            }
            display();
        }
    }
    void delete_from_beg()
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head;
            head = head->next;
            temp->next = NULL;
        }
        display();
    }
    void delete_from_end()
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head;
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        display();
    }
    void delete_from_n(int n)
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else if(n==0)
        {
            struct node* temp = head;
            head = head->next;
            temp->next = NULL;
        }
        else
        {
            struct node* temp = head;
            bool valid = true;
            while(--n)
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    cout<<"Invalid Index"<<endl;
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                temp->next = temp->next->next;
            }
        }
        display();
    }
    void delete_the_element(int x)
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            bool found = false;
            int n = 0;
            struct node* temp = head;
            while(temp!=NULL)
            {
                if(temp->data == x)
                {
                    delete_from_n(n);
                    n--;
                    found = true;
                }
                temp = temp->next;
                n++;
            }
            if(!found)
            {
                cout<<"The element "<<x<<" is not present in list"<<endl;
            }
        }
    }
    void reverse_display()
    {
        if(head==NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head;
            temp_reverse(temp);
            cout<<endl;
        }
    }


    void display()
    {
        struct node *temp;
        if(head==NULL)
        {
            cout<<"list is empty\n\n";
        }
        else
        {
            temp = head;
            cout<<"Singly linked list: ";
            while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        cout<<"\n\n";
    }
    void custom_display()
    {
        struct node *temp;
        if(head==NULL)
        {
            cout<<"list is empty\n\n";
        }
        else
        {
            temp = head;
            cout<<"|"<<head<<"|-->";
            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"-"<<temp->next<<"|";
                if(temp->next!=NULL)
                {
                    cout<<"-->";
                }
                temp = temp->next;
            }
        }
        cout<<"\n\n";
    }
};

class DoublyLinkedList
{
    struct node
    {
        int data;
        node* next;
        node* previous;
    };
    struct node* head = NULL;
    public:

    void insert_beg(int x)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));

        if(head == NULL)
        {
            new_node->data = x;
            new_node->previous = NULL;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            new_node->data = x;
            new_node->next = head;
            new_node->previous = NULL;
            head->previous = new_node;
            head = new_node;
        }
        display();
    }
    void insert_end(int x)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        if(head == NULL)
        {
            new_node->data = x;
            new_node->next = NULL;
            new_node->previous = NULL;
            head = new_node;
        }
        else
        {
            new_node->data = x;
            new_node->next = NULL;

            struct node* temp = head;

            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            new_node->previous = temp;
            temp->next = new_node;
        }
        display();
    }
    void insert_at_n(int x, int n)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        if(head == NULL && n==0)
        {
            new_node->data = x;
            new_node->next = NULL;
            new_node->previous = NULL;
            head = new_node;
        }
        else if(head == NULL && n>0)
        {
            cout<<"Invalid Index"<<endl;
        }
        else if(n==0)
        {
            insert_beg(x);
        }
        else
        {
            struct node* temp = head;
            bool valid = true;

            while(--n)
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    cout<<"Invalid Index"<<endl;
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                if(temp->next==NULL)
                {
                    new_node->previous = temp;
                    temp->next = new_node;
                }
                else
                {
                    new_node->data = x;
                    new_node->next = temp->next;
                    temp->next->previous = new_node;
                    temp->next = new_node;
                    new_node->previous = temp;
                }
            }
            display();
        }
    }
    void delete_from_beg()
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head;
            head = head->next;
            temp->next = NULL;
            head->previous = NULL;
        }
        display();
    }
    void delete_from_end()
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head;
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        display();
    }
    void delete_from_n(int n)
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else if(n==0)
        {
            struct node* temp = head;
            head = head->next;
            temp->next = NULL;
            head->previous = NULL;
        }
        else
        {
            struct node* temp = head;
            bool valid = true;
            while(--n)
            {
                temp = temp->next;
                if(temp==NULL)
                {
                    cout<<"Invalid Index"<<endl;
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                if(temp->next->next!=NULL)
                {
                    temp->next->next->previous = temp;
                }
                temp->next = temp->next->next;
            }
        }
        display();
    }
    void delete_the_element(int x)
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            bool found = false;
            int n = 0;
            struct node* temp = head;
            while(temp!=NULL)
            {
                //cout<<temp->data<<"  ";
                if(temp->data == x)
                {
                    delete_from_n(n);
                    n--;
                    found = true;
                }
                temp = temp->next;
                n++;
            }
            if(!found)
            {
                cout<<"The element "<<x<<" is not present in list"<<endl;
            }
        }
    }
    void display()
    {
        struct node *temp;
        if(head==NULL)
        {
            cout<<"list is empty\n\n";
        }
        else
        {
            temp = head;
            cout<<"Doubly linked list: ";
            while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        cout<<"\n\n";
    }
    void custom_display()
    {
        struct node *temp;
        if(head==NULL)
        {
            cout<<"list is empty\n\n";
        }
        else
        {
            temp = head;
            cout<<"|"<<head<<"|-->";
            while(temp != NULL)
            {
                cout<<"|"<<temp->previous<<"-"<<temp->data<<"-"<<temp->next<<"|";
                if(temp->next!=NULL)
                {
                    cout<<"<-->";
                }
                temp = temp->next;
            }
        }
        cout<<"\n\n";
    }
    void reverse_display()
    {
        if(head==NULL)
        {
            cout<<"List is empty!"<<endl;
        }
        else
        {
            struct node* temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            cout<<"reverse: ";
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->previous;
            }
            cout<<endl;
        }
    }
};


class SinglyCircularLinkedList
{
    struct node
    {
        int data;
        node* next;
    };
    struct node* head = NULL;
    public:

    void insert_beg(int x)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));

        if(head == NULL)
        {
            new_node->data = x;
            new_node->next = new_node;
            head = new_node;
        }
        else
        {
            new_node->data = x;
            new_node->next = head;
            struct node* temp = head->next;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next = new_node;
            head = new_node;
        }
        display();
    }
    void insert_end(int x)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        if(head == NULL)
        {
            new_node->data = x;
            new_node->next = new_node;
            head = new_node;
        }
        else
        {
            new_node->data = x;
            new_node->next = head;

            struct node* temp = head->next;

            while(temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        display();
    }
    void insert_at_n(int x, int n)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        if(head == NULL && n==0)
        {
            new_node->data = x;
            new_node->next = new_node;
            head = new_node;
        }
        else if(head==NULL && n>0)
        {
            cout<<"Invalid Index"<<endl;
        }
        else if(n==0)
        {
            insert_beg(x);
        }
        else
        {
            struct node* temp = head->next;
            bool valid = true;
            n--;
            if(n==0)
            {
                new_node->data = x;
                new_node->next = head->next;
                head->next = new_node;
            }
            else
            {
                while(--n)
                {
                    temp = temp->next;
                    if(temp==head)
                    {
                        cout<<"Invalid Index"<<endl;
                        valid = false;
                        break;
                    }
                }
                if(valid)
                {
                    new_node->data = x;
                    new_node->next = temp->next;
                    temp->next = new_node;
                }
            }
            display();
        }
    }
    void delete_from_beg()
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head->next;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        display();
    }
    void delete_from_end()
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else
        {
            struct node* temp = head->next;
            while(temp->next->next!=head)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
        display();
    }
    void delete_from_n(int n)
    {
        if(head == NULL)
        {
            cout<<"List is already empty!"<<endl;
        }
        else if(n==0)
        {
            struct node* temp = head;
            head = head->next;
            temp->next = head;
        }
        else
        {
            struct node* temp = head->next;
            bool valid = true;
            n--;
            if(n==0)
            {
                temp->next = temp->next->next;
            }
            else if(n==1 && head == head->next->next)
            {
                cout<<"Invalid Index"<<endl;
            }
            else
            {
                while(--n)
                {
                    temp = temp->next;
                    if(temp->next==head)
                    {
                        cout<<"Invalid Index"<<endl;
                        valid = false;
                        break;
                    }
                }
                if(valid)
                {
                    temp->next = temp->next->next;
                }
            }
        }
        display();
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"list is empty\n\n";
        }
        else if (head == head->next)
        {
            cout<<head->data;
        }
        else
        {
            struct node* temp = head->next;
            cout<<"Singly linked list: ";
            cout<<head->data<<" ";
            while(temp != head)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        cout<<"\n\n";
    }
    void custom_display()
    {
        struct node *temp;
        if(head==NULL)
        {
            cout<<"list is empty\n\n";
        }
        else
        {
            temp = head->next;
            cout<<"|"<<head<<"|-->";
            cout<<"|"<<head->data<<"-"<<head->next<<"|-->";
            while(temp != head)
            {
                cout<<"|"<<temp->data<<"-"<<temp->next<<"|-->";
                if(temp->next==head)
                {
                    cout<<"(first_node)";
                }
                temp = temp->next;
            }
        }
        cout<<"\n\n";
    }
};














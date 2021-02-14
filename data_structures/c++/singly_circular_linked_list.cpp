#include<bits/stdc++.h>
using namespace std;

struct node
{
        int data;
        node *next;
};
struct node *head = NULL;

void display()
{
        if (head == NULL)
        {
                cout << "list is empty\n\n";
        }
        else if (head == head->next)
        {
                cout << "Singly linked list: " << head->data;
        }
        else
        {
                struct node *temp = head->next;
                cout << "Singly linked list: ";
                cout << head->data << " ";
                while (temp != head)
                {
                        cout << temp->data << " ";
                        temp = temp->next;
                }
        }
        cout << "\n\n";
}

void insert_beg(int x)
{
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        if (head == NULL)
        {
                new_node->data = x;
                new_node->next = new_node;
                head = new_node;
        }
        else
        {
                new_node->data = x;
                new_node->next = head;
                struct node *temp = head->next;
                while (temp->next != head)
                {
                        temp = temp->next;
                }
                temp->next = new_node;
                head = new_node;
        }
        display();
}
void insert_end(int x)
{
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
                new_node->data = x;
                new_node->next = new_node;
                head = new_node;
        }
        else
        {
                new_node->data = x;
                new_node->next = head;

                struct node *temp = head->next;

                while (temp->next != head)
                {
                        temp = temp->next;
                }
                temp->next = new_node;
        }
        display();
}
void insert_at_n(int x, int n)
{
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL && n == 0)
        {
                new_node->data = x;
                new_node->next = new_node;
                head = new_node;
        }
        else if (head == NULL && n > 0)
        {
                cout << "Invalid Index" << endl;
        }
        else if (n == 0)
        {
                insert_beg(x);
        }
        else
        {
                struct node *temp = head->next;
                bool valid = true;
                n--;
                if (n == 0)
                {
                        new_node->data = x;
                        new_node->next = head->next;
                        head->next = new_node;
                }
                else
                {
                        while (--n)
                        {
                                temp = temp->next;
                                if (temp == head)
                                {
                                        cout << "Invalid Index" << endl;
                                        valid = false;
                                        break;
                                }
                        }
                        if (valid)
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
        if (head == NULL)
        {
                cout << "List is already empty!" << endl;
        }
        else
        {
                struct node *temp = head->next;
                while (temp->next != head)
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
        if (head == NULL)
        {
                cout << "List is already empty!" << endl;
        }
        else
        {
                struct node *temp = head->next;
                while (temp->next->next != head)
                {
                        temp = temp->next;
                }
                temp->next = head;
        }
        display();
}
void delete_from_n(int n)
{
        if (head == NULL)
        {
                cout << "List is already empty!" << endl;
        }
        else if (n == 0)
        {
                struct node *temp = head;
                head = head->next;
                temp->next = head;
        }
        else
        {
                struct node *temp = head->next;
                bool valid = true;
                n--;
                if (n == 0)
                {
                        temp->next = temp->next->next;
                }
                else if (n == 1 && head == head->next->next)
                {
                        cout << "Invalid Index" << endl;
                }
                else
                {
                        while (--n)
                        {
                                temp = temp->next;
                                if (temp->next == head)
                                {
                                        cout << "Invalid Index" << endl;
                                        valid = false;
                                        break;
                                }
                        }
                        if (valid)
                        {
                                temp->next = temp->next->next;
                        }
                }
        }
        display();
}
void custom_display()
{
        struct node *temp;
        if (head == NULL)
        {
                cout << "list is empty\n\n";
        }
        else
        {
                temp = head->next;
                cout << "|" << head << "|-->";
                cout << "|" << head->data << "-" << head->next << "|-->";
                while (temp != head)
                {
                        cout << "|" << temp->data << "-" << temp->next << "|-->";
                        if (temp->next == head)
                        {
                                cout << "(first_node)";
                        }
                        temp = temp->next;
                }
        }
        cout << "\n\n";
}


int main()
{
        insert_beg(2);
        insert_beg(7);
        insert_beg(5);
        insert_beg(4);
        insert_end(45);
        insert_at_n(78, 4);
        delete_from_end();
        delete_from_n(2);
        delete_from_beg();
        custom_display();
}
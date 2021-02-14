#include <bits/stdc++.h>
using namespace std;

struct node
{
        int data;
        node *next;
        node *previous;
};
struct node *head = NULL;

void display()
{
        struct node *temp;
        if (head == NULL)
        {
                cout << "list is empty\n\n";
        }
        else
        {
                temp = head;
                cout << "Doubly linked list: ";
                while (temp != NULL)
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
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
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

                struct node *temp = head;

                while (temp->next != NULL)
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
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL && n == 0)
        {
                new_node->data = x;
                new_node->next = NULL;
                new_node->previous = NULL;
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
                struct node *temp = head;
                bool valid = true;

                while (--n)
                {
                        temp = temp->next;
                        if (temp == NULL)
                        {
                                cout << "Invalid Index" << endl;
                                valid = false;
                                break;
                        }
                }
                if (valid)
                {
                        if (temp->next == NULL)
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
        if (head == NULL)
        {
                cout << "List is already empty!" << endl;
        }
        else
        {
                struct node *temp = head;
                head = head->next;
                temp->next = NULL;
                head->previous = NULL;
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
                struct node *temp = head;
                while (temp->next->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = NULL;
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
                temp->next = NULL;
                head->previous = NULL;
        }
        else
        {
                struct node *temp = head;
                bool valid = true;
                while (--n)
                {
                        temp = temp->next;
                        if (temp == NULL)
                        {
                                cout << "Invalid Index" << endl;
                                valid = false;
                                break;
                        }
                }
                if (valid)
                {
                        if (temp->next->next != NULL)
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
        if (head == NULL)
        {
                cout << "List is already empty!" << endl;
        }
        else
        {
                bool found = false;
                int n = 0;
                struct node *temp = head;
                while (temp != NULL)
                {
                        //cout<<temp->data<<"  ";
                        if (temp->data == x)
                        {
                                delete_from_n(n);
                                n--;
                                found = true;
                        }
                        temp = temp->next;
                        n++;
                }
                if (!found)
                {
                        cout << "The element " << x << " is not present in list" << endl;
                }
        }
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
                temp = head;
                cout << "|" << head << "|-->";
                while (temp != NULL)
                {
                        cout << "|" << temp->previous << "-" << temp->data << "-" << temp->next << "|";
                        if (temp->next != NULL)
                        {
                                cout << "<-->";
                        }
                        temp = temp->next;
                }
        }
        cout << "\n\n";
}
void reverse_display()
{
        if (head == NULL)
        {
                cout << "List is empty!" << endl;
        }
        else
        {
                struct node *temp = head;
                while (temp->next != NULL)
                {
                        temp = temp->next;
                }
                cout << "reverse: ";
                while (temp != NULL)
                {
                        cout << temp->data << " ";
                        temp = temp->previous;
                }
                cout << endl;
        }
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
        reverse_display();
        custom_display();
}
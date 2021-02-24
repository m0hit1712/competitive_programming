#include <bits/stdc++.h>
using namespace std;

struct node
{
        int data;
        node *next;
};
struct node *head = NULL;

int display_top()
{
        return head->data;
}

void push(int x)
{
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
                new_node->data = x;
                new_node->next = NULL;
                head = new_node;
                printf("[^] stack started\n");
                printf("[+] new top: %d\n", display_top());
                printf("-----------------------------------\n");
        }
        else
        {
                printf("[-] previous top: %d\n", display_top());
                printf("[+] %d pushed\n", x);
                new_node->data = x;
                new_node->next = head;
                head = new_node;
                printf("[+] new top: %d\n", display_top());
                printf("-----------------------------------\n");
        }
}

void pop()
{
        if (head == NULL)
        {
                printf("[*] Stack is empty");
        }
        else
        {
                printf("[-] previous top: %d\n", display_top());
                printf("[-] %d popped\n", display_top());
                struct node *temp = head;
                head = head->next;
                temp->next = NULL;
                printf("[+] new top: %d\n", display_top());
                printf("-----------------------------------\n");
        }
}



int main()
{
        push(3);
        push(4);
        push(10);
        push(23);
        push(43);
        push(12);
        push(3234);
        push(423);
        pop();
        pop();
        pop();
        pop();
}



#include <bits/stdc++.h>
using namespace std;

struct node
{
        int data;
        node *next;
};
struct node *head = NULL;

int display_peek()
{
        return head->data;
}

void display()
{
        struct node *temp;
        if (head == NULL)
        {
                printf("[*] Queue is empty");
                printf("-----------------------------------\n");
        }
        else
        {
                temp = head;
                printf("[+] Queue: ");
                while (temp != NULL)
                {
                        printf("%d ", temp->data);
                        temp = temp->next;
                }
                printf("\n-----------------------------------\n");
        }
}

void enqueue(int x){
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL){
                new_node->data = x;
                new_node->next = NULL;
                head = new_node;
                printf("[^] queue started\n");
                printf("[+] peek: %d\n", display_peek());
                display();
        }
        else{
                printf("[^] %d added\n", x);
                printf("[+] still peek: %d\n", display_peek());
                new_node->data = x;
                new_node->next = NULL;
                struct node *temp = head;
                while (temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = new_node;
                display();
        }
}

void dequeue(){
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
                printf("[*] Queue is empty");
        }
        else
        {
                printf("[+] %d dequeued\n", display_peek());
                struct node *temp = head;
                head = head->next;
                temp->next = NULL;
                printf("[+] new peek: %d\n", display_peek());
                display();
        }
}

int main(){
        enqueue(1);
        enqueue(12);
        enqueue(3);
        enqueue(6);
        enqueue(111);
        dequeue();
        dequeue();
        dequeue();
}
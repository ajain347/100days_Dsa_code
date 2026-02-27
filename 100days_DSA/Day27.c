#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int getLength(Node* head) 
{
    int count = 0;
    while (head != NULL) 
    {
        count++;
        head = head->next;
    }
    return count;
}


Node* findIntersection(Node* head1, Node* head2) 
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node *ptr1 = head1, *ptr2 = head2;

    if (len1 > len2) 
    {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } 
    else 
    {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) 
    {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() 
{
    int n, m, val;

    scanf("%d", &n);
    Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        Node* newNode = createNode(val);

        if (head1 == NULL)
            head1 = tail1 = newNode;
        else 
        {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);
    Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &val);

        Node* temp = head1;
        Node* found = NULL;
        while (temp != NULL) {
            if (temp->data == val) 
            {
                found = temp;
                break;
            }
            temp = temp->next;
        }

        if (found != NULL) 
        {
            if (head2 == NULL)
                head2 = tail2 = found;
            else
                tail2->next = found;
            break;  
        } 
        else 
        {
            Node* newNode = createNode(val);
            if (head2 == NULL)
                head2 = tail2 = newNode;
            else 
            {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}
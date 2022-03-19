#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
    int data;
    struct data *next;
};

typedef struct data *NODE;

NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct data));
    if(newn==NULL)
    {
        printf("NOT CREATED");
        exit(0);
    }
    newn->next=NULL;
    return newn;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    int n;
    printf("enter the number :\n");
    scanf("%d",&n);
    temp->data=n;
    return temp;
}

NODE insert_end(NODE head)
{
    NODE newn=NULL, cur=NULL;
    newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    else
    {
        cur=head;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = newn;
    }
    return head;
}
NODE swap(NODE head)
{
    NODE prev=head,cur=head->next;
    if(head==NULL||head->next==NULL)
        return NULL;
    head=cur;
    while(1)
    {
        NODE newn=cur->next;
        cur->next=prev;
        if(newn==NULL||newn->next==NULL)
        {
            prev->next=newn;
            break;
        }
        prev->next=newn->next;
        prev=newn;
        cur=prev->next;
    }
    return head;
}
void display_list(NODE head)
{
    NODE cur=NULL;
    if(head==NULL)
    {
        printf("list is empty\n");
        exit(0);
    }
    else
    {
        cur=head;
        printf("Details\n");
        printf("The Employers id:\n");
        printf("head");
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}

int main()
{
  NODE head=NULL;
  int choice;
        printf("\n\nMENU---1.Insert node 2 Display 3 Swap_No\n");
        while(1)
        {
            printf("Enter choice:\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: head=insert_end(head);
                break;
                case 2: display_list(head);
                break;
                case 3: head=swap(head);
                break;
                 default: printf("INVALID CHOICE\n");
            }
        }
return 0;
}

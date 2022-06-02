#include<stdio.h>
#include<stdlib.h>
struct node
{

	int data;
	struct node *next;

};

typedef struct node *NODE;

NODE insert_front( NODE );
NODE insert_end(NODE);
NODE read_details(NODE);
void display_list(NODE);
NODE delete_end(NODE);
NODE delete_front(NODE);
NODE getnode();
void main()
{
    int choice;
    NODE head=NULL;

    while(1)
    {
      printf("\nPress\n 1 for insert at end\n 2 for insert front\n 3 for display\n 4 for Delete end \n5 for Delete front\n6 for exit\n");
      scanf("%d",&choice);

        switch(choice)
        {
            case 1:head=insert_end(head);
                    break;
            case 2:head=insert_front(head);
                    break;
            case 3:display_list(head);
                    break;
            case 4:head=delete_end(head);
                    break;
            case 5:head=delete_front(head);
                    break;
            case 6:exit(0);
                    break;
            default:printf("Invalid choice\n");
        }
    }
}
NODE getnode()
{
NODE new;
new=(NODE)malloc(sizeof(struct node));
if(new==NULL)
{
printf("Not created\n");
exit(0);
}
printf("Enter the data part\n");
scanf("%d",&new->data);
new->next = NULL;
return new;
}
NODE insert_end (NODE head)
{
NODE new, cur;

new=getnode();
new ->next = NULL;
if(head==NULL)
return new;
cur = head;
while (cur->next != NULL)
{
cur = cur->next;
}
cur -> next = new;
return head;
}
NODE insert_front( NODE head)
{
NODE new;
//new = read_details();
new -> next = NULL;
if(head == NULL)
{
return new;
}
new ->next = head;
head = new;
return head;
}
void display_list (NODE head)
{
NODE cur;
if(head==NULL)
{
printf("Empty List\n");
return NULL;
}
printf("elements are\n");
cur = head;
printf("data\n");
while (cur != NULL)
{
printf("%d\n",cur->data);
cur = cur ->next;
}
}
NODE delete_end(NODE head)
{
NODE prev, cur;
if(head==NULL)
{
printf("List Empty\n");
return head;
}
if(head->next==NULL)
{
printf("Deleted: %d\n", head->data);
free(head);
return NULL;
}
prev =NULL;
cur =head;
while(cur ->next != NULL)
{
prev= cur;
cur = cur ->next;
}
printf("Deleted: %d\n", cur->data);
free(cur);
prev->next=NULL;
return head;
}
NODE delete_front (NODE head)
{
NODE cur;
if(head==NULL)
{
printf("List Empty\n");
return head;
}
cur=head;
head=head->next;
printf("Deleted: %d\n", cur->data);
free(cur);
return head;
}




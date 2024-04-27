#include<stdio.h>

struct node
{
    int item;
    struct node *next;
};


struct node* Find(struct node *s,int data)
{

    while(s !=NULL) //or while(s)
    {
        if(s->item==data)
            return s;
        s=s->next;
    }
    return NULL;
}
void Insert_After(struct node *temp,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=temp->next;
    temp->next=n;
}
void Insert_At_First(struct node **s,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void Insert_At_Last(struct node **s,int data)
{
    struct node *n,*t;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(*s==NULL){
        n->next=NULL;//correct
        *s=n;
    }
    else{
        t=*s;
        while(t->next!=NULL){
             t=t->next;
        }

        n->next=NULL;//correct
        t->next=n;
    }
}
void Delete_At_First(struct node **s)
{
    struct node *t;
    if(*s==NULL){
        printf("Underflow");
    }
    else
    {
        t=*s;
        *s=t->next;
        free(t);
    }
}

void Delete_At_Last(struct node *s)
{
    struct node *t,*q;
    if(s==NULL){
        printf("Underflow");
    }
    else{
            t=s;
        while(t->next!=NULL){//t!=NULL
            q=t;
            t=t->next;
        }
        free(t);
        q->next=NULL;
    }
}
void Delete_After(struct node **s,struct node *temp)
{
    struct node *p;
    if(*s==NULL){
        printf("Underflow");
    }
    else if((*s)->next==NULL)
    {
        Delete_At_First(s);
    }
    else{
        p=*s;
        printf("\n");
        while(p->next!=temp){
            p=p->next;
        }
        printf("%d\n%d",p->item,temp->item);
        p->next=temp->next;
        free(temp);
    }
}

void printList(struct node *start)
{
    while(start!=NULL){
    printf("%d ",start->item);
    start=start->next;
    }
}
void main(){
    struct node *start=NULL,*t;
    int d,s;

    //t=start;
   while(1)
    {
        system("cls");
        printf("This is a linked list data structure");
        printf("\n\nLinked Have : ");
        printList(start);
        printf("\n\n<---------------------------------------------------------------------------------->");
        printf("\n1.Insert a node at first place");
        printf("\n2.Insert a node at last place");
        printf("\n3.Insert a node after any node");
        printf("\n4.Delete a node at first place");
        printf("\n5.Delete a node at last place");
        printf("\n6.Delete a node from any place");
        printf("\n<---------------------------------------------------------------------------------->");
        printf("\n\nEnter operation key number what do you want : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1 :    printf("\nEnter a data you want insert : ");
                        scanf("%d",&d);
                        Insert_At_First(&start,d);
                        break;

            case 2 :    printf("\nEnter a data you want insert : ");
                        scanf("%d",&d);
                        Insert_At_Last(&start,d);
                        break;

            case 3 :    printf("\nEnter the data after which you want to insert the your data : ");
                        scanf("%d",&d);
                        struct node *temp=Find(start,d);
                        printf("\nEnter your data : ");
                        scanf("%d",&d);
                        Insert_After(temp,d);
                        break;

            case 4 :    Delete_At_First(&start);
                        break;
            case 5 :    Delete_At_Last(start);
                        break;

            case 6 :    printf("\nEnter the data after which you want to delete the your data : ");
                        scanf("%d",&d);
                        struct node *temp1=Find(start,d);
                        Delete_After(&start,temp1);
                        break;


           default :    printf("Enter valid input\n");
        }
        getch();
    }

}

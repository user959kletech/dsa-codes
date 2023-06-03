#include<stdio.h>
#include<stdlib.h>
FILE*fp;
int x,n;
struct stackll{
int data;
struct data*next;
};
typedef struct stackll*NODE;
NODE newn,ptr,head,tail;
int randnum(){
    //generate random number
int p=rand();
int k=p%100;
return k;
}
NODE getnode(){    //get data for push function
newn=(NODE)malloc(sizeof(struct stackll));
if(newn==NULL){
    printf("memory not allocated");
    exit(0);
}
x=randnum();
newn->data=x;
newn->next=NULL;
return newn;
}
void push(){ //push element to stack
newn=getnode();
if(head==NULL){
    head=newn;
    tail=head;
    tail->next=NULL;
    head->next=NULL;
}
else{
    tail->next=newn;
    tail=tail->next;
    tail->next=NULL;
}
}
void pop(){ //pop element from stack
if(head==NULL) printf("stack is empty");
else{
    ptr=head;
    printf("deleted element is:\n%d",ptr->data);
    head=head->next;
    free(ptr);
}
}
void display(){ //display elements of the stack
    ptr=head;
while(ptr->next!=NULL){
    printf("\n%d",ptr->data);
    ptr=ptr->next;
}
printf("\n%d",ptr->data);
}
void fops(){ //copy to file
    fp=fopen("abracadabra.txt","w");
    ptr=head;
    while(ptr->next!=NULL){
        fprintf(fp,"%d\n",ptr=ptr->data);
        ptr=ptr->next;
    }
    fprintf(fp,"%d\n",ptr=ptr->data);
    fclose(fp);
    }
int main()
{    //main function
    int t;
    for(;;){
    int choice;
    printf("\nenter 0 to push\nenter 1 to pop\nenter 2 to display\nenter 3 to copy to file\nenter 4 to exit\n");
    scanf("%d",&choice);
    switch (choice){
    case 0:push();break;
    case 1:pop();break;
    case 2:display();break;
    case 3:fops();break;
    case 4:exit(0);break;
    return 0;
}
}
}

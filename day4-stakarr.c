#include <stdio.h>
#include <stdlib.h>
#define N 1000
int stack[N];
int top=-1;
FILE*fp;
int n,k;
void display(){
    //display elements of the stack
for(int i=0;i<n;i++){
    printf("\n%d",stack[i]);
}
}
void fops(){
    //copy elements to file
    fp=fopen("abracadabra.txt","w");
    int i=0;
    while(stack[i]!=NULL){
        fprintf(fp,"%d\n",stack[i]);
        i++;
    }
    fclose(fp);
    }
void push(int num)
{    //push elements onto stack
    if(top==N-1)
        printf("\nStack overflow");
    top++;
    stack[top]=num;
}
int pop()
{      //pop element from stack
    int item;
    if(top==-1)
    {
        printf("\nStack underflow");
        return 0;
    }
    item=stack[top];
    top--;
    return item;
}
int randnum(){
    //generate random number
int x=rand();
int k=x%100;
push(k);
}
int main()
{    //main function
    int t;
    for(;;){
    int choice;
    printf("\nenter 0 to push\nenter 1 to pop\nenter 2 to display\nenter 3 to exit\n");
    scanf("%d",&choice);
    switch (choice){
    case 0:printf("\nEnter number of random number:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        randnum();
    }
    fops();
    break;
    case 1:t=pop();
        printf("\n popped element:%d",t);n--;
    fops();break;
    case 2:display();break;
    case 3:exit(0);break;
    return 0;
}
}
}

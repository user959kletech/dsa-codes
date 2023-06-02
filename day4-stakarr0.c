#include <stdio.h>
#include <stdlib.h>
#define N 1000
int stack[N];
int top=0;   //IMPORTANT TO NOTE: TOP IS 0 NOT -1
FILE*fp;
int n;
void display(){ //display elements
for(int i=0;i<n;i++){
    printf("\n%d",stack[i]);
}
}
void fops(){    //add to file
    fp=fopen("abracadabra.txt","w");
    for(int i=0;i<n;i++){
        fprintf(fp,"%d\n",stack[i]);
    }
    fclose(fp);
    }
void push(int num)
{      //push onto stack
    if(top==N-1)
        printf("\nStack overflow");
    stack[top]=num;
    top++;
}
int pop()
{     //pop from stack
    int item;
    if(top==0)
    {
        printf("\nStack underflow");
        return 0;
    }
    item=stack[top];
    top--;
    return item;
}
int randnum(){  //generate random numbers
int x=rand();
int k=x%100;
push(k);
}
int main()
{      //main function
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

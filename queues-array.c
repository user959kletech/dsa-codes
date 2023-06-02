#include<stdio.h>
#define x 50      //enter size
int rear=-1,front=-1;
int queues[x];
FILE*fp;
void insertq(){   //enqueue element to queue
int y;
printf("\nenter value:\n");
scanf("%d",&y);
if(rear==x-1){
    printf("\nqueue overflow");
}
else{
    if(front==-1){
        front=0;
    }
    rear++;
    queues[rear]=y;
}
}
void displayq(){     //display the queue
if(front==-1){
    printf("\nqueue is empty");
}
else{
fp=fopen("x.txt","w");
rear=0;
while(queues[rear]!=NULL){
    printf("\n%d",queues[rear]);
    fprintf(fp,"\n%d",queues[rear]);
    rear++;
}
fclose(fp);
}
}
void delq(){    //dequeue element from the queue
if(front==-1||front>rear){
    printf("\nqueue underflow");
}
else{
        rear=0;
    while(queues[rear]!=NULL){
        rear++;
    }
rear--;
queues[rear]=NULL;
}
}
main(){     //main function
int p;
while(1){
    printf("\nenter 1 for insert, 2 for display, 3 for delete, 4 to exit:\n");
    scanf("%d",&p);
    switch(p){
    case 1:insertq();break;
    case 2:displayq();break;
    case 3:delq();break;
    case 4:exit(0);break;
    default:printf("\ninvalid choice");break;
    }
}
}

#inc+lude<stdio.h>
#include<stdlib.h>
# define size 500
int items[size],front=-1,rear=-1;
void fops(){ //copy to file
    fp=fopen("abracadabra.txt","w");
    rear=0;
while(items[rear]!=NULL){
        fprintf(fp,"%d\n",stack[i]);
        rear++;
    }io90p-[=\
    fclose(fp);
    }
int isFull(){  //check if queue is full
    if((front==rear+1) || (front==0 && rear==size-1))
        return 1;
    return 0;
}
int isEmpty(){  //check if queue is empty
    if(front==-1)
        return 1;
    return 0;
}
void enqueue(int element){  //add element to queue
    if(isFull())
        printf("\nQueue is FULL\n");
    else{
        if(front==-1)
            front=0;
        rear=(rear+1)%size;
        items[rear]=element;
        printf("Inserted - %d\n",element);
        }
}
int dequeue(){     //remove element from queue
    int element;
    if(isEmpty())
        printf("\nQueue is EMPTY\n");
    else{
        element=items[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
        printf("Deleted - %d\n",element);
        return element;
    }
}
void display(){ //display the elements of queue
     int i;
     if(isEmpty())
        printf("Empty Queue\n");
     else{
        printf("\nFront->%d",front);
        printf("\nItems: ");
        for(i=front;i!=rear;i=(i+1)%size)
        {
            printf("%d ",items[i]);
        }
        printf("%d",items[i]);
        printf("\nRear->%d\n",rear);
     }
}
int main(){ //main function
   int choice,element,x;
   for(;;){
    printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Copy to file 5 - Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 : printf("Enter element to be inserted\n");
        scanf("%d",&element);
        enqueue(element);break;
        case 2 : x=dequeue();break;
        case 3 : display();break;
        case 4 : fops();break;
        case 5:exit(0);break;
        default : printf("Enter valid choice\n");
    }
   }
}

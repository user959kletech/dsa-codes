#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct linklist{ //declare
int data;
struct linklist*next;
};
typedef struct linklist*ll;
ll ptr,newn,head;
int n,i,j;
ll getnode(){    //get node in list
newn=(ll)malloc(sizeof(struct linklist));
if(newn==NULL){
    printf("memory not allocated");
    exit(0);
}
newn->data=j;
newn->next=NULL;
if(head==NULL) head=newn;
return newn;
}
int main(){   //main function
clock_t start, end;
double execution_time;
FILE*fp;
fp=fopen("random.txt","w");
printf("enter number of random numbers to generate:\n");
scanf("%d",&n);
for(i=0;i<n;i++){
        j=rand() % 1000 + 1;
        ptr=getnode(j);
    fprintf(fp,"%d\n",ptr->data);
    printf("%d\n",ptr->data);
    ptr=ptr->next;
}
fclose(fp);
start = clock();
fp=fopen("time.txt","w");
    int stor2[100];              //store array
    ptr=head;
for(i=0;i<n;i++){
    stor2[i]=ptr->data;
    ptr=ptr->next;
}
    printf("modified array is:\n");
for(i=0;i<n;i++){
    printf("%d\n",stor2[i]);       //print sorted array
}
end = clock();
execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
printf("%lf",execution_time);           //print execution time
fprintf(fp,"%lf\n",execution_time);      //store time in file
fclose(fp);
}

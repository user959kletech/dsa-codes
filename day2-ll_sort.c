#include<stdio.h>
struct linked_list{                     //create linked list
int data;
struct linked_list * next;
};
typedef struct linked_list * NODE;
NODE head,newn,tail,ptr;
int sort_arr();
int i,n,x;
NODE getnode(){
newn=(NODE)malloc(sizeof(struct linked_list));
if(newn==NULL){
    printf("memory not allocated");
    exit(0);
}
newn->data=x;
newn->next=NULL;
return newn;
}
int main(){

FILE *fp;
fp = fopen("a.txt", "r");                          //open file
if(fp==NULL){
    printf("file not opened");                  //checking if file is opened
    exit(0);
}
printf("enter no. of array elements to access:\n");
scanf("%d",&n);

for(i=0;i<n;i++){

    fscanf(fp,"%d",&x);
    if(i==0){                       //store array elements
    head=getnode();
    ptr=head;
        tail=head;
        }
    else{
        ptr=getnode();
    tail->next=ptr;
    tail=tail->next;
    }
}
fclose(fp);
        printf("original array is:\n");
     ptr=head;
for(i=0;i<n;i++){
        printf("%d\n",ptr->data);                          //display array elements
        ptr=ptr->next;
}
sort_arr();
}
int sort_arr(){
    FILE*fp;
    fp=fopen("b.txt","w");
ptr=head;
tail=head;
newn=head;
tail=tail->next;
        printf("sorted array is:\n");
for(i=0;i<n;i++){
if(ptr->data<tail->data){
    newn->data=ptr->data;
    ptr->data=tail->data;
    tail->data=newn->data;
}
else{
    ptr=ptr->next;
    newn=newn->next;
}
x=ptr->data;
printf("%d\n",x);
fprintf(fp,"%d",x);
tail=tail->next;
}
fclose(fp);
}

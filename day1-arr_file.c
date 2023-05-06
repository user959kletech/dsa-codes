#include<stdio.h>
#include<stdlib.h>
int sort_arr(int);      //declare function to sort
int i,n,arr[10];          //declare relevant integers
int main(){
FILE*fp;                  //declare file pointer
printf("enter no. of array elements to access:\n");
scanf("%d",&n);                               //number of elements of array to be shown
fp = fopen("a.txt", "r");                          //open file
if(fp==NULL){
    printf("file not opened");                  //checking if file is opened
    exit(0);
}
for(i=0;i<n;i++){
    fscanf(fp,"%d",&arr[i]);                       //store array elements
}
fclose(fp);
        printf("original array is:\n");
for(i=0;i<n;i++){
        printf("%d\n",arr[i]);                          //display array elements
}


    int stor2[10];              //store sorted array
for(i=0;i<n;i++){
    stor2[i]=arr[n-(i+1)];
}
FILE*fptr;
fptr = fopen("b.txt", "w");        //create new file
    printf("modified array is:\n");
for(i=0;i<n;i++){
    fprintf(fptr,"%d",stor2[i]);
    printf("%d\n",stor2[i]);       //print sorted array
}
}

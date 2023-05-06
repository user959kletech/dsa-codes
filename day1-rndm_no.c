#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,i,j;
int main(){
clock_t start, end;
double execution_time;
int arr[100];
FILE*fp;
fp=fopen("random.txt","w");
printf("enter number of random numbers to generate:\n");
scanf("%d",&n);
for(i=0;i<n;i++){
        j=rand() % 1000 + 1;
        arr[i]=j;
    fprintf(fp,"%d\n",j);
    printf("%d\n",j);
}
fclose(fp);
start = clock();
fp=fopen("time.txt","w");
    int stor2[100];              //store sorted array
for(i=0;i<n;i++){
    stor2[i]=arr[n-(i+1)];
}
    printf("modified array is:\n");
for(i=0;i<n;i++){
    printf("%d\n",stor2[i]);       //print sorted array
}
end = clock();
execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
printf("%lf",execution_time);
fprintf(fp,"%lf\n",execution_time);
fclose(fp);
}

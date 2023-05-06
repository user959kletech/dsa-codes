#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,j,n,m;
void sort(int b[],int m)               //sorting code
{
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(b[j]>b[j+1])       //checking equality
            {
                int temp=0;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
}
int main()
{
    time_t t1,t2,t;
    FILE *fp;
    printf("\nEnter number of random elements:  ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    fp=fopen("test2.txt","w");
    if(fp==NULL)
    {
        printf("\nFile not created");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);
    fp=fopen("test2.txt","r");
    printf("\nEnter number to be sorted:  ");
    scanf("%d",&m);
    int b[m];

    if(fp==NULL)
    {
        printf("\nFile not opened");
        exit(0);
    }
    for(i=0;i<m;i++)
    {
        fscanf(fp,"%d",&b[i]);
    }
    fclose(fp);
    t1=time(NULL);
    sort(b,m);
    t2=time(NULL);
    t=t2-t1;
    printf("\nTime taken: %d",t);
}

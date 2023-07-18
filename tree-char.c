#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct CHARTREE     //declare tree
{
    char data;
    struct TREE *left;
    struct TREE *right;
};    //assign name for tree
typedef struct CHARTREE *tree;
void random_char(FILE *fp,int n) //generate random characters
{
    int c;
    char r;
    for(int i=0;i<n;i++)
    {
        c=rand()%52;
        if(c<26)
        {
            r='A'+c;
            fprintf(fp,"%c\t",r);
        }
        else
        {
            r='a'+(c-26);
            fprintf(fp,"%c\t",r);
        }
    }
}
tree getnode(char data)    //create node
{
    tree newn=(tree)malloc(sizeof(struct CHARTREE));
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
    return newn;
}
tree insert(tree root,char data)      //insert elements based on value into tree
{
    if(root==NULL)
    {
        root=getnode(data);
        return root;
    }
    if(data < root->data)
        root->left=insert(root->left,data);
    if(data > root->data)
        root->right=insert(root->right,data);
    return root;
}
void inorder(tree root,FILE *fp)  //print in inorder format
{
    if(root!=NULL)
    {
        inorder(root->left,fp);
        printf("%c\t",root->data);
        fprintf(fp,"%c\t",root->data);
        inorder(root->right,fp);
    }
}
void preorder(tree root,FILE *fp) //print in preorder format
{
    if(root!=NULL)
    {
        printf("%c\t",root->data);
        fprintf(fp,"%c\t",root->data);
        preorder(root->left,fp);
        preorder(root->right,fp);
    }
}
void postorder(tree root,FILE *fp)  //print in postorder format
{
    if(root!=NULL)
    {
        postorder(root->left,fp);
        postorder(root->right,fp);
        printf("%c\t",root->data);
        fprintf(fp,"%c\t",root->data);
    }
}
int main()     //main function
{
    FILE *fp;
    int n; char data;
    tree root=NULL;
    printf("\nEnter number: ");
    scanf("%d",&n);
    fp=fopen("char.txt","w");
    random_char(fp,n);
    fclose(fp);
    fp=fopen("char.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&data);
        root=insert(root,data);
    }
    fclose(fp);
    fp=fopen("inorder.txt","w");
    printf("\nIn-Order:\n");
    inorder(root,fp);
    fclose(fp);
    fp=fopen("preorder.txt","w");
    printf("\nPre-Order:\n");
    preorder(root,fp);
    fclose(fp);
    fp=fopen("postorder.txt","w");
    printf("\nPost-Order:\n");
    postorder(root,fp);
    fclose(fp);
    return 0;
}

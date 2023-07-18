#include <stdio.h>
#include <stdlib.h>
struct NUMTREE     //declare tree
{
    int data;
    struct TREE *left;
    struct TREE *right;
};
typedef struct NUMTREE *tree; //give an alternate name for the tree
tree getnode(int data)   //create node for tree elements
{
    tree newn=(tree)malloc(sizeof(struct NUMTREE));
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
    return newn;
}
tree insert(tree root,int data)   //insert elements in tree
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
void inorder(tree root,FILE *fp) //display the elements in inorder format
{
    if(root!=NULL)
    {
        inorder(root->left,fp);
        printf("%d\t",root->data);
        fprintf(fp,"%d\t",root->data);
        inorder(root->right,fp);
    }
}
void preorder(tree root,FILE *fp)  //display the elements in preorder format
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        fprintf(fp,"%d\t",root->data);
        preorder(root->left,fp);
        preorder(root->right,fp);
    }
}
void postorder(tree root,FILE *fp)   //display the elements in postorder format
{
    if(root!=NULL)
    {
        postorder(root->left,fp);
        postorder(root->right,fp);
        printf("%d\t",root->data);
        fprintf(fp,"%d\t",root->data);
    }
}
void random_gen(FILE *fp,int n)    //generate random numbers to be stored in tree
{
    int c,x,y;
    printf("\nEnter range x and y:");
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c<y && c>x)
        {
            fprintf(fp,"%d ",c);
        }
    }
}
int main()    //main function
{
    FILE *fp;
    int n,data;
    tree root=NULL;
    fp=fopen("input.txt","w");
    printf("\nEnter number:  ");
    scanf("%d",&n);
    random_gen(fp,n);
    fclose(fp);
    fp=fopen("input.txt","r");
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&data);
        root=insert(root,data);
    }
    fclose(fp);
    fp=fopen("inorder.txt","w");
    printf("\nIn-Order\n");
    inorder(root,fp);
    fclose(fp);
    fp=fopen("preorder.txt","w");
    printf("\nPre-Order\n");
    preorder(root,fp);
    fclose(fp);
    fp=fopen("postorder.txt","w");
    printf("\nPost-Order\n");
    postorder(root,fp);
    fclose(fp);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct avltree{
int data;
int height;
struct avltree*right;
struct avltree*left;
};
typedef struct avltree*NODE;
NODE newn,ptr,element,root;
FILE*fp;
int maxval(int a,int b){
    if(a>b) return a;
    else return b;
}
int random(){
    int x;
    x=rand();
    x=x%100;
    return x;
}
int height(NODE n){
    if(n==NULL) return 0;
    else return n->height;
}
NODE RR(NODE n){
    NODE x=n->left;
    NODE y=x->right;
    x->right=n;
    n->left=y;
    n->height=maxval(height(n->left),height(n->right));
    x->height=maxval(height(x->left),height(x->right));
    return x;
}
NODE LR(NODE n){
    NODE x=n->right;
    NODE y=x->left;
    n->right=y;
    x->left=n;
    n->height=maxval(height(n->left),height(n->right));
    x->height=maxval(height(x->left),height(x->right));
    return x;
}
NODE getnode(int elem){
newn=(NODE)malloc(sizeof(struct avltree));
newn->data=elem;
newn->left=NULL;
newn->right=NULL;
newn->height=1;
return newn;
}
int Balance(NODE n){
if (n==NULL) return 0;
else return(height(n->left)-height(n->right));
}
NODE insertnode(NODE groot,int p){
groot=getnode(p);
if(root==NULL) return groot;
if (p < groot->data)
    groot->left = insertnode(groot->left, p);
  else if (p > groot->data)
    groot->right = insertnode(groot->right, p);
  else
    return groot;
    groot->height = 1 + maxval(height(groot->left),
               height(groot->right));

  int balance = Balance(groot);
  if (balance > 1 && p < groot->left->data)
    return RR(groot);

  if (balance < -1 && p > groot->right->data)
    return LR(groot);

  if (balance > 1 && p > groot->left->data) {
    groot->left = LR(groot->left);
    return RR(groot);
  }

  if (balance < -1 && p < groot->right->data) {
    groot->right = RR(groot->right);
    return LR(groot);
  }

  return groot;
}
NODE minValueNode(NODE node) {
  NODE cur = node;

  while (cur->left != NULL)
    cur = cur->left;

  return cur;
}
void printPreOrder(NODE groot) {
  if (root != NULL) {
    printf("%d ", groot->data);
    printPreOrder(groot->left);
    printPreOrder(groot->right);
  }
}
int main() {
    root=NULL;
  while(1){
  int x=random();
  root = insertnode(root, x);
  printPreOrder(root);
  }
}

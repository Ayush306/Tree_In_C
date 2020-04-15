#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void insertNode(int);
//NODE Delete(NODE,int);

struct node
{

    int data;
    struct node *left,*right;
};

typedef struct node NODE;

NODE *findMIN(NODE*);

NODE *L,*R;
NODE *minAds;

NODE *root,*p,*temp;
NODE *current;
 int more = 1;
 int n;
 int element_del;
void main()
{
    while(1)
    {
    int Choice;
    printf("\n----------------Welcome In Tree Program----------------------\n");

    printf("1:Insert a node into Tree\n");
    printf("2:Delete a node into Tree\n");
    printf("3:Search a node into Tree\n");
    printf("4:Display the Tree\n");
    printf("5:Exit\n");
    printf("Enter the Choice: ");
    scanf("%d",&Choice);
    switch(Choice)
    {

        case 1:
            while(more == 1)
            {
            printf("Enter the data:");
            scanf("%d",&n);
            insertNode(n);
            printf("\nDo you want to insert more nodes (Type 1): ");
            scanf("%d",&more);
            }
            break;
        case 2:
            printf("Enter the element Which You Want To delete:");
            scanf("%d",&element_del);
            Delete(root,element_del);
            break;
        case 4:
            printf("\nThe Tree is:\n ");
            Inorder_Print(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Plz enter a valid key:");
    }
    }

}
void insertNode(int d)
{
    temp  = (NODE*)malloc(sizeof(NODE));
    temp->data = d;

    temp->left = NULL;
    temp->right = NULL;

    p = root;
    if(root == NULL)
    {
        root = temp;
        temp->data = d;
    }
      else
      {
          current = root;
          while(current)
          {
              p = current;
              if(temp->data > current->data)
              {
                  current = current->right;
              }
              else
              {
                  current = current->left;
              }
          }
          if(p->data < temp->data)
          {
              p->right = temp;
          }
          else
          {
              p->left = temp;
          }
      }
}
 Delete(NODE *root,int element_del)
{

    //Delete A Leaf Node
    current = root;
    while(current)
    {
        if(current->data < element_del)
           {
                p = current;
               current = current->right;
           }
            else if(current->data > element_del)
            {
                 p = current;
                current = current->left;
            }
            else{
                break;
            }
    }
    if(current->left == NULL && current->right == NULL)
    {
      if(current == p->right)   //No child node
      {

        p->left = NULL;

      }
    else

        if(current == p->left)
       {
         p->left = NULL;
       }
    }
    else                              //case 1 when the node have left child
       if(current->left != NULL && current->right == NULL)
       {
        if(current == p->right)      //(i)node exist right side of the parent
          {
            p->right = current->left;
            current->left = NULL;
          }
          else
            if(current == p->left)     //(ii)node exist left side of the parent
            {
             p->left = current->left;
              current->left = NULL;
            }
       }
    else                             //case 2 when the node have right child

      if(current->right != NULL && current->left == NULL)
      {
          if(current == p->left)      //(i)node exist left side of the parent
          {
              p->left = current->right;
              current->left = NULL;
          }
          else

           if(current == p->right)    //(ii)node exist right side of the parent
            {
              p->right = current->right;
              current->right = NULL;
            }

      }
      else
        if(current->right != NULL && current->left != NULL)  //When deleted or targeted node is  having both child
      {

          R = current->right;
          if(R->left == NULL)
          {
          minAds = findMIN(R);
          current->data = minAds->data;
          current->right = R->right;
          R->left = NULL;
          R->right = NULL;
          free(minAds);
          }
          else
            if(R->right == NULL)
          {
             minAds = findMIN(R);
             current->data = minAds->data;
             R->left = minAds->right;
             minAds->right = NULL;
             free(minAds);
          }
          else
            if(R->left !=NULL && R->right !=NULL)
          {
              minAds  = findMIN(R);
              current->data = minAds->data;
              if(minAds->right != NULL)
              {
                  R->left = minAds->right;
                  free(minAds);
              }
              else{
                free(minAds);
              }
          }
      }

  //  free(current);


}
NODE *findMIN(NODE *root1)
{
    if(root1->left == NULL)
    {
        return root1;
    }
    else
    {
   return findMIN(root1->left);
    }
}
void Inorder_Print(NODE *t)
{

    if(t->left)

        Inorder_Print(t->left);

    printf("%d=>",t->data);
    if(t->right)

        Inorder_Print(t->right);

}

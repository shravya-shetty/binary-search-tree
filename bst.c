#include<stdio.h>
struct node // DLL node for Tree with left_link value and right_link
{
	int value;
	struct node *ltree;
	struct node *rtree;
};
typedef struct node* NODE;

NODE getnode() // create a node
{
	NODE x;
	x=(NODE) malloc (sizeof(struct node));
    x->ltree=NULL;
    x->rtree=NULL;
	return x;
} // end of getnode

NODE create(int item, NODE root) // create a  BST for the given values
{
	NODE temp,cur,prev;
	int i , flag=0;
	temp=getnode(); // create node
	temp->value=item; // store value
	if(root==NULL) // if empty tree then new node itself is ROOT of BST
	{
		root=temp;
		return root;
	}
	else // otherwise add new node to BST
	{
		prev=NULL;
		cur=root;
		while (cur!=NULL) // find the leaf node
		{
			prev=cur;
			flag = (temp->value==cur->value)?1:0;
			cur=(temp->value<cur->value)?cur->ltree:cur->rtree; // condition to choose left or right subtree
		}
		if(flag==0)
		{
		if(temp->value<prev->value) // if new node smaller than ROOT then make it as left child
			prev->ltree=temp;
		else if(temp->value>prev->value) // otherwise if new node greater than ROOT then make it as right child
			prev->rtree=temp;
		}
	    }

		return root;
}

void in(NODE IN) // Recursive INORDER traversal function
{
	if(IN!=NULL) // if tree is not empty then traverse
	{
		in(IN->ltree); // left child
		printf("%d\t",IN->value); // Root
		in(IN->rtree); //right child
	}
}

void pre(NODE PRE)  // Recursive PREORDER traversal function
{
	if(PRE!=NULL) // if tree is not empty then traverse
	{
		printf("%d\t",PRE->value); // Root
		pre(PRE->ltree); // left child
		pre(PRE->rtree); //right child
	}
}

void post(NODE POST) // Recursive POSTORDER traversal function
{
	if(POST!=NULL) // if tree is not empty then traverse
	{
		post(POST->ltree); // left child
		post(POST->rtree); //right child
		printf("%d\t",POST->value); // Root
	}
}


void main()
{
	int choice, item, n, i;
	NODE root=NULL;
	printf("SANDESH H D\n4CB19CS089");
	while(1)
	{
		 printf("\n1. Create BST of N Integers");
		 printf("\n2. BST Traversal");
		 printf("\n3. Exit");
		 printf("\nEnter Your Choice: ");
		 scanf("%d",&choice);
		 switch(choice)
		 {
			  case 1:   printf("\n Enter number elements : ");
                        scanf("%d",&n);
                        for (i =0; i<n; i++)
                        {
                            printf("Enter the item to be inserted\n");
                            scanf("%d",&item);
                            root=create(item,root);
                        }
                        break;
			  case 2:   if(root==NULL) // check for empty tree
                            printf("Tree is empty\n");
                        else
                        {   // for non-empty tree traverse BST
                            printf("\n\nPREORDER traversal\n");
                            pre(root);
                            printf("\n\nINORDER traversal\n");
                            in(root);
                            printf("\n\nPOSTORDER traversal\n");
                            post(root);
                        }
                        break;
			  case 3:   return;
			  default:  printf("\n Invalid Choice\n");
		 } // end of switch
	} // end of while
} // end of main

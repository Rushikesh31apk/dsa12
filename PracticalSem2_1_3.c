#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*left;
	struct node*right;
}Node;
Node*create(Node*root)
{
	struct node*temp, *prev, *newnode;
	int i,n,num;
	printf("\nHow many number do you want to insert in tree: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter %d node in tree: ",i+1);
		scanf("%d",&num);
		newnode=(Node*)malloc(sizeof(Node));
		newnode->data=num;
		newnode->left=newnode->right=NULL;
		if(root== NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp != NULL)
		{
			prev=temp;
			if(temp->data <num)
			{
				temp=temp->right;
			}
			else{
				temp=temp->left;
			}
		}
		if(num< prev->data)
		{
			prev->left=newnode;
		}
		else{
			prev->right=newnode;
		}
	}
	return root;
}
void inorder(Node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	return ;
}
Node *copy(Node*root){
    Node *root1;
	if(root != NULL)
	{
		root1=(Node*)malloc(sizeof(Node));
		root1->data=root->data;
		root1->left=copy(root->left);
		root1->right=copy(root->right);
		return root1;
	}
	else{
		return NULL;
	}
}
int compare(Node *T1, Node *T2)
{
	if(T1 == NULL && T2 == NULL)
	{
		return 1;
	}
	else if(T1 != NULL && T2 == NULL || T1 == NULL && T2 != NULL)
	{
		return 0;
	}
	else{
		compare(T1->left,T2->left);
		compare(T1->right,T2->right);
	}
}
void main()
{
	Node*root,*root1;
	int ch;
	do
	{
		printf("\n1.create\n2.T1-inorder\n3.T2-inorder\n4.copy\n5.compare\n6.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root=NULL;
				root=create(root);
				break;
			case 2:
				printf("\nShowing Tree one: ");
				inorder(root);
				break;
			case 3:
				printf("\nShowing Tree Two: ");
				inorder(root1);
				break;
			case 4:
				root1=copy(root);
				printf("\nTree copied succefully!");
				break;
			case 5:
				if(compare(root,root1))
				{
					printf("!Both trees are equal!");
				}
				else
				{
					printf("!Both trees are Not equal!");
				}
				break;
			case 6:
				exit(0);
		}
	}while(ch != 6);
}

#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *lchild, *rchild;	
};

struct node * root = NULL;

int insertTree(int data)
{
	// allocate space and store values in new node
	struct node *ptr, *pptr,*temp = (struct node *) malloc(sizeof(struct node));
	temp->info= data;
	temp->lchild=NULL;
	temp->rchild = NULL;
	
	// find the place of insertion
	if(root == NULL) root= temp;
	else
	{
		pptr=ptr= root;
		while (ptr != NULL)
		{
			pptr = ptr;
			if(data < ptr->info) ptr= ptr->lchild;
			else ptr = ptr->rchild;
		}
		 
		if (data < pptr->info) pptr->lchild = temp;
		else pptr->rchild = temp;
	}
	
	return 0;

}


struct node * FindMin(struct node *point) {
if (point == NULL) {
      return NULL; // or undefined.
   }
   while (point->lchild != NULL) {
      point = point->lchild; // left tree is smaller
   }
   return point;
}

/*
struct node* Delete(struct node *point, int data) {
if (point == NULL) {
     return NULL;
  }
  if (data < point->info) {  // data is in the left sub tree.
      point->lchild = Delete(point->lchild, data);
  } else if (data > point->info) { // data is in the right sub tree.
      point->rchild = Delete(point->rchild, data);
  } else {
     // case 1: no children
     if (point->lchild == NULL && point->rchild == NULL) {
        free(point); // wipe out the memory, in C, use free function
        point = NULL;
     }
     // case 2: one child (right)
     else if (point->lchild == NULL) {
        struct node *temp = point; // save current node as a backup
        point = point->rchild;
        free( temp);
     }
     // case 3: one child (left)
     else if (point->rchild == NULL) {
        struct node *temp = point; // save current node as a backup
        point = point->lchild;
        free( temp);
     }
     // case 4: two children
     else {
	struct node *temp =(struct node *) FindMin(point->rchild); // find minimal value of right sub tree
	point->info = temp->info; // duplicate the node
	point->rchild = Delete(point->rchild, temp->info); // delete the duplicate node
     }
  }
  return point; // parent node can update reference
}
*/
int deleteBST(struct node * start, int data)
{
	struct node *pptr, *ptr, *nodetodel;
	if(start == NULL) {
		printf("The tree is empty");
		return 0;
	}
	
	pptr=ptr = start;
	while(ptr!= NULL)
	{
		if(ptr->info == data ) break;
		pptr=ptr;
		if(data< ptr->info) ptr= ptr->lchild;
		else ptr=ptr->rchild;
	}
	
	if((pptr ==ptr) && (ptr->lchild == NULL) && (ptr->rchild ==NULL))
	{
		printf("a1");
		nodetodel= pptr;
		start= NULL;
		free(nodetodel);
		return 0;
	}
	else if((data==ptr->info) && (ptr->lchild == NULL) && (ptr->rchild ==NULL))
	{
		printf("a2");
		nodetodel= ptr;
		if(pptr->info < ptr->info)
			pptr->rchild = NULL;
		else
			pptr->lchild = NULL;
		free(nodetodel);
		return 0;
	}
	
	else if((data ==ptr->info) && (ptr->lchild != NULL) && (ptr->rchild ==NULL))
	{
		printf("a3");
		if(pptr->rchild == ptr)
			pptr->rchild = ptr->lchild;
		else
			pptr->lchild = ptr->lchild;
		nodetodel = ptr;
	    free(nodetodel);
		return 0;		
	}
	else if((data ==ptr->info) && (ptr->lchild == NULL) && (ptr->rchild !=NULL))
	{
		printf("a4");
		if(pptr->rchild == ptr)
			pptr->rchild = ptr->rchild;
		else
			pptr->lchild = ptr->rchild;
		nodetodel = ptr;
	    free(nodetodel);
		return 0;		
	}
	
	else if((data ==ptr->info) && (ptr->lchild != NULL) && (ptr->rchild !=NULL))
	{
		printf("a5");
		nodetodel = FindMin(ptr->rchild);
		ptr->info = nodetodel->info;
		deleteBST(ptr->rchild,ptr->info );
		return 0;	
	}
	return 0;
}



int inorder( struct node * start)
{
	if(start == NULL) return 0;
	inorder( start->lchild);
	printf("\n Value read is = %d", start->info);
	inorder(start->rchild);
	return 0;
}

int main()
{
	insertTree(10);
	insertTree(1);
	insertTree(7);
	insertTree(5);
	insertTree(17);
	inorder(root);
	deleteBST(root, 10);
	inorder(root);
	return 0;
}

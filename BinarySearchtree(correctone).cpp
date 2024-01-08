#include<iostream>
using namespace std;
struct node
{
	int data;
	node*Llink;
	node*Rlink;
};
class binarysearchtree
{
	public:
		node*createnode(int val)
		{
			node*tmp=new node;
			tmp->data=val;
			tmp->Llink=NULL;
			tmp->Rlink=NULL;
			return tmp;
		}
		node* insert(node*node,int data)
		{		
			if(node==NULL)
			{
				return createnode(data);
			}
			if(data <= node->data)
		{
			node->Llink = insert(node->Llink, data);
		}
		else if(data > node->data)
		{
			node->Rlink = insert(node->Rlink, data);
		}
		return node;
	}
	
	node* search(node* node, int ele) 
	{
    if (node != NULL) 
	{
        if (node->data == ele) 
		{
            cout << "Found" << endl;
            return node;
        }
        if (ele > node->data) 
		{
            node->Rlink = search(node->Rlink, ele);
        } else 
		{
            node->Llink = search(node->Llink, ele);
        }
    } 
	else 
	{
        cout << "Element not found" << endl;
    }
   }

     node*deletion(node*root,int value)
    {
    	if(root==NULL)
    	{
    		return root;
		}
		if(root->data>value)
		{
			root->Llink=deletion(root->Llink,value);
			return root;
		}
		else if(root->data<value)
		{
			root->Rlink=deletion(root->Rlink,value);
			return root;
		}
		if (root->Llink == NULL)
		 {
            node*temp = root->Rlink;
            delete root;
            return temp;
        }
    else if (root->Rlink == NULL) 
	{
        node*temp = root->Llink;
        delete root;
        return temp;
    }
 
    else {
 
        node*succParent = root;
        node*succ = root->Rlink;
        while (succ->Llink != NULL)
		 {
            succParent = succ;
            succ = succ->Llink;
        }
        if (succParent !=root)
        {
            succParent->Llink= succ->Rlink;
        }
        else
        {
           succParent->Rlink = succ->Rlink;
		   root->data = succ->data;
           delete succ;
           return root;
       }
    }
		
	}
		void inorder(node *node)
		{
			if(node!=NULL)
			{
				inorder(node->Llink);
				cout<<node->data<<" ";
				inorder(node->Rlink);
			}
		}
			void preorder(node *node)
		{
			if(node!=NULL)
			{
				cout<<node->data<<" ";
				preorder(node->Llink);
				preorder(node->Rlink);
			}
		}
		void postorder(node *node)
		{
			if(node!=NULL)
			{
				postorder(node->Llink);
				postorder(node->Rlink);
				cout<<node->data<<" ";
			}
		}
};
int main()
{
	
	int n,key,ele;
	node * root = NULL;
	binarysearchtree bst;
	cout << "Enter number of elements : ";
	cin >> n;
	cout<<"Enter elements:";
	for(int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		root = bst.insert(root, value);	
	}
	
	cout<< "Inorder traversal : ";
	bst.inorder(root);
	cout<<endl;
	cout<<"Preorder traversal:";
	bst.preorder(root);
	cout<<endl;
	cout<<"Postorder traversal:";
	bst.postorder(root);
	cout<<endl;
	cout<<"Enter element to search:";
	cin>>ele;
	root=bst.search(root,ele);
	cout<<"enter key to delete:";
	cin>>key;
	root=bst.deletion(root,key);
	cout<<"Modified BST after deleteting a node:";
	bst.inorder(root);
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
}

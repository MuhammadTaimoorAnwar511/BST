#include<iostream>
using namespace std;


struct  tree
{
public:
	int data;
	tree* left;
	tree* right;
	tree()
	{
		//cout << "\nconstructor called\n";
		data = 0;
		left = NULL;
		right = NULL;
	}
	tree(int d)
	{

		data = d;
		left = NULL;
		right = NULL;
	}
	
	~tree()
	{
		cout << "\ndestructor called\n";

	}
	
};

class linked_list
{

public:
	tree* head;
	int count = 0;
	linked_list()
	{
		head = NULL;
		count = 0;
	}
	linked_list& operator =(const linked_list& tempo)
	{
		//cout << "chala";
		head = tempo.head;
		return *this;
	}
	void add_binanrry_tree(int d)
	{
		tree* n = new tree(d);

		if (head == NULL)
		{
			++count;
			head = n;
			return;
		}
		else
		{
			++count;
			add_binanrry_tree_leaf(head, d);
	
		}
	}

	void add_binanrry_tree_leaf(tree* leaf, int d)
	{
		if (d < leaf->data)
		{
			if (leaf->left != NULL)
			{
				add_binanrry_tree_leaf(leaf->left, d);
			}
			else
			{
				leaf->left = new tree;
				leaf->left->data = d;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
			}
		}
		else if (d > leaf->data)
		{
			if (leaf->right != NULL)
			{
				add_binanrry_tree_leaf(leaf->right, d);
			}
			else
			{
				leaf->right = new tree;
				leaf->right->data = d;
				leaf->right->right = NULL;
				leaf->right->left = NULL;
			}
		}
	}

	void find(int d)
	{
		retive(d, head);
	}

	void retive(int d, tree* temp)
	{
		if (temp == NULL) {}

		else
		{
			retive(d, temp->left);

			if (temp->data == d)
			{
				cout << "\nDATA FOUND\n";	
				cout << temp->data << " ";
			}
			else
			{

			}
			retive(d, temp->right);
		}
	}

	void print()
	{
		print_inorder(head);
	}

	void print_inorder(tree* temp)
	{
		if (temp == NULL) {}

		else
		{		
			//cout << "print";
			print_inorder(temp->left);
			//print_inorder(temp->right);
			cout << temp->data << ",";
			print_inorder(temp->right);
			//print_inorder(temp->left);
		}
	}

	//
	
	bool check_bst_left()
	{
		return isbst_left(head->left, head);
	}
	bool isbst_left(tree* temp, tree* h)
	{
		bool left = 0;
		if (temp == NULL) {}

		else
		{
			if (temp->data < h->data )
			{
				left = 1;
			//	cout << temp->data << ",";	
			}
			else
			{
				left = 0;
			}
			if (temp->left!=NULL && temp->right!=NULL)
			{
				if (temp->left->data < temp->right->data && temp->left->data < h->data && temp->right->data < h->data)
				{
					isbst_left(temp->left, h);
				}
			}
			return left;
		}
	}
	bool check_bst_right()
	{
		return isbst_right(head->right, head);
	}

	bool isbst_right(tree* temp, tree* h)
	{
		bool right = 0;
		if (temp == NULL) {}

		else
		{
			if (temp->data > h->data)
			{
				right = 1;
				//cout << temp->data << ",";
			}
			else
			{
				right = 0;
			}
			if (temp->left != NULL && temp->right != NULL)
			{
				if (temp->left->data < temp->right->data && temp->left->data > h->data && temp->right->data > h->data)
				{
					isbst_right(temp->right, h);
				}
			}
			return right;
		}
	}
	
	void printsmaller(int n)
	{
		print_inorder_smaller(n,head);
	}

	void print_inorder_smaller(int n,tree* temp)
	{
		if (temp == NULL) {}
		else
		{
			//cout << "print";
			print_inorder_smaller(n, temp->right);
			//print_inorder_smaller(n,temp->left);
			if (temp->data < n)
			{
				cout << temp->data << ",";
			}
			else{}
			print_inorder_smaller(n, temp->left);
		}
	}
	
	void size()
	{
		cout << count;
	}
	void empty()
	{
		if (head == NULL)
		{
			cout << "\ntree is  EMPTY \n";
		}
		else
		{
			cout << "\ntree is NOT  EMPTY \n";
		}
	}
};

int main()
{
	bool le, ri;
	linked_list l,r;
	int opt=1;
	int val;
	cout << "\n====== BST CREATED  ====\n";
	l.add_binanrry_tree(40);
	l.add_binanrry_tree(30);
	l.add_binanrry_tree(25);
	l.add_binanrry_tree(35);
	l.add_binanrry_tree(50);
	l.add_binanrry_tree(45);
	l.add_binanrry_tree(60);
	cout << "\n==============================================================================\n";
	
	while (opt == 1)
	{
		opt = 0;
		while (opt <= 0 || opt >= 8)
		{
			cout << "\nSELECT OPTIONS \n 1]PRINT BST\n 2]TOTAL NUMBER OF NODES\n 3]CHECK TREE IS EMPTY OR NOT\n 4]FIND SPECIFIC VALUES\n 5]FIND VALUES SMALLER THAT SPECIFIC NUMBER\n 6]CHECK BST OR NOT \n 7] ASSIGNMENT OPERATOR \n\n= ";
			cin >> opt;
		}

		switch (opt)
		{
		case 1:
			cout << "\n====PRINT BST TREE ===========\n";
			l.print();
			break;
		case 2:
			cout << "\n======# of nodes==========\n";
			l.size();
			break;
		case 3:
			cout << "\n=====empty==========\n";
			l.empty();
			break;
		case 4:
			cout << "\n======FIND DATA===========\n";
			cin >> val;
			l.find(val);
			break;
		case 5:
			cout << "\n=====SMALLER VALUES=======\n";
			cin >> val;
			l.printsmaller(val);
			break;
		case 6:
			cout << "\n=========CHECK ============\n";
			le = l.check_bst_left();
			ri = l.check_bst_right();

			if (le == 0 || ri == 0)
			{
				cout << "\nTREE IS NOT BST\n";
			}
			else
			{
				cout << "\nTREE IS BST\n";
			}
			break;
		case 7:
			cout << "\n========== ASSIGN done ==================\n";
			r = l;
			cout << "\n========== PRINT BST TREE ===============\n";
			r.print();
			cout << endl;
			cout << "\n=========== DATA FIND ===================\n";
			r.find(50);
			cout << "\n========================================\n";
			break;
		}
		cout << "\n\nPress 1 to continue again\nPress 2 to exit program \n= ";
		cin >> opt;
	}
	

	return 0;
}
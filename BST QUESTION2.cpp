#include<iostream>
#include<fstream>
#include<string>
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
		cout << "chala";
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

	void print()
	{
		print_preorder(head);
	}

	void print_preorder(tree* temp)
	{
		if (temp == NULL) {}

		else
		{		
			cout << temp->data << " , ";
			print_preorder(temp->left);
			print_preorder(temp->right);
		}
	}
	//
	void write()
	{
		write_preorder(head);

	}

	void write_preorder(tree* temp)
	{
		int v;
		if (temp == NULL) {}

		else
		{
			fstream myfile;
			myfile.open("file.txt", ios::app);//write
			if (myfile.is_open())
			{
				//cout << "file write \n";
				v =temp->data;
				myfile << v << endl;;
				myfile.close();
			}
			write_preorder(temp->left);
			write_preorder(temp->right);
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
	linked_list l;
	int opt=1;
	int val;
	int node_val;
	
	
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
		while (opt <= 0 || opt >= 7)
		{
			cout << "\nSELECT OPTIONS \n 1]PRINT BST\n 2]TOTAL NUMBER OF NODES\n 3]CHECK TREE IS EMPTY OR NOT\n 4]CHECK BST OR NOT \n 5]WRITE IN FILE \n 6]Read from file \n\n= ";
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
			cout << "\n==============================\n";
			break;
		case 5:
			l.write();
			break;
		case 6:
			linked_list k;
			fstream readfile;
			readfile.open("file.txt", ios::in);//read
				if (readfile.is_open())
				{
					int v;
					while(readfile>>v)
					{
						k.add_binanrry_tree(v);
					}
				}
				readfile.close();
				cout << "\n======================OUTPUT================\n";
				k.print();
				cout << "\n===============================================\n";
				cout << "\n=========CHECK ============\n";
				le = k.check_bst_left();
				ri = k.check_bst_right();

				if (le == 0 || ri == 0)
				{
					cout << "\nNEW TREE IS NOT BST\n";
				}
				else

				{
					cout << "\nNEW TREE IS BST\n";
				}
				cout << "\n==============================\n";
			break;
		}

		cout << "\n\nPress 1 to continue again\nPress 2 to exit program \n= ";
		cin >> opt;
	}
	

	return 0;
}
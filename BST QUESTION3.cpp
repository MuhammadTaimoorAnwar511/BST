#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int u_ch = 0;
int first_time = 1;
int c_bit=0;
class huffman
{
public:
	char ch;
	int frequency;
	int edge;
	int arr[20];
	huffman* left_down;
	huffman* right_down;

	huffman()
	{
		for (int i = 0; i < 20; i++)
		{
			arr[i] = 2;
		}
		ch = '0';
		frequency = 0;
		left_down=NULL;
		right_down=NULL;
	}
	huffman(char c,int f)
	{
		for (int i = 0; i < 20; i++)
		{
			arr[i] = 2;
		}
		ch = c;
		frequency = f;
		left_down = NULL;
		right_down = NULL;
	}
};

class qeue_freq
{
public:

	char ch;
	int frequency;
	qeue_freq* next;

	qeue_freq()
	{
		ch='0';
		frequency = 0;
		next = NULL;
	}
	qeue_freq(char c)
	{
		ch = c;
		frequency =0 ;
		next = NULL;
	}
	


};
class link
{
public:
	qeue_freq* q_head;
	huffman* h_head;
	huffman* current;
	link()
	{
		q_head = NULL;
		h_head = NULL;
		current = NULL;
	}

	void fetch_from_qeue()
	{
		    huffman* h = new huffman;
			huffman* h1=new huffman;
			huffman* h2=new huffman;
			int sum = 0;

		if (q_head!=NULL)
		{

			if (first_time == 1)
			{
				cout << "\n==================qeue=================\n";	
				qeue_freq* temp1 = q_head;
				qeue_freq* temp2 = q_head->next;

				h_head = h;

				 h1->ch = q_head->ch;
				 h1->frequency = q_head->frequency;
				 
				 h2->ch = q_head->next->ch;
				 h2->frequency = q_head->next->frequency;
				qeue_freq* t1 = q_head;
				qeue_freq* t2 = q_head->next;
				
				q_head = t2->next;
				delete t1;
				delete t2;
			
			}
			else
			{
				cout << "\n==================qeue=================\n";
				qeue_freq* temp1 = q_head;
				qeue_freq* t1 = q_head;
				
				h1->ch = q_head->ch;
				h1->frequency = q_head->frequency;
				q_head = t1->next;
				delete t1;
		
			}
		}

		else
		{
			cout << "\n EMPTY \n";
			return;
		}

		if(first_time == 1)
		{
			h->ch ='*';
			sum = h1->frequency + h2->frequency;
			h->frequency = sum;
			sum = 0;
			
			if(h1->frequency <= h2->frequency)
			{
				h->left_down = h1;
				h1->edge = 0;
				h1->arr[0] = 0;
				h->right_down = h2;
				h2->edge = 1;
				h2->arr[0] = 1;
			}
			else
			{
				h->left_down = h2;
				h2->edge = 0;
				h2->arr[0] = 0;
				h->right_down = h1;
				h1->edge = 1;
				h1->arr[0] = 1;
			}
			current = h;
			cout << "H H  = " << h->ch << " = " << h->frequency << " left " << h->left_down << " right " << h->right_down << endl;
			cout << "H L  = " << h->left_down->ch <<  " = " << h->left_down->frequency      << " left " << h->left_down->left_down << " right " << h->right_down->right_down << endl;
			cout << "H R  = " << h->right_down->ch << " = " << h->right_down->frequency     << " left " << h->left_down->left_down << " right " << h->right_down->right_down << endl;
			first_time = 2;
			cout << "\n/////////////////////////////////////////////////////\n";
		}
		else
		{	
			h->ch = '*';
			sum = h1->frequency + current->frequency;
			h->frequency = sum;
			sum = 0;
			
			if (h1->frequency <= current->frequency)//left add
			{
				h->left_down = h1;
				h1->edge = 0;
				h->right_down = current;
				h1->edge = 1;
				find_bit(0);
			}
			else//right add
			{
				h->left_down = current;
				current->edge = 0;
				h->right_down = h1;
				h1->edge = 1;
				find_bit(1);
			}
			h_head = current;
			current = h;
			cout << "H H  = " << h->ch << " = " << h->frequency << " left " << h->left_down                                    << " right " << h->right_down << endl;
			cout << "H L  = " << h->left_down->ch << " = " << h->left_down->frequency   << " left " << h->left_down->left_down << " right " << h->right_down->right_down << endl;
			cout << "H R  = " << h->right_down->ch << " = " << h->right_down->frequency << " left " << h->left_down->left_down << " right " << h->right_down->right_down << endl;
			cout << "\n/////////////////////////////////////////////////////\n";
		}
	}

	void find()
	{
		retive(h_head);
	}

	void retive(huffman* temp)
	{
		
		if (temp == NULL) 
		{
		//	cout << "ok";
		}

		else
		{
			retive(temp->left_down);
			
			
				cout<<"[ " << temp->ch << " = " << temp->frequency << " edge = " << temp->edge << "] " << "address = ";
				fstream reencod;
				reencod.open("reconstruct.txt", ios::app);// write//
				if (reencod.is_open())
				{
					reencod << temp->ch;
				}
			
				
				for (int k = 0; k < 20; k++)
				{
					fstream encod;
					encod.open("encoded.txt", ios::app);// writte//
					if (temp->arr[k] != 2)
					{
						
						if (encod.is_open())
						{
							c_bit = c_bit + 1;
							encod << temp->arr[k];
						}
						else{}
						
						cout << temp->arr[k] << " ";
					}
				}
				fstream encod;
				encod.open("encoded.txt", ios::app);// read//
				encod << "\n";
				cout << endl;
				retive(temp->right_down);
		}
	}
	void find_bit(int i)
	{
		retive_bit( i, h_head);
	}
	void check()
	{
		cout << "\nORIGINAL AND RECONSTRUCTED IS NOT SAME \n";
	}
	void retive_bit(int i, huffman* temp)
	{
		if (temp == NULL)
		{
			//	cout << "ok";
		}

		else
		{
			retive_bit( i, temp->left_down);

			for (int k = 0; k < 20; k++)
			{
				if (temp->arr[k] == 2)
				{
					temp->arr[k] = i;
					break;
				}
				
				//cout <<temp->arr[k] << " ";
			}
		//	cout << endl;
			//	cout << "\nDATA FOUND\n";
				//cout << "[ " << temp->ch << " = " << temp->frequency << "  edge = " << temp->edge << "] " << endl;
			
			retive_bit(i, temp->right_down);
			
		}
	}

	void show_qeue()
	{
		qeue_freq* temp = q_head;

		while(temp!=NULL)
		{
			cout<<temp->ch<<" = ";
			cout<<temp->frequency<<"  \n";
			temp = temp->next;
		}
	}

	void check_unique(char c)
	{
		bool rep = 0;
		qeue_freq* temp = q_head;

		while (temp != NULL)
		{
			if (temp->ch == c)
			{
				cout << "similar =" << c << " \n";
				temp->frequency = temp->frequency + 1;
				rep = 1;
			}
			temp = temp->next;
		}
		if (rep == 1)
		{
			return;
		}
		else
		{
			u_ch = u_ch + 1;
			add_in_qeue(c);

			return;
		}
	}
	void add_in_qeue(char c)
	{
		qeue_freq* n = new qeue_freq(c);

		if (q_head == NULL)
		{
			
			q_head = n;
			q_head->frequency = q_head->frequency + 1;
			
			return;
		}
		else
		{
			qeue_freq* temp = q_head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
			temp->next->frequency = temp->next->frequency + 1;
		}
	}

	
	void sortList()
	{
		
		qeue_freq* t1 = q_head;
		qeue_freq* t2;
		int f;
		char c;
		if (q_head == NULL) {}
		else
		{

			while (t1 != NULL)
			{
				t2 = q_head;

				while (t2 != NULL)
				{
					if (t1->frequency < t2->frequency)
					{
						f = t1->frequency;
						c = t1->ch;
						t1->frequency = t2->frequency;
						t1->ch = t2->ch;
						t2->ch = c;
						t2->frequency = f;
					}
					else
					{
					}
					t2 = t2->next;
				}
				t1 = t1->next;
			}
		}
	}
	
};

int main()
{
	int o_count = 0;

	string s;
	int s_l;
	char c;
	int o_size;
	fstream org_file;
	link q_head;
	link h_head;
	org_file.open("original.txt", ios::in);// read//
	fstream encod;
	
	encod.open("encoded.txt", ios::out);// read//
	if (org_file.is_open())
	{
		
		while (org_file.get(c))
		{
			    o_count = o_count + 1;
				q_head.check_unique(c);
				//cout<<"add in qeue=" << c << "\n";
		}
	}
	else{}
	cout << "\n=====================================\n";
	q_head.sortList();
	q_head.show_qeue();
	cout << "\n=====================================\n";
	o_size = o_count * 7;
	cout << "total characters =" << o_count << endl;
	cout << "unique  characters =" << u_ch << endl;
	cout << "original file size in bits =" << o_size;
	for (int i = 0; i < u_ch ; i++)
	{
		q_head.fetch_from_qeue();	
		q_head.show_qeue();
	}
	cout << "\n================END==================\n";
	q_head.find();
	cout << "\n---------------------------------\n";
	cout << "\nencoded file bit =" << c_bit << endl;
	cout << "\n================CHECK==================\n";
	q_head.check();
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next, *prev;
	Node(int data):data(data) , next(NULL) , prev(NULL){}
	Node():next(NULL) , prev(NULL){}
};

struct linkList
{
	Node* Head;
	linkList(): Head(NULL){}

	void addNode(Node *cur)
	{
		if(Head==NULL) Head = cur;
		else 
		{
			cur->next = Head;
			Head->prev = cur;
			Head= cur;
		}
	}

	void addLast(Node *now)
	{
		if(Head==NULL) 
		{
			Head= now;
			return;
		}
		Node * cur = Head;
		while(cur!=NULL)
		{
			if(cur->next==NULL)
			{
				cur->next = now;
				now->prev = cur;
				break;
			}else cur = cur->next;
		}
	}

	void removeNode(Node* rem)
	{
		if(rem->next==NULL && rem->prev==NULL)
			Head = NULL;
		else if(rem->prev==NULL)
			Head= Head->next;
		else if(rem->next==NULL)
			rem->prev->next = NULL;
		else 
		{
			rem->prev->next = rem->next;
			rem->next->prev = rem->prev;
		}
		delete(rem);
	}

	void removeDuplicate()
	{
		Node *Now = Head;

		while(Now!=NULL)
		{
			Node *next = Now->next;
			while(next!=NULL)
			{
				if(next->data==Now->data)
				{
					Node *temp = next->next;
					removeNode(next);
					next = temp;
				}
				else next=next->next;
			}
			Now=Now->next;
		}
		return;
	}

	int calcKth(Node* cur,int k,Node** sol)
	{
		if(cur==NULL) return 1;
		int ret = calcKth(cur->next,k,sol);
		if(ret==k) *sol = cur;
		return ret+1;
	}

	Node* findKthElement(int k)
	{
		Node* Kth = NULL;
		calcKth(Head ,k , &Kth);
		return Kth;
	}


	void addNode(Node* &h ,Node* &temp)
	{
		if(h!=NULL) h->prev = temp;
		temp->next = h;
		h = temp;
		return;
	}

	void partitionX(int x)
	{
		Node *h1 = NULL;
		Node *h2 = NULL;
		Node *cur = Head;

		while(cur!=NULL)
		{
			Node *temp = new Node(cur->data);
			if(temp->data<x)
				addNode(h1 , temp);
			else addNode(h2 , temp);
			temp = cur;
			cur = cur->next;
			delete(temp);
		}

		PrintList();

		if(h1==NULL) Head = h2;
		else if(h2==NULL) Head = h1;
		else
		{
			cur = h1;
			while(cur!=NULL)
			{
				if(cur->next==NULL)
				{
					h2->prev = cur;
					cur->next = h2;
					break;
				}
				else cur = cur->next;
			}
			Head = h1;
		}
	}

	void PrintList()
	{
		Node *cur = Head;
		cout<<"start : "<<endl;
		while(cur!=NULL)
		{
			cout<<cur->data<<endl;
			cur = cur->next;
		}
		cout<<"END "<<endl;
	}
};

void addBackword(Node *left,Node *right,int carry,linkList &sol)
{
	if(left==NULL && right==NULL)
	{
		if(carry!=0) sol.addLast(new Node(carry));
		return;
	}

	int sum = carry+(left==NULL ? 0 : left->data)+(right==NULL ? 0 : right->data);
	sol.addLast(new Node(sum%10));

	addBackword(left!=NULL ? left->next : left , right!=NULL ? right->next : right , sum/10 , sol);
}

int addForword(Node *left,Node *right ,linkList &sol)
{
	if(left==NULL && right==NULL)
	{
		return 0;
	}

	int sum = addForword(left!=NULL ? left->next : left , right!=NULL ? right->next : right , sol);

	sum += (left==NULL ? 0 : left->data)+(right==NULL ? 0 : right->data);
	sol.addNode(new Node(sum%10));

	return sum/10;
}

int main()
{
	linkList *linklist = new linkList();

	Node *d;
	d = new Node(10);
	linklist->addNode(d);
	d = new Node(10);
	linklist->addNode(d);
	d = new Node(12);
	linklist->addNode(d);
	d = new Node(13);
	linklist->addNode(d);
	d = new Node(12);
	linklist->addNode(d);
	d = new Node(15);
	linklist->addNode(d);

	linklist->PrintList();

	// linklist->removeNode(linklist->Head->next);
	// linklist->removeNode(linklist->Head->next);
	// linklist->removeDuplicate();
	// linklist->PrintList();

	// cout<<linklist->findKthElement(3)->data<<endl;

	linklist->partitionX(11);
	linklist->PrintList();


	linkList *l1 = new linkList();
	d = new Node(2);
	l1->addLast(d);
	d = new Node(3);
	l1->addLast(d);
	d = new Node(4);
	l1->addLast(d);
	l1->PrintList();


	linkList *l2 = new linkList();
	d = new Node(5);
	l2->addLast(new Node(5));
	d = new Node(6);
	l2->addLast(d);
	d = new Node(7);
	l2->addLast(d);
	l2->PrintList();

	linkList sol;

	addBackword(l1->Head , l2->Head ,0, sol);
	sol.PrintList();

	linkList sol2;

	int c= addForword(l1->Head , l2->Head , sol2);

	while(c) 
	{
		sol2.addNode(new Node(c%10));
		c/=10;
	}

	sol2.PrintList();

	return 0;
}
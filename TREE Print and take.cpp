#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
	public:
	T data;
	vector<TreeNode<T>*>children;
	TreeNode(T data)
	{

		this->data=data;
	}
	~TreeNode()
	{
		for(int i=0;i<children.size();i++)
		{
			delete(children[i]);
		}
	}
};
TreeNode<int>* input()
{
	cout<<"enter data"<<endl;//2 4
	int rootData;
	cin>>rootData;
	TreeNode<int>*root= new TreeNode<int>(rootData);
	int nc;//2 1 0
	cout<<"enter no. of child"<<endl;
	cin>>nc;
	// 1 2 3 4
	for(int i=0;i<nc;i++)
	{
		TreeNode<int>*child=input();
		root->children.push_back(child);
	}
	return root;
}
TreeNode<int>* input2()
{
	int rootData;
	cout<<"enter root data"<<endl;
	cin>>rootData;
	TreeNode<int>*root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*>pq;
	pq.push(root);
	while(pq.size()>0)//2
	{
		TreeNode<int>*front = pq.front();
		pq.pop();
		int numChild;//2 //1 //0 //0
		cout<<"enter num of child of "<<front->data<<endl;
		cin>>numChild;
		for(int i=0;i<numChild;i++)
		{
			cout<<"enter"<<i<<" th child data of "<<front->data<<endl;
			int childData;
			cin>>childData;//2 //3//4
			TreeNode<int>*child = new TreeNode<int>(childData);
			pq.push(child);
			front->children.push_back(child);
			
		}
	}
	return root;
}
void print(TreeNode<int>*root)
{
	//edge case
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
			cout<<root->children[i]->data<<",";
			//print(root->children[i]);
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		print(root->children[i]);
	}
	
}
//1 2 3 4 
int count(TreeNode<int>*root)
{
	int ans = 1;
	for(int i=0;i<root->children.size();i++)
	{
		ans = ans + count(root->children[i]);
	}
	return ans;
}
int height(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ans =0;
	for(int i=0;i<root->children.size();i++)
	{
		int t=height(root->children[i]);
		ans = max(t,ans);
	}
	return ans+1;
}
void depth(TreeNode<int>*root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==0)
	{
		cout<<root->data<<" ";
	}
	for(int i=0;i<root->children.size();i++)
	{
		depth(root->children[i],k-1);
	}
	return ;
}
int countleaf(TreeNode<int>*root)
{

	if(root->children.size()==0)
	{
		return 1;
	}
	int count = 0;
	for(int i=0;i<root->children.size();i++)
	{
		count=count+countleaf(root->children[i]);
	}
	return count;
}
void pre(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++)
	{
		pre(root->children[i]);
	}
	return;
}
void post(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return ;
	}
	for(int i=0;i<root->children.size();i++)
	{
		post(root->children[i]);
	}
	cout<<root->data<<" ";
}
void deletenode(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		deletenode(root->children[i]);
	}
	delete root;
}
void printLevel(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	queue<TreeNode<int>*>pq;
	pq.push(root);
	while(pq.size()!=0)
	{
		TreeNode<int>*front = pq.front();
		pq.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++)
		{
			cout<<front->children[i]->data<<" ";
			pq.push(front->children[i]);
		}
		cout<<endl;
	}
}
int sum(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ans=root->data;
	for(int i=0;i<root->children.size();i++)
	{
		ans=ans+sum(root->children[i]);
		
	}
	return  ans;
}
int maxi(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return -1;
		
	}
	int ans = root->data;
	for(int i=0;i<root->children.size();i++)
	{
		ans=max(ans,maxi(root->children[i]));
	}
	return ans;
}
int main()
{
//		TreeNode<int>*root = new TreeNode<int>(1);
//	TreeNode<int>*node1 = new TreeNode<int>(2);
//	TreeNode<int>*node2 = new TreeNode<int>(3);
//	root->children.push_back(node1);
//	root->children.push_back(node2);
//	TreeNode<int>*node3 =  new TreeNode<int>(4);
//	node1->children.push_back(node3);
	TreeNode<int>* root = input2();
//	print(root);
//	cout<<endl;
//	cout<<count(root)<<endl;
//	cout<<height(root)<<endl;
//	depth(root,2);
//	cout<<endl;
//	cout<<countleaf(root)<<endl;
//	pre(root);
//	cout<<endl;
//	post(root);
//	deletenode(root);
//	delete root;
	print(root);
	
	cout<<"level"<<endl;
printLevel(root);
cout<<endl;
cout<<"sum"<<sum(root)<<endl;
cout<<"maxi"<<endl;
cout<<maxi(root)<<endl;
	return 0;
}

//10:20,30,40
//20:40,50
//30:
//40:
//40:
//50:

#include"myvector.cpp"
#include"bits/stdc++.h"
using namespace std;
int main()
{
	myVector<int> V(7,6);	
	cout<<"\nVector ban dau:";
	for(int i=0;i<V.size();i++) 
		cout<<V[i]<<" ";
		
	for(int i=0;i<V.size();i++) 
		V[i]=i*i;
		
	cout<<"\nVector binhphuong:";
	for(int i=0;i<V.size();i++)
		cout<<V[i]<<" ";
		
	V.push_back(11);
	V.push_back(13);
	V.insert(2,20);
	
	cout<<"\nVector :";
	for(int i=0;i<V.size();i++) 
		cout<<V[i]<<" ";
		
	cout<<"\nDuyet :";
	for(myVector<int>::iterator it=V.begin();it!=V.end();++it) 
		cout<<*it<<"\t";
			
	cout<<"\nDuyet auto : ";
	for(auto x:V) 
		cout<<x<<" ";
	myVector<int> Q;
	Q=V;
	cout<<"\nDuyet auto Q: ";
	for(auto x:Q) 
		cout<<x<<" ";
	Q.erase(Q.begin()+2);
	cout<<"\nDuyet auto Q: ";
	for(auto x:Q) 
		cout<<x<<" ";
	cout<<"\nDuyet nguoc Q: ";
	for(myVector<int>::reverse_iterator it=Q.rbegin();it!=Q.rend();++it) 
		cout<<*it<<" ";	
}

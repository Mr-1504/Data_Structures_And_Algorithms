#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<float> v;
	int n;
	float x;
	cout<<"Nhap n=";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<" = ";
		cin>>x;
		v.push_back(x);
	}
	cout<<"Cac phan tu hien co trong vector:";
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n In cac phan tu bang cach su dung bo lap xuoi:";
	vector<float>::iterator it;
	for(it = v.begin(); it!=v.end();it++)
		cout<<*it<<"  ";
	cout<<"\n In cac phan tu bang cach su dung bo lap nguoc:";		
	vector<float>::reverse_iterator rit ;
	for(rit = v.rbegin(); rit!=v.rend();rit++)
		cout<<*rit<<"  ";
		
	it = v.begin();
	it++;	
	v.erase(it);
	cout<<"\nCac phan tu hien co trong vector:";
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		
}

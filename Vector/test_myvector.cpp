#include<bits/stdc++.h>
#include"myvector.cpp"
using namespace std;
void in(myVector<float> v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<"\t";
}

int main()
{
	myVector<float> v;
	v.push_back(10);
	v.push_back(100);
	v.push_back(1000);
	v.push_back(10000);
	//v.insert(2,500);
	
	cout<<"Vector v:";
	in(v);
	cout<<"\n Duyet vector bang bo lap xuoi:";
	myVector<float>::iterator it;
	for(it = v.begin(); it!=v.end(); it++)
		cout<<*it <<"\t";	
	cout<<"\n Duyet vector bang bo lap nguoc:";
	myVector<float>::reverse_iterator rit ;
	for(rit = v.rbegin(); rit!=v.rend(); rit++)
		cout<<*rit <<"\t";
	
}

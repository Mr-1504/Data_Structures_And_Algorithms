#include<bits/stdc++.h>
using namespace std;
template<class T>
class Matrix{
	private:
		int m,n;
		T *ele;
	public:
		Matrix()
		{
			m=0;
			n=0;
			ele = NULL;
		}
		Matrix(int m1, int n1)
		{
			m=m1;
			n=n1;
			ele = new T[m*n];;
		}
		void Nhap()
		{
			cout<<"Nhap so hang, so cot:";
			cin>>m>>n;
			if (ele!=NULL)
				delete []ele;
			ele = new T[m*n];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
				{
					cout<<"pt["<<i<<"]["<<j<<"]=";
					cin>> ele[i*n+j];
				}
		}
		void In()
		{
			
			for(int i=0;i<m;i++)
			{
				cout<<"\n";
				for(int j=0;j<n;j++)
					cout<<ele[i*n+j]<<"\t";
			}
		}
	Matrix operator +(Matrix a)
	{
		if(m!=a.m || n!=a.n)
			return Matrix();	
		else
		{
			Matrix c(m,n);
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					c.ele[i*n+j]=ele[i*n+j] + a.ele[i*n+j];
			return c;
		}		
		
	}	
	Matrix operator -() //Ðoi dau
	{
		Matrix c(m,n);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				c.ele[i*n+j]=-ele[i*n+j];
			return c;		
	}		
	
};
int main()
{
	Matrix<int> a,b,c,d;
	a.Nhap();
	b.Nhap();
	c = a+b;
	c.In();
	d =-a;
	cout<<"\nMa tran d:\n";
	d.In();
	
}

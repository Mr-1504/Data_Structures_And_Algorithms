#include<iostream>
#ifndef __vector__cpp__
#define __vector__cpp__
using namespace std;
template <class T>
class myvector_reverse_iterator
{
	T *curr;	
	public:
		myvector_reverse_iterator(T *c=0) {curr=c;}
		myvector_reverse_iterator<T> &operator=(myvector_reverse_iterator<T> it) 
		{
			this->curr=it.curr; 
			return *this;
		}
		myvector_reverse_iterator<T> operator++()//++curr
		{
			curr--;
			return curr;
		}
		myvector_reverse_iterator<T> operator++(int)//++curr
		{
			myvector_reverse_iterator<T> tmp=curr;
			curr--;
			return tmp;
		}
		T &operator*() {return *curr;}
		bool operator!=(myvector_reverse_iterator<T> t) {return curr!=t.curr;}
};

template<class T>
class myvector
{
	private:
		int cap,num;
		T *buff;
	public:
		myvector() {
			cap=1;
			num=0;
			buff=new T[1];
		}
		myvector(int k,T x) {
			cap=num=k;
			buff=new T[k];
			for(int i=0;i<k;i++) 
				buff[i]=x;
		}
		~myvector() {if(buff) delete[]buff;}
		int capacity() {return cap;}
		int size() {return num;}
		bool empty() {return num==0;}
		void pop_back() {if(num>0) num--;}
		void extend(int newcap)
		{
			if(newcap<cap) return;
			cap=newcap;
			T *temp=new T[cap];
			for(int i=0;i<num;i++) temp[i]=buff[i];
			if(buff) 
				delete []buff;
			buff= temp;			
		}
		T &back() {return buff[num-1];}
		void push_back(T x)
		{
			if(num==cap) extend(cap*2);
			buff[num++]=x;
		}
		T &operator[](int k) {return buff[k];}
		void insert(int k,T x)
		{
			if(cap==num) 
				extend(cap*2);
			for(int i=num-1;i>=k;i--) 
				buff[i+1]=buff[i];
			buff[k]=x;
			num++;
		}
		void erase(int k)
		{
			if (k<0 || k>size())
				return;
			for(;k<size();k++) 
				buff[k] = buff[k+1];
			num--;
		}
		myvector &operator=(myvector<T> V)
		{
			this->num=V.num;
			this->cap=V.cap;
			if(cap)
			{
				this->buff=new T[cap];
				for(int i=0;i<num;i++) this->buff[i]=V.buff[i];
			}
			else this->buff=0;
			return *this;
		}
		typedef T *iterator; 
		iterator begin() {return buff;}
		iterator end() {return buff+num;}
		typedef myvector_reverse_iterator<T> reverse_iterator;
		reverse_iterator rbegin() 
		{
			return reverse_iterator(buff+num-1);
		} 
		reverse_iterator rend() 
		{
			return reverse_iterator(buff-1);
		}
			 
};
#endif


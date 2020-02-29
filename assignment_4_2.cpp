//Name:Supriya Das  Roll:301910501008
/* 2.	Design a COMPLEX class, which will behave like normal integer with respect to 
"	addition, 
"	subtraction, 
"	accepting the value and 
"	displaying the value.*/

#include<iostream>
using namespace std;
class complex
{
	private:
		int a,b;
	public:
		get_complex()
		{
			cin>>a>>b;
		}
		complex operator+(complex q)
		{
			complex p;
			p.a=a+q.a;
			p.b=b+q.b;
			return p;
		}	
		complex operator-(complex q)
		{
			complex p;
			p.a=a-q.a;
			p.b=b-q.b;
			return p;
		}
		void display()
		{
			cout<<"\nThe result is:"<<a<<"+i"<<b;
		}
};
int main()
{
	complex k1,k2,k3,k4;
	printf("\nEnter the first complex:");
	k1.get_complex();
	printf("\nEnter the second complex:");
	k2.get_complex();
	k3=k1+k2;
	printf("\nAfter addition:");
	k3.display();
	k4=k1-k2;
	printf("\nAfter subtraction:");
	k4.display();
	return 0;
}

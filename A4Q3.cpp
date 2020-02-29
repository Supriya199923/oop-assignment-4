//Name:Supriya Das  Roll:301910501008
/* 3.	Design an ARRAY class with the following features:
a.	Array object may be declared for a specific size and a value for initializing all the elements. If this it is to be assumed as a 0.
b.	An array object may be declared and initialized with another object.
c.	An array object may be declared and initialized with another array (not the object, standard array as in C language).

Let a and b are two objects:
i.	a+b will add corresponding elements.
ii.	a=b will do the assignment.
iii.	a[I] will return the ith element of the object.
iv.	a*5 or 5*a will multiply the element with 5.

*/
#include<bits/stdc++.h>
using namespace std;
class ARRAY
{
   int size;
   int *a;
   public:
    ARRAY(int len,int ele)// constructor case a initialising with "ele"
    {
        size=len;
        a=new int[size];
        for(int i=0;i<size;i++)
          a[i]=ele;
      }
    ARRAY(){}
    ARRAY(const ARRAY &obj) //copy constructor case b
    {
        size=obj.size;
        a=new int [size];   //declaring an array dynamically
        for(int i=0;i<size;i++)
          a[i]=obj.a[i];

    }
    ARRAY(int arr[],int size1)//constructor case c
    {
        size=size1;
        a=new int [size];
        for(int i=0;i<size;i++)
        {
           a[i]=arr[i];
        }
    }
    void display()
    {
        cout<<"\nSize:"<<size<<"\n";
        cout<<"Elements:";
        for(int i=0;i<size;i++)
          cout<<a[i]<<" ";
        cout<<"\n";
    }
    ARRAY operator+(ARRAY obj)
    {
       ARRAY temp;
       temp.size=obj.size;
       temp.a=new int[temp.size];
       for(int i=0;i<temp.size;i++)
          temp.a[i]=obj.a[i]+a[i];
       return temp;
    }
    int operator[](int ind)
    {
       return a[ind];
    }
    friend ARRAY operator*(int fact,ARRAY obj)
    {
        ARRAY temp;
         temp.size=obj.size;
         temp.a=new int[temp.size];
         for(int i=0;i<temp.size;i++)
         {
             temp.a[i]=fact*obj.a[i];
         }
        return temp;
    }
    friend ARRAY operator*(ARRAY obj,int fact)
    {
        ARRAY temp;
         temp.size=obj.size;
         temp.a=new int[temp.size];
         for(int i=0;i<temp.size;i++)
         {
             temp.a[i]=fact*obj.a[i];
         }
         return temp;
    }
};
int main()
{
  cout<<"\n Initialising object 1 with constructor 1 and making all elements = 6 and size = 9";
  ARRAY a1(9,6);
  a1.display();
  cout<<"\n Initialising object 2 by equating with object 1 (copy constructor)";
  ARRAY a2=a1;
  a2.display();
  int x[9]={9,8,7,6,5,4,3,2,1};
  cout<<"\n Initialising object 3 with a standard array and size 4(constructor 3)";
  ARRAY a3(x,9);
  a3.display();
  ARRAY a4=a1+a3;
  cout<<"After adding first and third objects and equating with object 4 : ";
  a4.display();
  cout<< "Enter the element to view : ";
  int c;
  cin>>c;
  cout<<"Element is:"<<a4[c-1]<<"\n";
  int fact;
  cout<<"Enter the factor to multiply with object 4(added array) : ";
  cin>>fact;
  cout<<"After applying fact*(object)";
  ARRAY a5=fact*a4;
  a5.display();
  cout<<"After applying (object)*fact";
  ARRAY a6=a4*fact;
  a6.display();
}

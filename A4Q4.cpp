//Name:Supriya Das  Roll:301910501008
/*4.	Design a STRING class, which will have the initialization facility similar to array class. Provide support for 
"	Assigning one object for another, 
"	Two string can be concatenated using + operator, 
"	Two strings can be compared using the relational operators.

*/
#include<bits/stdc++.h>
#include<string>
using namespace std;
class STRING{
   int length;
   string s;
   public:
    STRING(){}
    STRING(int len,string s1)
    {
       length=len;
       s=s1;
    }
    STRING operator=(STRING obj)
    {
        STRING temp;
        temp.length=obj.length;
        temp.s=obj.s;
        return temp;
    }
    STRING operator+(STRING obj)
    {
        STRING temp;
        temp.length=length+obj.length;
        temp.s=s+obj.s;
        return temp;
    }
    void operator>(STRING obj1)
    {
    	cout<<"\nAfter comparison: ";
       if(length>obj1.length)cout<<s<<">"<<obj1.s<<"\n";
       if(length<obj1.length)cout<<s<<"<"<<obj1.s<<"\n";
       if(length==obj1.length)cout<<s<<"=="<<obj1.s<<"\n";
    }
    void display()
    {
       	cout<<"String is:"<<s<<"\n";
		 cout<<"\nLength is:"<<length<<"\n";
    }
};

int stringlen(string s1)
{
  int i;
  for(i=0;s1[i]!='\0';i++);
  return i;
}
int main()
{
    string str1,str2;
    int l;
    cout<<"\nEnter first string : ";
    cin>>str1;
    l=stringlen(str1);
    STRING s1(l,str1);
    cout<<"\nEnter second string : ";
    cin>>str1;
    l=stringlen(str1);
    STRING s2(l,str1);
    s1.display();
    s2.display();
    cout<<"\nAfter concatination and assignment: ";
    STRING s3=s1+s2;
    s3.display();
    s1>s2;
}

//Name:Supriya Das  Roll:301910501008
//5.	Modify the STRING class so that assigning/initializing a string by another will not copy it physically but will keep a reference count, which will be incremented. Reference value 0 means the space can be released.
#include<string.h>

#include<iostream>

using namespace std;

class STRING

{

  char *s;
  int len ;
  static int refcount;
public:
  STRING()
  {
    s=NULL;
    len=0;
  }
  STRING(int size,char *a)
  {
    len=size;
    s = new char[size+1];
    strcpy(s,a);
  }
  STRING(const STRING &T)
  {
    s=T.s;
    refcount++;
  }
  STRING(string st)
  {
    const char *a= st.c_str();
    len=strlen(a);
    s=new char[len+1];
    strcpy(s,a);
  }
  ~STRING()
  {
    if(refcount==0)
    {
    delete(s);
    cout<<"The space is now realeased"<<endl;
    }
   else
  {
  cout<<"reference deleted"<<endl;
  refcount--;
  }
}
  void display();
  void getrefcount()
  {
    cout<<"The reference count is "<<refcount<<endl;
  }
  void operator =(STRING);
};

void STRING::display()
{
cout<<s<<endl;
}
void STRING::operator =(STRING T)
{
  s=T.s;
  refcount++;
}
int STRING::refcount=0;

int main()
{
  STRING a(7,"Supriya");
  STRING b(a);
  STRING c=a;
  a.display();
  b.display();
  c.display();
  c.getrefcount();
  return 0;
}

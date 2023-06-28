#include<iostream>
#include<conio.h>
#include<ctime>
#include<cmath>
using namespace std;
class ssort
{
  public:
  int a[10000],n,key;
  void getdata();
  void sort();
};
void swapping(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void ssort :: getdata()
{
    cout<<"\nEnter the length of the array:";
  cin>>n;
     cout<<"\nEnter the element  array:";
     srand(time(0));
  for(int i=0;i<n;i++)
   {
     a[i]=rand()%10000;
   }
}
void ssort :: sort()
{
      int i,min_val=0,j=0,temp=0,num=0;
      for(i=0;i<n-2;i++)
      {
          min_val=i;
          for(j=i+1;j<n;j++)
          {
              num=num+1;
              if(a[j]<a[min_val])
                min_val=j;
          }
          swap(a[i], a[min_val]);
      }
      cout<<"the sorted array is "<<endl;
      cout<<"Number of times the basic operation is performed is "<<num<<endl;
      for(i=0;i<n;i++)
      {
          cout<<a[i]<<endl;
      }
}
int main()
{
 ssort ob;
 ob.getdata();
 ob.sort();
 getch();
}

#include<iostream>
using namespace std;

class search{
    public:
           int a[50],ele;
           void LinearSearch(int [],int );
           void BinarySearch(int [],int);
};

int n;
int main(){
search t;
int i,ch;
cout<<"\nEnter the number of elements :";
cin>>n;
cout<<"\nEnter "<<n<<" elements:\n";
for(i=0;i<n;i++)
    cin>>t.a[i];
cout<<"Enter the element to be searched: ";
cin>>t.ele;
cout<<"\n1.Linear search \n2.Binary search \n3.Exit";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch){
case 1 : t.LinearSearch(t.a,t.ele);
        break;
case 2 : t.BinarySearch(t.a,t.ele);
        break;
case 3: exit(0);
default: cout<<"Inavlid choice";
 }
return(0);
}

void search :: LinearSearch(int a[],int ele){
int i;
for(i=0;i<n;i++){
    if(ele == a[i]){
     cout<<"Element "<<ele<<" is found at location "<<i;
     break;
    }
}
    if(i==n)
        cout<<"Unsucessfull search";

}

void search :: BinarySearch(int a[],int ele){
    int low=0,high=n-1,loc=-1,i,j,t;

    for(i=0;i<n;i++) 
     for(j=0;j<i;j++){
         if(a[j+1]<a[j]){
             t = a[j];
             a[j]=a[j+1];
             a[j+1]=t;

}
     }

    while(low<=high){      
    int mid=(low+high)/2;
    if(ele == a[mid]){
    loc=mid;
    cout<<"Element "<<ele<<" is found at location "<<loc;
    break;
    }
    else if(ele<a[mid])
     high = mid-1;
    else
     low = mid+1;
 }

 if(loc==-1)
  cout<<"Unsuccessful Search";
}

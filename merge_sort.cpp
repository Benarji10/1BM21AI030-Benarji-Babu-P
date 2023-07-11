#include <iostream>
using namespace std;

class sort
{
public : int n, arr[10];
void merge(int * arr, int low, int mid, int high) 
{
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;
    int arrLeft[lengthLeft], arrRight[lengthRight];
    for (int a = 0; a < lengthLeft; a++) 
	{
        arrLeft[a] = arr[low + a];
    }
    for (int a = 0; a < lengthRight; a++) 
	{
        arrRight[a] = arr[mid + 1 + a];
    }
    i = 0;
    j = 0;
    k = low;
    while (i < lengthLeft && j < lengthRight) 
	{

        if (arrLeft[i] <= arrRight[j]) 
		{
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }
    while (i < lengthLeft) 
	{
        arr[k] = arrLeft[i];
        k++;
        i++;
    }
    while (j < lengthRight) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}

void mergeSort(int * arr, int low, int high) {
    int mid;
    if (low < high) {

        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
}t;

void main() {

    int i;
    cout<<"\nEnter the number of elements: ";
    cin>>t.n;
    cout<<"\nEnter those elements : ";
    for(i=0;i<t.n;i++)
        cin>>t.arr[i];
    t.mergeSort(t.arr, 0, (t.n)-1);
   cout<<"\nSorted array is :";
for(i=0;i<t.n;i++)
    cout<<t.arr[i]<<" ";
}

#include<iostream>
using namespace std;
class sort
{
int a[50],n;
public:
void read()
{
cout<<"Enter the number of elements \n";
cin>>n;
cout<<"Specify the elements\n";
for(int i=0;i<n;i++)
cin>>a[i];
}
int u=n-1,l=0,i,j;
void quicksort();
void mergesort();
void insertionsort();
void display()
{
cout<<"\nelemnts after sorting\n";
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
void choice();
};
void sort::choice()
{
cout<<"\n1.quick sort\n2.merge sort\n3.insertion sort\nenter your choice";
int ch;
cin>>ch;
switch (ch)
{
case 1: quicksort();
break;
case 2: mergesort();
break;
case 3: insertionsort();
break;
default: cout<<"\nenter the choice\n";
 choice();
}
}


 
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

void sort::quicksort()
{
 quick_sort(a,0,n-1);
}



void sort::insertionsort()
{
int i,j,temp;
for(i=1; i<n; i++)
	{
		temp=a[i];
		j=i-1;
		while((temp<a[j]) && (j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
}







void merge(int arr[], int start, int middle, int end)
{
    int i, j, k;
    int n1 = middle - start + 1;
    int n2 =  end - middle;
 
    int L[30], R[30];
 
    for (i = 0; i < n1; i++)
    L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
    R[j] = arr[middle + 1+ j];
 
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
    if (L[i] <= R[j])
    {
        arr[k] = L[i];
        i++;
    }
    else
    {
        arr[k] = R[j];
        j++;
    }
    k++;
    }
 
    while (i < n1)
    {
    arr[k] = L[i];
    i++;
    k++;
    }
 
    while (j < n2)
    {
    arr[k] = R[j];
    j++;
    k++;
    }
}
 
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
    int middle =start+(end-start)/2;
 
    mergeSort(arr, start, middle);
    mergeSort(arr, middle+1, end);
 
    merge(arr, start, middle, end);
    }
}
void sort::mergesort()
{ mergeSort(a, 0, n-1);

}

int main()
{
sort s; 
s.read();
s.choice();
s.display();
}





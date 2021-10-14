#include <stdio.h>

int linear(int arr[],int n,int elem)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==elem)
        {
            return i;
        }
        else{
            return -1;
        }
    }

}

int binary(int arr[],int n,int elem)
{
    int mid,high,low;
    low=0;
    high=n-1;
    while(low<=high){
    mid=(high+low)/2;
    if(arr[mid]==elem)
    {
        return mid;
    }
    else if(arr[mid]<elem)
    {
        low=mid+1;
    }
    else if(arr[mid]>elem)
    {
        high=mid-1;
    }
    }
}

int main()
{
    int arr[]={1,2,3,4,6,7,10};
    int size=sizeof(arr)/sizeof(int);
    int element=4;
    int ans=binary(arr,size,element);
    printf("%d",ans);
    return 0;
}

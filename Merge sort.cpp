#include<bits/stdc++.h>
using namespace std;
//@@@@@@@@@@MERGE FUNCTION TO SPLIT AND SORT AND AGAIN MERGE THE ARRAY@@@@@@@@@@@@
void merge(int a[],int l,int m,int r)
//l=left index of the subarray
//r=right index of the subarray
//m=choosen to be the mid index of the given array
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    // n1=limit of left subarray
    //n2=limit of right subarray
    // creating temporary subarrays
    int left[n1],right[n2];
    //copying data to subarray
    for(i=0;i<n1;i++)
        left[i]=a[l+i];
    for(j=0;j<n2;j++)
        right[j]=a[m+1+j];
        // MERGE BACK TO ORIGINAL ARRAY
        i=0; //index of first subarray
        j=0; //index of second subarray
        k=l; //index of merged subarray
        while(i<n1&&j<n2)
        {
            if(left[i]<=right[j])
            {
                a[k]=left[i];
                i++;
            }
            else
                {
                a[k]=right[j];
            j++;
            }
            k++;
        }
        // IF ANY ELEMENT LEFT IN LEFT SUBARRAY

        while(i<n1)
        {
            a[k]=left[i];
            i++;
            k++;
        }

// IF ANY ELEMENT LEFT IN RIGHT SUBARRAY
        while(j<n2)
        {
            a[k]=right[j];
            j++;
            k++;
            }
            }
// IMPLEMENTING MERGE TECHNIQUE AND SORTING ARRAY
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
// MAIN FUNCTION FOR PRINTING SORTED ARRAY
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    int a_size=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,a_size-1);
    cout<<"SORTED ARRAY IS"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
    return 0;
}


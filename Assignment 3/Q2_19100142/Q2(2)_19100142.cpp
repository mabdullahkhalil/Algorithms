
#include<cmath>
#include<iostream>
#include<climits>
#include <vector>

using namespace std;

int maxx(int a,int b, int c){
    int maxxx=max(a,b);
    return max(maxxx,c);
}


int sum(int* arr,int n)
{
    if(n==1)
    {
        return arr[0];
    }
    int m = n/2;
    int leftMax = sum(arr,n/2);
    int rightMax = sum(arr+(n/2),n-(n/2));
    int left_array_sum = 0, right_array_sum = 0, max_sum=0;
    int i=n/2;
    while(i < n)
    {
        max_sum += arr[i];
        right_array_sum = max(right_array_sum,max_sum);
        if (right_array_sum>max_sum) {
          //  cout<<"i "<<i<<endl;
        }
        else{
          //  cout<<"-----i "<<i<<endl;
            
        }
        i++;
    }
    max_sum = 0;
    i= ((n/2)-1);
    while(i >= 0)
    {
        max_sum += arr[i];
        left_array_sum = max(left_array_sum,max_sum);
        if (left_array_sum>max_sum) {
            //cout<<"j "<<i<<endl;
        }
        else{
            //cout<<"---j "<<i<<endl;
            
        }
        i--;
    }
    
    if (left_array_sum+right_array_sum> leftMax && left_array_sum+right_array_sum>rightMax) {
        cout<<"ijkhsgad "<<endl;
    }
    return maxx(leftMax,rightMax,left_array_sum+right_array_sum);
}


int main(int argc, char const *argv[])
{
    int n;
    cout<<"size of array input: ";cin>>n;
    
    int * arr=new int[n];
    
    for (int i=0; i<n; i++) {
        
        arr[i]=( -9+ int((2* 9+ 1)* 1.* rand()/ (RAND_MAX+ 1.)));
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    
    cout<<"the sum is: "<<sum(arr,n)<<"\n";

   
   
    return 0;
}



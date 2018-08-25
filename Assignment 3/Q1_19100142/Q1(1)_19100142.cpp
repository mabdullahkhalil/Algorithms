#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;


int min(int* array,int start,int end){
    
    if (start==end) {
        return start;
    }
    int leftindex=min(array, start, ((start+end)/2));
    int rightindex=min(array,((start+end)/2)+1,end);
    if (array[leftindex]<array[rightindex]) {
        return leftindex;
    }
    else{
        return rightindex;
        
    }
    
}


int main(){
    long n;
    cout<<"Enter size(n): ";
    cin>>n;
    
    int *newth=new int[n];
    
    for (int i=0; i<n;i++) {
        newth[i]=( -9+ int((2* 9+ 1)* 1.* rand()/ (RAND_MAX+ 1.)));
        cout<<newth[i]<<" ";
    }
    cout<<endl;
    int index=min(newth,0,n-1);
    cout<<index<<endl;
    
}



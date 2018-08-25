
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
recurrence relation:

T(0)=max{H[0],L[0]};
T(n)=max{H[n]+T(n-2), L[n]+T(n-1)}
*/
/*
part b


number of boxes to fill= n
time to fill each box= O(1)
time complexity= O(n)

*/




vector<int> one;
vector<int> two;

int checkk(int n,vector<int>* maxx,vector<int>* max1){
    int a=0,b=0;
    if (n<=0) {
        return maxx->at(0);
    }
    try {
        maxx->at(n);  }   // vector::at throws an out-of-range
    catch (const std::out_of_range& oor) {
        a=one[n]+checkk(n-2,maxx,max1);
        b=two[n]+checkk(n-1,maxx,max1);
        maxx->push_back(max(a,b));
        if (a>b) {
            max1->push_back(n-2);
        }
        else{
            max1->push_back(n-1);

        }
    }
 
    return maxx->at(n);

}


int main(){

    ifstream myfile ("input.txt");
    string onee,twoo,three;
    getline(myfile, onee);
    getline(myfile, onee);
    
    
    istringstream ss(onee);
    string token;
    while(getline(ss, token, ':')) {
        one.push_back(stoi(token));

    }
    
    getline(myfile, twoo);
    
    
   istringstream so(twoo);
    while(getline(so, token, ':')) {
        two.push_back(stoi(token));
    }

    vector<int> maxx;
    vector<int> max1;

    maxx.push_back(max(one[0],two[0]));
  
    max1.push_back(0);
    
    cout<<"the maximum sum is: "<<checkk(one.size()-1,&maxx,&max1)<< endl;
    
    max1.erase(unique (max1.begin(), max1.end()),max1.end());
    max1.push_back(one.size()-1);



cout<<"index : ";
    for (int i=0; i<max1.size(); i++) {
        cout<<max1[i]<<" ";
    }
    cout<<endl;
    cout<<"chosen: ";

    for (int i=max1.size(); i>0 ; i--) {
        if (max1[i]==max1[i-1]+1) {
            cout<<"L ";
        }
        else{
            cout<<"H ";
        }
    }
    cout<<endl;
    
}

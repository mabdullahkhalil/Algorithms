#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include "sorts.cpp"

using namespace std;

vector<long> GenerateRandom(long n,long d);


//=====================================================================================

int main()
{

	struct timeval start, end, diff;

	string str; string str1; string str2;
	long n;

	vector<long> num;

	cout<<"Enter total number of files: ";
	cin>>n;


long d;
cout<<"enter randomizer: "; cin>>d;
		num = GenerateRandom(n,d);

	
// to display the created vector

	cout<<"File sizes:"<<endl;
	for(int i=0; i<num.size(); i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl<<endl;

//=====================================================================================

int size_of_usb;

cout<<"what is the size of usb? ";
cin>>size_of_usb;

num = HeapSort(num);

    long count=0;
    int i=0;
    while (count+num[i]<size_of_usb && (i<num.size())){
    	count+=num[i];
    	i++;
    }
    cout<<"files sizes added :";
    for (int j = 0; j < i; ++j)
    {
    	/* code */
    	cout<<num[j]<<" ";

    }
    cout<<endl;

    cout<<i-1<<" of the "<<num.size()<<" files were added to the usb of size "<<size_of_usb<<"."<<endl;
}

//=====================================================================================
//Vector Generation Functions

vector<long> GenerateRandom(long d, long n)
{
    vector<long> nums;
    long k, residue;
    for (k = 0; k < d; k++)
    {
        residue = (long) (((long long)k * (long long) n) % d);
        if (residue==0)
        {
        	nums.push_back((rand() % 100 + 1));
        }
        else{
        nums.push_back(residue);}
    }
    return nums;
}




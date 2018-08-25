#include <iostream>
#include <string>
#include <fstream>

/*
recurrence relation

for all the rows j:
for all the columns i:
if i==0 and (third[0+j-1]==two[j]):
	B[0][j]=B[0][j-1]

if j==0 and (third[0+i-1]==one[i]):
	B[j][0]=B[j-1][0]

if (three[i+j-1]==one[i]):
	boolcheck[i][j]=boolcheck[i-1][j]

if(three[i+j-1 ]==two[j]):
	boolcheck[i][j]=boolcheck[i][j-1]

*/
/*
part b

number of boxes to fill=(size of string 1 * size of string two +2)
time to fill each box=O(1)
time compelxity=(size of string 1 * size of string two +2)

*/


using namespace std;

bool populate(string one, string two, string three){
	bool** boolcheck=new bool* [one.size()];
	for (int i = 0; i < one.size(); ++i)
	{
		boolcheck[i]=new bool[two.size()];
		for (int j = 0; j < two.size(); ++j)
		{
			boolcheck[i][j]=false;
		}
	}

	boolcheck[0][0]=true;

	for (int j = 1; j < two.size(); ++j)
	{
		if (three[0+j-1]==two[j])
		{
			boolcheck[0][j]=boolcheck[0][j-1];
		}
		// cout<<boolcheck[0][j]<<" ";
	}

	// cout<<endl;


	for (int j = 1; j < one.size(); ++j)
	{
		if (one[j]==three[0+j-1])
		{
			boolcheck[j][0]=boolcheck[j-1][0];
		}
		// cout<<boolcheck[j][0]<<" ";
	}

	// cout<<endl;


for (int i = 1; i < one.size(); ++i)
{
	for (int j = 1; j < two.size(); ++j)
	{

		if (three[i+j-1]==one[i])
		{
			boolcheck[i][j]=boolcheck[i-1][j];
		}
		else if(three[i+j-1 ]==two[j]){
			boolcheck[i][j]=boolcheck[i][j-1];

		}
	}
}


	// for (int i = 0; i < one.size(); ++i)
	// {
	// 	for (int j = 0; j < two.size(); ++j)
	// 	{
	// 		cout<<boolcheck[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }


	

	return boolcheck[one.size()-1][two.size()-1];
}

void checkk(string one, string two, string three){

	bool c=populate("0"+one,"0"+two,three);
	if (c)
	{
		cout<<"'"<<three<<"' is interleaving of '"<<one<<"' and '"<<two<<"'"<<endl;
	}
	else{
		cout<<"'"<<three<<"' is not interleaving of '"<<one<<"' and '"<<two<<"'"<<endl;
	}
}

int main(){

    ifstream myfile ("input.txt");
    string one,two,three;
    getline(myfile, one);
    getline(myfile, two);
    getline(myfile, three);

	checkk(one,two,three);


	myfile.close();

}
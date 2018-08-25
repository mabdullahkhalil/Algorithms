#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
Recurrence Relation
T[0,graph]=distance[0]
T[n,graph]=distance[n]+max(T[parents[n][0],graph], T[parents[n][1],graph],...,T[parents[n][i],graph]);
*/
/*
part b:

number of boxes fileed to store the partial results = n*m;
time to fill one box= O(1)
total time complexity=O(m*n)


*/




int cities;
bool* indexx=new bool[cities];
int* distances=new int[cities];
vector< vector<int> > parents;
vector<int> parentt;

int func(int n,int** graph){

    if (n==0)
    {
        return distances[0];
        
    }
    else if(distances[n]!=0)
    {
        return distances[n];
    }
    
    distances[n]=func(parents[n][0],graph)+graph[parents[n][0]][n];
    int pare=parents[n][0];
    for (int i=1; i<parents[n].size(); i++) {
        if (func(parents[n][i],graph)+graph[parents[n][i]][n] > distances[n]) {
            distances[n]= func(parents[n][i],graph)+graph[parents[n][i]][n];
            pare=parents[n][i];
        }
    }
            cout<<"this"<<endl;

    parentt.push_back(pare);
    return distances[n];
}




int main() {

    ifstream myfile ("Input2.txt");
    string line;
    string string_distribution[2];
    getline(myfile, line);
    istringstream string_extraction(line);
    
    getline(string_extraction, string_distribution[0], ' ');
    getline(string_extraction, string_distribution[1]);
    cities=stoi(string_distribution[1]);
    int* total=new int[cities];
    
    int** graph = new int*[cities];
    int** array = new int*[cities];
    for(int i = 0; i < cities; ++i){
        graph[i] = new int[cities];
        for (int j=0; j<cities; j++) {
            graph[i][j]=0;
        }
        total[i]=0;
    }

    
    
    
    
    int i=0;
    
    if (myfile.is_open() ) {
        
        while(getline(myfile, line) && i<cities) {
            
            istringstream string_extraction(line);
            
            getline(string_extraction, string_distribution[0], ':');
            getline(string_extraction, string_distribution[1]);
            total[i]=stoi(string_distribution[0]);
            
            istringstream ss(string_distribution[1]);
            string token[2];
            string ext;
            
            while(getline(ss, ext, ',')) {
                istringstream ext1(ext);
                getline(ext1, token[0], ';');
                getline(ext1, token[1]);
                graph[stoi(string_distribution[0])][stoi(token[0])]=stoi(token[1]);
            }
            i++;
        }
        myfile.close();
        
        for (int i = 0; i < cities; ++i)
        {
            vector<int> v;
            parents.push_back(v);
        }
        

        indexx[0]=true;
        distances[0]=0;
        for (int i = 1; i < cities; ++i)
        {
            distances[i]=0;
            indexx[i]=false;
        }
        
        for (int i = 1; i < cities; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (graph[j][i]!=0)
                {
                    indexx[i]=true;
                }
            }
        }
        
        
        
        for (int i = 0; i < cities; ++i)
        {
            if (indexx[i]==false)
            {
                for (int j = 0; j < cities; ++j)
                {
                    graph[i][j]=0;
                }
            }
        }
        //  cout<<"********** Adjacency Matrix *********"<<endl;
        for (int m=0; m<cities; m++) {
            for (int n=0;n<cities ; n++) {
                if (graph[m][n]!=0) {
                    parents[n].push_back(m);
                }
            }
            
        }
        
        
        
        

        
        
    }

    func(cities-1,graph);
    
//    for (int i=0; i<cities; i++) {
//        if (parent[i]!=-1) {
//            cout<<parent[i]<<endl;
//        }
//    }
    
    
    
    parentt.erase( unique(parentt.begin(),parentt.end() ), parentt.end() );
    for (int i=0; i<parentt.size(); i++) {
        cout<<parentt[i]<<" -> ";
    }
    cout<<cities-1<<endl;
    
    cout<<"cost of the tolls: "<<distances[cities-1]<<endl;
    
}



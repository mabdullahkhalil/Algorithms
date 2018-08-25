#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

int cities;

int Dijkstra(int** graph, int src,int dest)
{
    int weight[cities][cities];
    int distance[cities], parent[cities], isvisited[cities];
    
    for (int i=0; i<cities;i++) {
        distance[i]=0;
        parent[i]=0;
        isvisited[i]=0;
    }


    int i=0,j=0;
    while (i<cities){
        j=0;
        while(j<cities) {
            if (graph[i][j]==0){
                weight[i][j]=99999;
            }
            else{
                weight[i][j]=graph[i][j];
            }
            j++;
        }
        i++;
    }
    int ii=0;
    while (ii<cities) {
        distance[ii]=weight[src][ii];
        parent[ii]=src;
        isvisited[ii]=0;
        ii++;
    }
    distance[src]=0;
    isvisited[src]=1;
   int count=1;
    int next;
    while (count<cities-1) {
        int dist=99999;
        i=0;
        while (i<cities) {
            if (distance[i]<dist && !isvisited[i]) {
                dist=distance[i];
                next=i;
            }
            i++;
        }
            isvisited[next]=1;
        i=0;
        while (i<cities) {
            if (!isvisited[i]) {
                if (dist+weight[next][i]<distance[i]) {
                    distance[i]=dist+weight[next][i];
                    parent[i]=next;
                }
            }
            i++;
        }
        count++;
    }

    return distance[dest];

}

int main() {
    
    ifstream myfile ("input.txt");
    string line;
    string string_distribution[2];
    getline(myfile, line);
    istringstream string_extraction(line);
    
    getline(string_extraction, string_distribution[0], ' ');
    getline(string_extraction, string_distribution[1]);
    cities=stoi(string_distribution[1]);
    int* total=new int[cities];
    
    int** array = new int*[cities];
    for(int i = 0; i < cities; ++i){
        array[i] = new int[cities];
        for (int j=0; j<cities; j++) {
            array[i][j]=0;
        }
        total[i]=0;
    }
    
    
    int** graph = new int*[cities];
    for(int i = 0; i < cities; ++i){
        graph[i] = new int[cities];
        for (int j=0; j<cities; j++) {
            graph[i][j]=0;
        }
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
                array[stoi(string_distribution[0])][stoi(token[0])]=stoi(token[1]);
            }
            i++;
        }
        myfile.close();
        
        //  cout<<"********** Adjacency Matrix *********"<<endl;
        for (int m=0; m<cities; m++) {
            for (int n=0;n<cities ; n++) {
                if (array[m][n]!=0) {
                    graph[m][n]=array[m][n];
                    cout<<graph[m][n]<<" ";
                }
                else{
                    graph[m][n]=0;
                    cout<<graph[m][n]<<" ";
                }
            }
            cout<<endl;
            
        }
        int srcc,destt,altcity;
        cout<<"src  city :";cin>>srcc;
        cout<<"dest city :"; cin>>destt;
        cout<<"alte city :";cin>>altcity;
        
        int smallest=(Dijkstra(graph,0,destt));
        int d1=(Dijkstra(graph,0,altcity));
       int d2=(Dijkstra(graph,altcity,destt));
        cout<<"Cost of smallest path from "<<srcc<<" -> "<<destt<<" : "<<smallest<<endl;
        if (d1+d2 > 99999) {
            cout<<"no such path exists"<<endl;
            return 0;
        }
        
        float check=(float)(smallest-d1-d2)/(float)(smallest);
        if ((abs(check) * 100) <20.0) {
            cout<<"the path through "<<srcc<<" -> "<<altcity<<" -> "<<destt<<" is possible."<<endl;
        }
        else{
            cout<<"the alternate path is longer"<<endl;
        }
        
        
        // 0,2,4
        
//        cout
        return 0;
        
        
    }
    
    
    
    
    
    
}


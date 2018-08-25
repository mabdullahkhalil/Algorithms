//
//  main.cpp
//  assignment 1
//
//  Created by Apple PC on 21/10/2017.
//  Copyright © 2017 Apple PC. All rights reserved.
//

/*
 a queue is created in the start which includes the source node for BFS.
 a while loop runs till the last vertex in the queue.
 deques and check for the cycle.
 finds non-colored neighbours.
 if the edge exists and destination is not colored then the destination is given the opposite color.
 if the opposite happens then return false.
 and in case all are visited and oppositely colored, return TTRUE.
 then it prints the different colored chemicals.
 an adjacency matrix was used in the code to store all the endes and nodes.
 
 Time Complexity: O(n+m) due to bfs running.
 Space Complexity: O(n^2) due to adjacency matrix
 
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int number_of_chemicals;

bool isBipartite(int** graph, int src)
{

    int storing_color[number_of_chemicals];
        int i=0;
    while (i<number_of_chemicals) {
        storing_color[i]=-1;
        i++;
    }
    
    storing_color[src] = 1;
    
    queue <int> q;
    q.push(src);
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        if (graph[u][u] == 1)
            return false;
        
        int v=0;
        while (v < number_of_chemicals)
        {
            if (graph[u][v] && storing_color[v] == -1)
            {
                storing_color[v] = 1 - storing_color[u];
                q.push(v);
            }

            else if (graph[u][v] && storing_color[v] == storing_color[u])
                return false;
            
            v++;
        }
    }
    
    cout<<"it is possible to safely pack these chemicals in two boxes "<<endl;
    cout<<"The chemicals going in box 1 are :"<<endl;
    int count=0;
    for (int i=0; i<number_of_chemicals; i++) {
        if (storing_color[i]==1) {
            cout<<++count<<". "<<i<<endl;
        }
    }
    cout<<"The chemicals going in box 2 are :"<<endl;
    count=0;
    for (int i=0; i<number_of_chemicals; i++) {
        if (storing_color[i]==0) {
            cout<<++count<<". "<<i<<endl;
        }
    }
    
    return true;
}


int main() {
    
    ifstream myfile ("chemicals2.txt");
    string line;
    string string_distribution[2];
    getline(myfile, line);
    istringstream string_extraction(line);
    
    getline(string_extraction, string_distribution[0], ' ');
    getline(string_extraction, string_distribution[1]);
    number_of_chemicals=stoi(string_distribution[1]);
    int* total=new int[number_of_chemicals];
    
    int** array = new int*[number_of_chemicals];
    for(int i = 0; i < number_of_chemicals; ++i)
        array[i] = new int[number_of_chemicals];
    
    
    int** graph = new int*[number_of_chemicals];
    for(int i = 0; i < number_of_chemicals; ++i)
        graph[i] = new int[number_of_chemicals];
    
    
    

    int i=0;

    if (myfile.is_open() ) {
 
        while(getline(myfile, line) && i<number_of_chemicals) {
           
                istringstream string_extraction(line);
                
                getline(string_extraction, string_distribution[0], ':');
                getline(string_extraction, string_distribution[1]);
            total[i]=stoi(string_distribution[0]);
            
                istringstream ss(string_distribution[1]);
                string token;
                int j=0;
                
                while(getline(ss, token, ',')) {
                    array[i][j]=stoi(token);
                    j++;
            }
            i++;
        }
        myfile.close();
        
      //  cout<<"********** Adjacency Matrix *********"<<endl;
        for (int m=0; m<i; m++) {
            int x=0;
            for (int n=0;n<i ; n++) {
                if (array[total[m]][x]==n) {
                    graph[total[m]][n]=1;
                    //cout<<graph[total[m]][n]<<" ";
                    x++;
                }
                else{
                    graph[total[m]][n]=0;
                    //cout<<graph[total[m]][n]<<" ";
                }
                
            }
            cout<<endl;
            
        }        
        if(!isBipartite(graph,0)){
            cout<<"it is not possible to safely pack these chemicals in two boxes "<<endl;
        }
        return 0;
        
        
    }

    
    
    
    
    
}

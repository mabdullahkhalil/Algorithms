//
//  main.cpp
//  Q2_19100142
//
//  Created by Apple PC on 22/10/2017.
//  Copyright © 2017 Apple PC. All rights reserved.
//
/*
 find the indgree of all the vertices.
 start with the one who has indegree=0.
 add it to the queue.
 add it to the topological sort array and check it's neighbiurs if any one has indegree zero and then add it to the queue too.
 it's kind of recursive using th while loop.
 
 Time COmplexity: O(N+m) i.e total edges nad vertices.
 Space complexity: O(n^2) due to the adjacency martrix.
 
 
 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int number_of_chemicals;
int frontqueue=-1;
int backqueue=-1;


int indegree(int** adj_matrix,int vertex){
    int count=0, total_indegree = 0;
    
    while (count<number_of_chemicals) {
        if (adj_matrix[count][vertex]==1) {
            total_indegree++;
        }
        count++;
    }
    return total_indegree;
}

void addtoqueue(int*qu,int vertex){
    if (backqueue != number_of_chemicals-1) {
        if (frontqueue==-1) {
            frontqueue=0;
        }
        backqueue++;
       qu[backqueue]=vertex;
    }

    //return *queue;
}


int empty(){
    if(frontqueue == -1 || frontqueue > backqueue)
    {
        return 1;
    }
    return 0;
}


int pop(int*qu){
   
        int new_ver;
        if(frontqueue != -1 || frontqueue < backqueue)
        {
            new_ver=qu[frontqueue];
            frontqueue++;
            return new_ver;
        
        
            
        }
    exit(1);
    
}



int main() {
    
    ifstream myfile ("chemicals.txt");
    string line;
    string UserN[2];
    getline(myfile, line);
    istringstream tokenizer(line);
    
    getline(tokenizer, UserN[0], ' ');
    getline(tokenizer, UserN[1]);
    number_of_chemicals=stoi(UserN[1]);
    int* total=new int[number_of_chemicals];
    
    int** array = new int*[number_of_chemicals];
    for(int i = 0; i < number_of_chemicals; ++i)
        array[i] = new int[number_of_chemicals];
    
    
    int** adj_matrix = new int*[number_of_chemicals];
    for(int i = 0; i < number_of_chemicals; ++i)
        adj_matrix[i] = new int[number_of_chemicals];
    
    int i=0;
    if (myfile.is_open() ) {
        while(getline(myfile, line) && i<number_of_chemicals) {
            istringstream tokenizer(line);
            getline(tokenizer, UserN[0], ':');
            getline(tokenizer, UserN[1]);
            total[i]=stoi(UserN[0]);
            istringstream ss(UserN[1]);
            string token;
            int j=0;

            if (UserN[1].empty()) {
                array[i][j]=-1;
            }
            
            while(getline(ss, token, ',')) {
                if (!UserN[1].empty()) {
                    array[i][j]=stoi(token);
                }
                else {
                    array[i][j]=-1;
                }
                j++;
            }
            i++;
            
            
        }
        myfile.close();
        
        for (int m=0; m<i; m++) {
            int x=0;
            for (int n=0;n<i ; n++) {

                if (array[total[m]][x]==n ){
 
                 //   cout<<"array[total[m]][x]"<<array[total[m]][x]<<endl;
                        adj_matrix[total[m]][n]=1;
                        cout<<adj_matrix[total[m]][n]<<" ";
                        x++;
                    
                    
                }
                else{
                    adj_matrix[total[m]][n]=0;
                    cout<<adj_matrix[total[m]][n]<<" ";
                }
            }
            cout<<endl;
        }
    }
    
    int* indegrees=new int[number_of_chemicals];
    int*qu=new int[number_of_chemicals];
    int* topological=new int[number_of_chemicals];
    i=0;
    
   queue<int> main_queue;
    while (i<number_of_chemicals) {
        indegrees[i]=indegree(adj_matrix,i);
        if (indegrees[i]==0) {
            main_queue.push(i);
        }
        
        i++;
    }
    
    int count=0;
    while(!main_queue.empty() && count < number_of_chemicals)
    {
        int node=main_queue.front();
        main_queue.pop();
        topological[++count] = node;
        int i=0;
        while (i<number_of_chemicals) {
            
            if(adj_matrix[node][i] == 1)
            {
                adj_matrix[node][i] = 0;
                indegrees[i] = indegrees[i] - 1;
                if(indegrees[i] == 0)
                {
                    main_queue.push(i);
                }
            }
            i++;
        }
//        count++;
    }
    
    if(count < number_of_chemicals)
    {
        cout<<"Graph is Cyclic. Therefore, Topological Ordering Not Possible\n";
    }
    cout<<"ordet in which the leader would walk:"<<endl;
    for(i = 1; i <= count; i++)
    {
        cout<<(topological[i])<<" ";
    }
    cout<<endl;
    return 0;
    
    
    
}

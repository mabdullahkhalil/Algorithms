#include<stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include<stdlib.h>
#include <vector>

using namespace std;
int i,j,k,a,b,u,v, tracks,ne=1;
int minimum=0,mincost=0;
int find(int i,int* predec);
int uni(int i,int j,int* predec);

int main()
{
    int *predec=new int[tracks];
    ifstream myfile ("input.txt");
    string line;
    string string_distribution[2];
    getline(myfile, line);
    istringstream string_extraction(line);
    
    getline(string_extraction, string_distribution[0], ' ');
    getline(string_extraction, string_distribution[1]);
    tracks=stoi(string_distribution[1]);
    int* total=new int[tracks];
    
    int** array = new int*[tracks];
    for(int i = 0; i < tracks; ++i){
        array[i] = new int[tracks];
        for (int j=0; j<tracks; j++) {
            array[i][j]=0;
        }
        total[i]=0;
        predec[i]=0;
    }
    
    
    int** graph = new int*[tracks];
    int** cost=new int*[tracks];
    
    for(int i = 0; i < tracks; ++i){
        graph[i] = new int[tracks];
        
        for (int j=0; j<tracks; j++) {
            graph[i][j]=0;
        }
    }
    cost=graph;
    
    
    
    int i=0;
    
    if (myfile.is_open() ) {
        
        while(getline(myfile, line) && i<tracks) {
            
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
        for (int m=0; m<tracks; m++) {
            for (int n=0;n<tracks ; n++) {
                if (array[m][n]!=0) {
                    graph[m][n]=array[m][n];
                    cost[m][n]=array[m][n];
                    cout<<graph[m][n]<<" ";
                }
                else{
                    graph[m][n]=0;
                    cout<<graph[m][n]<<" ";
                    cost[m][n]=0;
                }
            }
            cout<<endl;
            
        }
        int n=tracks;
        int minimum;
        printf("The edges of Minimum Cost Spanning Tree are\n");
        vector<pair<int, int>> pairs;
        vector<int> weight;
        
        while(ne < n)
        {
            int minimum=999;
            for(i=0;i<n;i++)
            {
                //   minimum=999;
                for(j=0;j < n;j++)
                {
                    if(cost[i][j] < minimum && cost[i][j]!=999 && cost[i][j]>0)
                    {
                        minimum=graph[i][j];
                        a=i;
                        u=i;
                        b=j;
                        v=j;
                    }
                }
            }
            u=find(u,predec);
            v=find(v,predec);
            if(uni(u,v,predec))
            {
                ne++;
                pairs.push_back(make_pair(a, b));
                weight.push_back(minimum);
                mincost +=minimum;
            }
            cost[a][b]=cost[b][a]=999;
        }
        
        for (int i=0; i<weight.size(); i++) {
            printf("%d edge (%d,%d) =%d\n",i+1,pairs[i].first,pairs[i].second,weight[i]);
            
        }
        
        int source,desti,wee;
        //        cout<<"we are going to add a track"<<endl;
        //        cout<<"from: ";cin>>source;
        //        cout<<"to  : ";cin>>desti;
        //
        
        int* isvisited=new int[tracks];
        int *parent1=new int[tracks];
        for (int i=0; i<tracks; i++) {
            isvisited[i]=0;
            parent1[i]=999999;
        }
        int check=pairs[0].first;
        for (int i=0; i<pairs.size(); i++) {
            if (isvisited[pairs[i].first]==0) {
                isvisited[pairs[i].first]=1;
            }
            if (isvisited[pairs[i].second]==0) {
                isvisited[pairs[i].second]=1;
            }
            if (isvisited[pairs[i].second]==1 && parent1[pairs[i].second]==999999 && pairs[i].second!=check) {
                parent1[pairs[i].second]=pairs[i].first;
            }
            else if (isvisited[pairs[i].first]==1 && parent1[pairs[i].first]==999999) {
                parent1[pairs[i].first]=pairs[i].second;
                
            }
            
        }

        
        cout<<"we are going to add a track"<<endl;
        cout<<"from   : ";cin>>source;
        cout<<"to     : ";cin>>desti;
        cout<<"weight :";cin>>wee;
        
        int w1=0,w2=0;
        
        for (int i=0; i<pairs.size(); i++) {
//            cout<<pairs[i].second<<endl;
//            cout<<parent1[pairs[i].second]<<endl;
//            cout<<pairs[i].first<<endl;
//            cout<<parent1[pairs[i].first]<<endl;
            
            if ((pairs[i].second==source && parent1[pairs[i].second]==pairs[i].first)|| (pairs[i].first==source && parent1[pairs[i].first]==pairs[i].second)) {
                  w1=weight[i];
            }
            if ((pairs[i].second==desti && parent1[pairs[i].second]==pairs[i].first)|| (pairs[i].first==desti && parent1[pairs[i].first]==pairs[i].second)) {
                w2=weight[2];
            }
        }
        
        if (wee<w1 && w1<=w2) {
            printf("edge (%d,%d) =%d\n",source,desti,wee);
            for (int i=0; i<weight.size(); i++) {
//                            cout<<pairs[i].second<<endl;
//                            cout<<parent1[pairs[i].second]<<endl;
//                            cout<<pairs[i].first<<endl;
//                            cout<<parent1[pairs[i].first]<<endl;
                if ((pairs[i].second!=source && parent1[pairs[i].second]==pairs[i].first)|| (pairs[i].first!=source && parent1[pairs[i].first]==pairs[i].second)) {
                    printf("edge (%d,%d) =%d\n",pairs[i].first,pairs[i].second,weight[i]);
                }
            }
        }
        if (wee<w2 && w2<w1) {
            printf("edge (%d,%d) =%d\n",source,desti,wee);
            for (int i=0; i<weight.size(); i++) {
                if ((pairs[i].second!=desti && parent1[pairs[i].second]==pairs[i].first)|| (pairs[i].first!=desti && parent1[pairs[i].first]==pairs[i].second)) {
                    printf("edge (%d,%d) =%d\n",pairs[i].first,pairs[i].second,weight[i]);
                }
            }
        }
    }
}
int find(int i,int* predec)
{
    while(predec[i]!=0)
        i=predec[i];
    return i;
}
int uni(int i,int j,int* predec)
{
    if(i!=j)
    {
        predec[j]=i;
        return 1;
    }
    return 0;
}


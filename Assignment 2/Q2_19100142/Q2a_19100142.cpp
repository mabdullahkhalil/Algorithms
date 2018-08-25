
//
//  main.cpp
//  Q2_19100142
//
//  Created by Muhammad Abdullah Khalil on 12/11/2017.
//  Copyright © 2017 Muhammad Abdullah Khalil. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;


int main() {
    vector<string> train_time,operators;
    ifstream myfile ("input2.txt");
    string line;
    string string_distribution[2];
    getline(myfile, line);
    istringstream string_extraction(line);
    
    if (line=="Trains") {
        getline(myfile, line);
        while (line!="Operators") {
            istringstream ss(line);
            string token;
            while(getline(ss, token, ',')) {
//                cout<<token<<endl;
                train_time.push_back(token);
            }
            getline(myfile, line);
        }
    }
    getline(myfile, line);
    while (line.size()!=0) {
        istringstream ss(line);
        string token;
        while(getline(ss, token, ',')) {
//            cout<<token<<endl;
            operators.push_back(token);
        }
        getline(myfile, line);
    }
    
    
    
    
    //    string train_time[train_time.size()]={"9:00 AM"," 9:10 AM"," 9:17 AM"," 9:34 AM"," 9:43 AM"," 9:56 AM","10:20 AM","11:50 AM","12:05 PM","12:23 PM","5:00 PM","5:45 PM","6:20 PM","6:30 PM","6:44 PM","10:15 PM"};
    vector<int> train_secs;
    for (int i=0; i<train_time.size(); i++) {
        istringstream ss(train_time[i]);
        string token[3];
        getline(ss, token[0], ':');
        getline(ss, token[1],' ');
        getline(ss, token[2]);
        int hour=stoi(token[0]);
        int min=stoi(token[1]);
        //        cout<<hour<<":"<<min<<endl;
        if (token[2]=="AM" || hour==12) {
            train_secs.push_back((hour*60*60)+(min*60));
//            cout<<train_secs[i]<<endl;;
        }
        else{
            train_secs.push_back(((hour+12)*60*60)+(min*60));
//            cout<<train_secs[i]<<endl;;
        }
    }
    
    //    string operators[operators.size()]={"8:00 AM-9:00 AM","8:20 AM-9:20 AM","8:30 AM-9:30 AM","9:30 AM-10:30 AM","10:30 AM-11:30 AM","11:15 AM-12:15 PM","12:15 PM-1:15 PM","1:10 PM-2:10 PM","2:00 PM-3:00 PM","2:45 PM-3:45 PM","3:30 PM-4:30 PM","4:30 PM-5:30 PM","5:15 PM-6:15 PM","6:00 PM-7:00 PM","6:30 PM-7:30 PM","7:00 PM-8:00 PM","7:45 PM-8:45 PM","8:30 PM-9:30 PM","9:30 PM-10:30 PM","10:20 PM-11:20 PM","10:45 PM-11:45 PM"};
    //
    vector<int> operator_start;
    vector<int> operator_end;
    
    for (int i=0; i<operators.size(); i++) {
        istringstream ss(operators[i]);
        string token[6];
        getline(ss, token[0], ':');
        getline(ss, token[1],' ');
        getline(ss, token[2],'-');
        getline(ss, token[3], ':');
        getline(ss, token[4],' ');
        getline(ss, token[5]);
        int hour=stoi(token[0]);
        int min=stoi(token[1]);
        if (token[2]=="AM" || hour==12) {
            operator_start.push_back((hour*60*60)+(min*60));
        }
        else{
            operator_start.push_back(((hour+12)*60*60)+(min*60));
        }
        hour=stoi(token[3]);
        min=stoi(token[4]);
//        cout<<hour<<":"<<min<<endl;
        if (token[5]=="AM" || hour==12) {
            operator_end.push_back((hour*60*60)+(min*60));
        }
        else{
            operator_end.push_back(((hour+12)*60*60)+(min*60));
        }
    }
    int* operatorcount=new int[operators.size()];
    for (int i=0; i<operators.size(); i++) {
        operatorcount[i]=0;
    }
    
    
    int count=0,check=0;
    printf("Train # | Arrival | Operator | Op_Time \n");

    while (check<operator_end.size()-1) {
        if (train_secs[count]>=operator_start[check] && train_secs[count]<=operator_start[check+1] && train_secs[count]<operator_end[check]) {
            operatorcount[check]+=1;
            printf("    %d   | %s |     %d    | %s \n",count+1,train_time[count].c_str(),check,operators[check].c_str());
//            cout<<"train "<<count+1<<" that came at "<<train_time[count]<<" was handled by operator "<<check<<" working at "<<operators[check]<<endl;
            count++;
            check--;
        }
        check++;
    }
    int c=0;
    for (int i=0; i<operators.size(); i++) {
        if (operatorcount[i]) {
            
            cout<<"Operator "<<i<<" handled "<<operatorcount[i]<<" trains."<<endl;c++;
        }
    }
    cout<<c<<"/"<<operator_end.size()<<" operators were needed"<<endl;
    
    
    
}


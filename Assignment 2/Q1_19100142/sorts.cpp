#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "list.cpp"
#include <math.h>

//=======================this done==============================================================
vector<long> InsertionSort(vector<long> nums)
{
    long array[nums.size()];
    cout<<"size "<<nums.size()<<endl;
    for (int i = 0; i < nums.size(); ++i)
    {
        array[i]=nums[i];
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        int j=i;
        while (j>0 && array[j]<array[j-1]){
            int temp = array[j];
            array[j]=array[j-1];
            array[j-1]=temp;
            j--;
        }
    }
    vector<long> sending;
    for (int i = 0; i < nums.size(); ++i)
    {
        sending.push_back(array[i]);
    }
    return sending;
    
}

//======================this done===============================================================
vector<long> MergeSort(vector<long> nums)
{
    List<long>* mainLL=new List<long>;
    for (int i = 0; i < nums.size(); i++)
    {
        mainLL->insertAtTail(nums[i]);
    }
    
   List<long>* sending= Msort(mainLL,nums.size());
    ListItem<long>* send=sending->getHead();
    vector<long> x;
    while (send!=NULL) {
        x.push_back(send->value);
        send=send->next;
    }
    return x;
    
}

List<long>* Msort(List<long>* mainLL,int size){
    if (floor(size/2)==0) {
        return mainLL;
    }
    List<long>* arrayLeft=new List<long>;
    List<long>* arrayRight=new List<long>;
    split_list(mainLL, arrayLeft, arrayRight, size);
    arrayLeft=Msort(arrayLeft, floor(size/2));
    arrayRight=Msort(arrayRight, size-floor(size/2));
    List<long>* last=mergeList(arrayLeft, arrayRight);
    return last;
}

void split_list(List<long>* linkedlist, List<long>* leftList, List<long>* rightList,int count){
    ListItem<long>* main=linkedlist->getHead();
    for (int i=0; i<(floor(count/2)); i++) {
        leftList->insertAtHead(main->value);
        main=main->next;
    }
    for (int i=0; i<(count- (floor(count/2))); i++) {
        rightList->insertAtHead(main->value);
    main=main->next;
    }
}

List<long>* mergeList(List<long>* leftList, List<long>* rightList){
    ListItem<long>* one=leftList->getHead();
    ListItem<long>* two=rightList->getHead();
    List<long>* three=new List<long>;
    for (int i=0; i<(leftList->length()+rightList->length()); i++) {

        if (one->value > two->value) {
            three->insertAtTail(two->value);
            two=two->next;
            if (two==NULL) {
                while (one!=NULL) {
                    three->insertAtTail(one->value);
                    one=one->next;
                }
                i=(leftList->length()+rightList->length());

            }
        }
        else if (one->value < two->value) {
            three->insertAtTail(one->value);
            one=one->next;
            if (one==NULL) {
                while (two!=NULL) {
                    three->insertAtTail(two->value);
                    two=two->next;
                }
                i=(leftList->length()+rightList->length());

            }
        }
    }
    return three;
}

//===========================this done==========================================================
vector<long> QuickSortArray(vector<long> nums)
{
    long* array=new long[nums.size()];
    for (int i=0; i<nums.size(); i++) {
        array[i]=nums[i];
    }
    int typeofsort;
    cout<<"Enter the pivot you want to make:"<<endl;
    cout<<"1.use the first element of the array as the pivot"<<endl;
    cout<<"2.use the median-of-three pivot"<<endl;
    cout<<"3.use the last element of the array as pivot"<<endl;
    cin>>typeofsort;
    
            if (typeofsort==1) {
                swap(array[0], array[nums.size()-1]);
            }
            else if(typeofsort==2){
                int mid=nums.size()/2;
                long x=array[0]+array[mid]+array[nums.size()-1]-maxi(array[0],array[mid],array[nums.size()-1])-mini(array[0],array[mid],array[nums.size()-1]);
                if (x==array[0]) {
                    swap(array[0], array[nums.size()-1]);
                }
                else if (x==array[mid]) {
                    swap(array[mid], array[nums.size()-1]);
                }
                else if (x==array[nums.size()-1]) {
                    swap(array[nums.size()-1], array[nums.size()-1]);
                }
            }
    
    Qsort(array, 0, nums.size()-1);
    
    vector<long> sending;
    for (int i=0; i<nums.size(); i++) {
        sending.push_back(array[i]);
    }
    return sending;
}

int maxi(long a, long b, long c){
    int max=a;
    if (b>max) {
        max=b;
    }
    if (c>max) {
        max=c;
    }
    return max;
}

int mini(long a, long b, long c){
    int min=a;
    if (b<min) {
        min=b;
    }
    if (c<min) {
        min=c;
    }
    return min;
}

void Qsort(long* array,int start_index, int end_index){
    if (start_index<end_index) {
        long cindex=split(array, start_index, end_index);
        Qsort(array, start_index, cindex-1);
        Qsort(array, cindex+1, end_index);
    }
    return;
}
int split(long* array,int start_index, int end_index){
   long pivot=array[end_index];
    int cindex=start_index;
    for (int i=start_index; i<end_index; i++) {
        if (array[i]<=pivot) {
            swap(array[i],array[cindex]);
            cindex++;
        }
    }
    swap(array[cindex], array[end_index]);

    return cindex;
}

//=====================================================================================
vector<long> QuickSortList(vector<long> nums)
{
    List<long>* linkedlist=new List<long>;
    
    for (int i=0; i<nums.size(); i++) {
        linkedlist->insertAtTail(nums[i]);
    }
    int randomnumber=rand()%nums.size() + 1;
    ListItem<long>* temp=linkedlist->getHead();
    
    for (int i=0; i<randomnumber-1; i++) {
        temp=temp->next;
    }
    long x=temp->value;
    temp->value=linkedlist->getTail()->value;
    linkedlist->getTail()->value=x;
    
    QLsort(linkedlist,0,nums.size()-1);
    
    
    vector<long> sending;
    ListItem<long>* sendd=linkedlist->getHead();
    for (int i=0; i<nums.size(); i++) {
        sending.push_back(sendd->value);
        sendd=sendd->next;
    }
    return sending;
}

void QLsort(List<long>* linkedlist,int start, int end){
    if (start<end) {
        long cindex=splitList(linkedlist, start,end);
        QLsort(linkedlist, start, cindex-1);
        QLsort(linkedlist, cindex+1, end);
    }
    return;
}

int splitList(List<long>* linkedlist,int start, int end){
    ListItem<long>* p=linkedlist->getHead();
    for (int i=0; i<end; i++) {
        
        p=p->next;
    }
    long pivot=p->value;
    ListItem<long>* ll=linkedlist->getHead();
    ListItem<long>* clist=linkedlist->getHead();
    int cindex=start;
    for (int i=0; i<start; i++) {
        clist=clist->next;
        ll=ll->next;
    }
    for (int i=start; i<end; i++) {
        if (ll->value<=pivot) {
            long temp=ll->value;
            ll->value=clist->value;
            clist->value=temp;
            clist=clist->next;
            cindex++;
        }

        ll=ll->next;
    }

    long temporary=p->value;
    p->value=clist->value;
    clist->value=temporary;

    return cindex;


    
    
}


//=======================this done==============================================================
vector<long> HeapSort(vector<long> nums)
{
    long* array=new long[nums.size()];
    array[0]=nums[0];
    for (int i=1; i<nums.size(); i++) {
        array[i]=nums[i];
        int m=floor((i-1)/2);
        int x=i;
        while (array[m]>array[x]) {
            long temp=array[x];
            array[x]=array[m];
            array[m]=temp;
            x=m;
            m=floor((m-1)/2);
        }
    }

    vector<long> sorted;
    for (int i=0; i<nums.size(); i++) {
        remove_min(array,&sorted,nums.size()-i-1);
    }
    return sorted;
}

void remove_min(long* array,vector<long>* sorted,int size){
    sorted->push_back(array[0]);
    reheapify(array,size);
}

void reheapify(long* array,int size){
    array[0]=array[size];
        array[size]=NULL;
    int m=0;
    int runningcheck = 0;
    while (((2*m)+1)<size && ((2*m)+2)<size) {
        if (array[((2*m)+1)] < array[m] && ((2*m)+1)<size) {
            runningcheck=((2*m)+1);
            if (array[m]>array[((2*m)+2)] && array[m]>array[((2*m)+1)]) {
                if (array[((2*m)+2)] < array[((2*m)+1)]) {
                    runningcheck=((2*m)+2);
                }
            }
        }
        else if (array[((2*m)+2)] < array[m] && ((2*m)+2)<size) {
            runningcheck=((2*m)+2);
            if (array[m]>array[((2*m)+2)] && array[m]>array[((2*m)+1)]) {
                if (array[((2*m)+2)] > array[((2*m)+1)]) {
                    runningcheck=((2*m)+1);
                }
            }
        }
        if (array[m] > array[runningcheck]) {
            long temp=array[m];
            array[m]=array[runningcheck];
            array[runningcheck]=temp;
            m=runningcheck;
        }
        else{
            break;
        }
    }
}

//=====================this done================================================================
vector<long> BucketSort(vector<long> nums, int max)
{
    List<long>* hashTable=new List<long>[max];
    int maximum=0;
    for (int i=0; i<nums.size(); i++) {
        hashTable[nums[i]].insertAtHead(nums[i]);
        if (nums[i]>maximum) {
            maximum=nums[i];
        }
    }
    vector<long> sending;
    cout<<maximum<<endl;
    for (int i=0; i<maximum+1; i++) {
        if (hashTable[i].getHead()!=NULL) {
            sending.push_back(hashTable[i].getHead()->value);
        }
    }
    return sending;
    
}

#endif

#ifndef __SORTS_H
#define __SORTS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "list.cpp"

using namespace std;

vector<long> InsertionSort(vector<long> nums);
//--------------------------------------------//
vector<long> MergeSort(vector<long> nums);
void split_list(List<long>* linkedlist, List<long>* leftList, List<long>* rightList,int count);
List<long>* mergeList(List<long>* leftList, List<long>* rightList);
List<long>* Msort(List<long>* mainLL, int size);
//--------------------------------------------//
vector<long> QuickSortArray(vector<long> nums);
void Qsort(long* array,int start_index, int end_index);
int split(long* array,int start_index, int end_index);
int maxi(long a,long b, long c);
int mini(long a,long b, long c);

//--------------------------------------------//
vector<long> QuickSortList(vector<long> nums);
void QLsort(List<long>* linkedlist,int start, int end);
int  splitList(List<long>* linkedlist,int start, int end);
//--------------------------------------------//
vector<long> HeapSort(vector<long> nums);
void remove_min(long* array,vector<long>* sorted,int size);
void reheapify(long* array,int size);
//--------------------------------------------//
vector<long> BucketSort(vector<long> nums, int max);

#endif


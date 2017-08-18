/*********************************************/
/**                                         **/
/**   CF-166A-Rank List.cpp                 **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void swap (int A[],int B[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
    temp = B[a];
    B[a] = B[b];
    B[b] = temp;
}

int getMaxIndex(int anArray[], int first, int last)
{
// return the index of the min value in the
// given Array up to the last index
    int maxIndex; //index of min element
    int index; //index of inspected element
    maxIndex = first;
    for (index = first + 1; index <= last; index++)
    {
        if (anArray[index]>anArray[maxIndex])
            maxIndex = index;
    }
    return maxIndex;
}

void selectionSort(int anArray[],int with[], int size)
{
// returns values in anArray are in ascending order
    int maxIndex; //index of smallest element
    int index; //index of first unsorted element
    for (index = 0; index < size -1; index++)
    {
        maxIndex = getMaxIndex(anArray, index, size-1);
        swap(anArray,with, index, maxIndex);
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    int p[n];
    int t[n];
    for(int i=0; i<n; i++)
    {
        cin >> p[i];
        cin >> t[i];
    }
    selectionSort(p,t,n);
    int start=0,end=0;
    for(int i=1; i<n; i++)
    {
        if(p[i]==p[i-1])
            end++;
        else
        {
            sort(t+start,t+end+1);
            end++;
            start=end;

        }
    }
    sort(t+start,t+end+1);
    int ranking[n];
    ranking[0]=1;
    int count=1;
    for(int i=1; i<n; i++)
    {
        if(p[i]==p[i-1] && t[i]==t[i-1])
        {
            count++;
            ranking[i]=ranking[i-1];
        }
        else
        {
            ranking[i]=ranking[i-1]+count;
            count =1;
        }

    }
    /*/////////////////////////
    cout << "-----start test-----"<< endl;
    for(int i=0; i<n; i++)
    {
        cout << p[i]<<" " <<t[i] << " "<< ranking[i] << endl;
    }
    cout << "-----end test-----"<< endl;
    /*////////////////////////////
    if(k>=ranking[n-1])
    {
        k=ranking[n-1];
        int count=0;
        for(int i=n-1; i>=0; i--)
        {
            if(ranking[i]==k)
                count++;
            else
                break;
        }
        cout << count << endl;
    }
    else
    {
        int upper_index= upper_bound(ranking,ranking+n,k)-ranking;
        cout << ranking[upper_index] - ranking[upper_index-1] << endl;
    }

    return 0;
}

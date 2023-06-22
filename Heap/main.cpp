#include <iostream>
#include <vector>
using namespace std;

void displayArray(vector<int>& arr, int arrSize){
    for (int i=0; i<arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapify(vector<int>& arr, int n, int i){
    //finding the largest out of parent and children
    int largest=i;
    int left=2*i +1;
    int right =2*i +2;
    //find the max of left and right values and update the largest
    if (left<n && arr[left]>arr[largest]) largest=left;
    if (right<n && arr[right]> arr[largest])  largest=right;

    //if the largest i updated swap those and perform heapify on the changed position
    if (largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n , largest); //recursively heapify largest
    }
}

void buildHeap( vector<int>& arr, int arrSize){
    //first non leaf node
    int index=arrSize/2 -1;

    for (int i=index; i>=0; i--){
        heapify (arr, arrSize, i);
        cout<<"Heap is built"<<endl;
        displayArray(arr, arrSize);
    }

}

void heapSort(vector<int>& arr, int arrSize){
    // build heap
    buildHeap(arr, arrSize);

   // extracting elements from heap one by one
   for (int i=arrSize -1; i>=0; i--){
        swap(arr[0], arr[i]); //update the last position with the max
        heapify (arr, i, 0);
    }

}

void insertToHeap(vector<int>& arr, int &arrSize, int val){
    arrSize++;
    arr.push_back(val);
    int i=arrSize-1;
    //insert to the larget position and bring it up the heap if it is greater than the parent else break
    while (i!=0){
        int parent =(i-1)/2;
        if (arr[parent]<arr[i]) {
            swap (arr[parent], arr[i]);
            i=parent;
        }
        else break;
    }
//     cout<<val << " inserted"<<endl;
//     displayArray(arr, arrSize) ;
}

void removeMax(vector<int>& arr, int &arrSize){
    arrSize--;
    swap(arr[0], arr[arrSize]);
    arr.pop_back();
    heapify(arr, arrSize, 0);
    cout<< "max removed"<<endl;
    displayArray(arr, arrSize) ;
}
int main()
{
    int arrSize=10;
    vector<int> heap_arr;
    for (int i = 0; i < arrSize; i++)  heap_arr.push_back(rand() % 100);
    //initial array
    cout<<"Initial Array"<<endl;
    displayArray(heap_arr,arrSize);
    //buildHeap
    buildHeap(heap_arr, arrSize);

    cout<<"Input array"<<endl;
    displayArray(heap_arr,arrSize);

    //insertion and deletion to heap
    for (int i = 0; i < 10; i++)
        insertToHeap(heap_arr, arrSize, rand() % 100);
    for (int i = 0; i < 5; i++)
        removeMax(heap_arr, arrSize);

    //heap sort
    heapSort(heap_arr, arrSize);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, arrSize);

}

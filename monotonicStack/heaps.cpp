#include <iostream>
#include <vector>
using namespace std;

class Max_Heap {
    public:
    
    vector<int> heap;
    Max_Heap(vector<int>arr){
        heap=arr;
    }

    void heapifyDown(int ind){
        int n = heap.size();
        int left = 2*ind+1;
        int right = 2*ind+2;
        int largest = ind;
        if(left<n && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<n && heap[right]>heap[largest]){
            largest=right;
        }
        if(largest==ind) return;
        swap(heap[ind],heap[largest]);
        heapifyDown(largest);
    }

    void heapifyUp(int ind){
        int n = heap.size();
        int parent = (ind - 1)/2;
        if(parent>=0 && heap[ind]>heap[parent]){
            swap(heap[ind],heap[parent]);
            parent=ind;
        }else{
            return;
        }
        heapifyUp(parent);
    }
    
    void build (){
        int n = heap.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapifyDown(i);
        }
    }
};

int main(){

    return 0;
}

//heap sort -> take max heap swap root with the last and then take out last and heapifydown the root
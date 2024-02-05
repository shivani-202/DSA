#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class heap{
    public:
    vector<int> arr;
    int size;

    heap(){
        arr.push_back(-1);
        size = 0;
    }
    void insert(int val) {
        size++;
        int index = size;
        arr.push_back(val); // Push the value to the end of the vector

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }
   
    void deletion() {
         int n = arr.size();
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    arr[1] = arr[size];
    arr.pop_back();
    size--;  // Decrease the size after deletion

    int i = 1;
    while (i <size) {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;

        int max_index = i;
        if (arr[i] < arr[left_child]) {
            max_index = left_child;
        }
        if (right_child <= size && arr[max_index] < arr[right_child]) {
            max_index = right_child;
        }

        if (max_index != i) {
            swap(arr[i], arr[max_index]);
            i = max_index;
        } else {
            break;
        }
    }
}

void heapify(vector<int> & arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}


     void print() {
        for (int i = 1; i<arr.size(); i++) {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(52);
    h.insert(50);
    h.print();
    h.deletion();
    h.print();
    vector<int> v = {-1, 54, 53, 55, 52, 50};
    int n = v.size();
    for(int i = n/2; i>0; i--){
        h.heapify(v, n, i);

    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<v[i];
        cout<<" ";
    }
    return 0;
}
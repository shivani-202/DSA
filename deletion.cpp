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
    int n = arr.size();
    void deletion(){
        arr[1] = arr[n];

        for(int i = 1; i<n; i++){
            if(arr[i] > arr[2*i] && arr[i] > arr[(2*i)+1]){
                return;
            }
            else{
                if(arr[i] < arr[2*i] && arr[2*i] > arr[2*i+1]){
                    swap(arr[i], arr[2*i]);
                }
                else{
                    swap(arr[i], arr[2*i + 1]);
                }
            }
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
    return 0;
}
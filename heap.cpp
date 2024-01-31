#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class heap {
public:
    vector<int> arr;
    int size;

    heap() {
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

    void print() {
        for (int i = 1; i<arr.size(); i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    heap h;
    h.insert(45);
    h.insert(89);
    h.insert(34);
    h.print();
    return 0;
}

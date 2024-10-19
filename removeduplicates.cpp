// Remove duplicates from sorted array
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDuplicatesBrute(vector<int> &arr)
{
    set<int> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int idx = 0;
    int size = st.size();
    for (auto it : st)
    {
        arr[idx] = it;
        idx++;
    }

    return size;
}

int removeDuplicatesOptimised(vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}
int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 3, 4};
    // in-place method
    // int k = removeDuplicatesBrute(arr);
    // for (int i = 0; i < k; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    int x = removeDuplicatesOptimised(arr);
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
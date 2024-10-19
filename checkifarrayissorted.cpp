#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i - 1] <= arr[i])
        {
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3};
    // isSorted(arr);
    if (isSorted(arr))
        cout << "Not Sorted" << endl;
    else
        cout << "Sorted" << endl;
    return 0;
}
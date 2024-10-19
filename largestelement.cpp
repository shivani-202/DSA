// Find the largest and second largest element in an array

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void largestElement(vector<int> arr, int &x1, int &x2)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x1)
        {
            x2 = x1;
            x1 = arr[i];
        }
        else if (arr[i] < x1 && arr[i] >= x2)
        {
            x2 = arr[i];
        }
    }
}
int main()
{
    vector<int> arr = {1, 9, 5, 2, 6, 7};
    int largest = arr[0];
    int slargest = 0;
    cout << "Largest  and Second Largest Element: ";
    largestElement(arr, largest, slargest);
    cout << largest << endl;
    cout << slargest;
    cout
        << endl;
    // cout << "Second Largest Element: " << secLargestElement(arr);
    return 0;
}
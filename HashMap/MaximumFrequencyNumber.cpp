#include <iostream>
using namespace std;
#include <unordered_map>
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> p;
    int maxFreq = 0;
    for (int i = 0; i < n; i++)
    {
        p[arr[i]]++;
        maxFreq = max(maxFreq, p[arr[i]]);
    }
    int maxFreqElement;
    for (int i = 0; i < n; i++)
    {
        if (p[arr[i]] == maxFreq)
        {
            return arr[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
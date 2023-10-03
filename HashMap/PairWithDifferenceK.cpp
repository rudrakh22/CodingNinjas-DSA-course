#include <iostream>
using namespace std;
#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> p;
    int pairCount=0;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i]+k;
        pairCount += p[a];
        if (k != 0)
        {
            a = arr[i] - k;
            pairCount += p[a];
        }
        p[arr[i]]++;
    }
    return pairCount;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
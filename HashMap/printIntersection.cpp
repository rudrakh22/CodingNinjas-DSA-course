#include <iostream>
using namespace std;
#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> p;
    for (int i = 0; i < n; i++)
    {
        p[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (p[arr2[i]] > 0)
        {
            cout << arr2[i] << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}

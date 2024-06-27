#include <iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    int left = low, right = high, Pivot = arr[low];
    // index
    while (left < right)
    {
        // index->value
        while (arr[left] <= Pivot)
        {
            left++;
        }

        while (arr[right] > Pivot)
        {
            right--;
        }
        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        // arr[low] = arr[right];
        // arr[right] = Pivot;
        // return Pivot;
    }
    arr[low] = arr[right];
    arr[right] = Pivot;
    return right;
}
void quickSort(int arr[], int low, int high)
{
    
    if (low < high)
    {

        int pi=partition(arr,low,high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter:" << endl;
    cin >> n;
    int *arr = new int[n];
    // int arr[5]={1 , 3, 5 , 2 ,6};
    // int low ,high;
    // cin >> low >> high;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    // Partition(arr , 0 , n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
}

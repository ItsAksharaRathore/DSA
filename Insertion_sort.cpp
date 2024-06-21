// #include <iostream>
// using namespace std;


// void insertionSort(int arr[], int n)
// {
//     int i, key, j;
//     for (i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;

        
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

// void printArray(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }


// int main()
// {
//     int *arr = new int [23] ;
//     int N = sizeof(arr) / sizeof(arr[0]);

//     insertionSort(arr, N);
//     printArray(arr, N);

//     return 0;
// }


#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
          cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
           cout << arr[i] << " ";
    }
    cout << std::endl;

    delete[] arr; 
    return 0;
}

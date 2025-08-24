#include <iostream>
using namespace std;

void Display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr[4][4] = {
        {10, 2, 0, 0},
        {100, 20, 4, 0},
        {0, 200, 30, 6},
        {0, 0, 300, 40}
    };

    int size = sizeof(arr[0]) / sizeof(arr[0][0]); 

    int main_diag[size] = {0};
    int sub_diag[size] = {0};
    int super_diag[size] = {0};

    for (int i = 0; i < size; i++)
    {
        main_diag[i] = arr[i][i];
        if (i < size - 1)
        {
            sub_diag[i] = arr[i][i + 1];
        }
        if (i > 0)
        {
            super_diag[i - 1] = arr[i][i - 1];
        }
    }

    Display(main_diag, size);
    Display(sub_diag, size);
    Display(super_diag, size);

    return 0;
}
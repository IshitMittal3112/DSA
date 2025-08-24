#include <iostream>
using namespace std;

void Display2D(int (&arr)[50][3], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2] << endl;
}

void Sort2D(int (&arr)[50][3], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][0] > arr[j][0] ||
                (arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1]))
            {
                for (int k = 0; k < 3; k++)
                    swap(arr[i][k], arr[j][k]);
            }
        }
    }
}

void Transpose(int (&arr)[50][3], int (&dest)[50][3], int n)
{
    dest[0][0] = arr[0][1];
    dest[0][1] = arr[0][0];
    dest[0][2] = arr[0][2];

    for (int i = 1; i < n; i++)
    {
        dest[i][0] = arr[i][1];
        dest[i][1] = arr[i][0];
        dest[i][2] = arr[i][2];
    }

    Sort2D(dest, n);
}

void AddSparse(int (&a)[50][3], int (&b)[50][3], int (&res)[50][3])
{
    int i = 1, j = 1, k = 1;
    res[0][0] = a[0][0];
    res[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1])
        {
            int sum = a[i][2] + b[j][2];
            if (sum != 0)
            {
                res[k][0] = a[i][0];
                res[k][1] = a[i][1];
                res[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
        else if (a[i][0] < b[j][0] ||
                 (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k][2] = a[i][2];
            k++;
            i++;
        }
        else
        {
            res[k][0] = b[j][0];
            res[k][1] = b[j][1];
            res[k][2] = b[j][2];
            k++;
            j++;
        }
    }

    while (i <= a[0][2])
    {
        res[k][0] = a[i][0];
        res[k][1] = a[i][1];
        res[k][2] = a[i][2];
        k++;
        i++;
    }

    while (j <= b[0][2])
    {
        res[k][0] = b[j][0];
        res[k][1] = b[j][1];
        res[k][2] = b[j][2];
        k++;
        j++;
    }

    res[0][2] = k - 1;
}

void MultiplySparse(int (&A)[50][3], int (&B)[50][3], int (&Result)[50][3])
{
    if (A[0][1] != B[0][0])
    {
        cout << "Multiplication not possible!\n";
        Result[0][2] = 0;
        return;
    }

    int BT[50][3];
    Transpose(B, BT, B[0][2] + 1);

    Result[0][0] = A[0][0];
    Result[0][1] = B[0][1];
    int k = 1;

    int rowBeginA = 1;
    while (rowBeginA <= A[0][2])
    {
        int rowA = A[rowBeginA][0];
        int rowEndA = rowBeginA;
        while (rowEndA <= A[0][2] && A[rowEndA][0] == rowA)
            rowEndA++;

        int rowBeginB = 1;
        while (rowBeginB <= BT[0][2])
        {
            int rowB = BT[rowBeginB][0];
            int rowEndB = rowBeginB;
            while (rowEndB <= BT[0][2] && BT[rowEndB][0] == rowB)
                rowEndB++;

            int i = rowBeginA, j = rowBeginB, sum = 0;
            while (i < rowEndA && j < rowEndB)
            {
                if (A[i][1] == BT[j][1])
                {
                    sum += A[i][2] * BT[j][2];
                    i++;
                    j++;
                }
                else if (A[i][1] < BT[j][1])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }

            if (sum != 0)
            {
                Result[k][0] = rowA;
                Result[k][1] = rowB;
                Result[k][2] = sum;
                k++;
            }

            rowBeginB = rowEndB;
        }

        rowBeginA = rowEndA;
    }

    Result[0][2] = k - 1;
}

int main()
{
    int mat[4][4] = {{0, 8, 9}, {3, 0, 0}, {0, 0, 7}, {2, 4, 5}};
    int mat2[4][4] = {{1, 9, 0}, {7, 0, 0}, {0, 8, 9}, {0, 0, 0}};
    int n = 4;

    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
                cnt++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat2[i][j] != 0)
                cnt2++;

    int spmat[50][3], spmat2[50][3];
    spmat[0][0] = spmat2[0][0] = n;
    spmat[0][1] = spmat2[0][1] = n;
    spmat[0][2] = cnt;
    spmat2[0][2] = cnt2;

    int k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
            {
                spmat[k][0] = i;
                spmat[k][1] = j;
                spmat[k][2] = mat[i][j];
                k++;
            }

    k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat2[i][j] != 0)
            {
                spmat2[k][0] = i;
                spmat2[k][1] = j;
                spmat2[k][2] = mat2[i][j];
                k++;
            }

    int trp[50][3], addmat[50][3], multmat[50][3];

    cout << "Sparse Matrix A:\n";
    Display2D(spmat, cnt + 1);
    cout << "\nTranspose of A:\n";
    Transpose(spmat, trp, cnt + 1);
    Display2D(trp, cnt + 1);

    cout << "\nAddition of A and B:\n";
    AddSparse(spmat, spmat2, addmat);
    Display2D(addmat, addmat[0][2] + 1);

    cout << "\nMultiplication of A and B:\n";
    MultiplySparse(spmat, spmat2, multmat);
    Display2D(multmat, multmat[0][2] + 1);

    return 0;
}
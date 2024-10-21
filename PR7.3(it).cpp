#include <iostream>
#include <iomanip>

using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void SortByRowDuplicates(int** a, const int rowCount, const int colCount);
int FirstNonNegativeCol(int** a, const int rowCount, const int colCount);

int main()
{
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    // 1. ¬пор€дкувати р€дки за к≥льк≥стю однакових елемент≥в
    SortByRowDuplicates(a, rowCount, colCount);
    cout << "After sorting by duplicate elements:" << endl;
    Print(a, rowCount, colCount);

    // 2. «найти перший стовпець без в≥д'Їмних елемент≥в
    int firstCol = FirstNonNegativeCol(a, rowCount, colCount);
    if (firstCol == -1)
        cout << "No column without negative elements found." << endl;
    else
        cout << "First column without negative elements: " << firstCol + 1 << endl; 

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int CountDuplicatesInRow(int* row, const int colCount)
{
    int duplicates = 0;
    for (int i = 0; i < colCount; i++)
    {
        for (int j = i + 1; j < colCount; j++)
        {
            if (row[i] == row[j])
            {
                duplicates++;
                break;
            }
        }
    }
    return duplicates;
}

void SortByRowDuplicates(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount - 1; i++)
    {
        for (int j = 0; j < rowCount - i - 1; j++)
        {
            if (CountDuplicatesInRow(a[j], colCount) > CountDuplicatesInRow(a[j + 1], colCount))
            {
                int* temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int FirstNonNegativeCol(int** a, const int rowCount, const int colCount)
{
    for (int j = 0; j < colCount; j++)
    {
        bool hasNegative = false;
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative)
            return j; 
    }
    return -1; // якщо не знайдено стовпц€ без в≥д'Їмних елемент≥в
}

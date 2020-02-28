#include <iostream>
using namespace std;

void initMatrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
}

void fillMatrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
int getCurrentMinCol(int** matrix, int startRow, int startCol, int n, int m)
{
    int min = matrix[startRow][startCol];
    int minCol = startCol;
    if (startCol < m - 1)
    {
        for (size_t i = startCol; i < m; i++)
        {
            if (min > matrix[startRow][i])
            {
                min = matrix[startRow][i];
                minCol = i;
            }
        }
    }
    
    for (size_t i = startRow+1; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
                minCol = j;
            }
        }
    }
    return minCol;

}
int getCurrentMinRow(int** matrix, int startRow, int startCol, int n, int m)
{
    int min = matrix[startRow][startCol];
    int minRow = startRow;
    if (startCol < m - 1)
    {
        for (size_t i = startCol; i < m; i++)
        {
            if (min > matrix[startRow][i])
            {
                min = matrix[startRow][i];
            }
        }
    }

    for (size_t i = startRow + 1; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
                minRow = i;
            }
        }
    }
    return minRow;

}
void sortMatrix(int** matrix, int n, int m)
{
    int rowSorted = 0;
    int colSorted = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int currentMinElRow = getCurrentMinRow(matrix, i, j, n, m);
            int currentMinElCol = getCurrentMinCol(matrix, i, j, n, m);
            
            int temp = matrix[currentMinElRow][currentMinElCol];
            matrix[currentMinElRow][currentMinElCol] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}
void printMatrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void deleteMatrix(int** matrix, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int main()
{
    unsigned int N, M;
    cin >> N >> M;
    int** matrix = new int*[N];

    initMatrix(matrix, N, M);
    fillMatrix(matrix, N, M);
    sortMatrix(matrix, N, M);
    printMatrix(matrix, N, M);
    deleteMatrix(matrix, N);

}


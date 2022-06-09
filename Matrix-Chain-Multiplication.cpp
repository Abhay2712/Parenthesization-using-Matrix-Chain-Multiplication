#include <iostream>
#include <conio.h>
#define INT_MAX 999999999
using namespace std;
void PrintParenthesis(int i, int j, int n, int *bracket, char &Mname)
{
    if (i == j)
    {
        cout << Mname++;
        return;
    }
    cout << "(";
    PrintParenthesis(i, *((bracket + i * n) + j), n, bracket, Mname);
    PrintParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, Mname);
    cout << ")";
}
void MCMO(int p[], int n)
{
    int M[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        M[i][i] = 0;
    for (int len = 2; len < n; len++)
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < M[i][j])
                {
                    M[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    cout << "\nThe Cost-Matrix is given by:\n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i > j)
                cout << "X\t";
            else
                cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nOptimal Cost:" << M[1][n - 1] << endl;
    cout << "Optimal Parenthesization:";
    char Mname = 'A';
    PrintParenthesis(1, n - 1, n, (int *)bracket, Mname);
}
int main()
{
    int n;
    cout << "Enter number of matrices:";
    cin >> n;
    int arr[n + 1];
    cout << "Enter dimensions of the matrices:" << endl;
    for (int i = 0; i <= n; i++)
        cin >> arr[i];
    MCMO(arr, n + 1);
    getch();
    return 0;
}

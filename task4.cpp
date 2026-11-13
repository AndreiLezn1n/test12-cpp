#include <iostream>
using namespace std;
int main()
{
    int M, N;
    cout << "enter M and N: ";
    cin >> M >> N;
    int a[50][50];
    cout << "enter matrix elements: " << endl;
    for (int i = 0; i < M; i++){
        for (int j=0; j < N; j++){
            cin >> a [i][j];
        } 
    }
    cout << "rowsum " << endl;
    int maxRowSum = -999999999; 
    int maxRowIndex = 0;
    for (int i = 0; i < M; i++){
        int rowSum = 0;
        for (int j = 0; j < N; j++){
            rowSum += a[i][j];
        }
        cout << "row " << i << ": " << rowSum << endl;
        if (rowSum > maxRowSum) {
            maxRowSum = rowSum;
            maxRowIndex = i;
        }
    }
    cout << "max sun in row: " << maxRowIndex << " (" << maxRowSum << ") " << endl;
    cout << "col sums " << endl;
    for (int j= 0; j < N; j++){
        int colSum = 0;
        for (int i = 0; i < M; i++){
            colSum += a[i][j];
        }
        cout << "col " << j << ": " << colSum << endl;
    }
    cout << "transposed matrix " << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    cout << "saddle points " << endl;
    bool found = false;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            bool isMinlnRow = true;
            for (int k =0; k < N; k++){
                if (a[i][k] < a[i][j]){
                    isMinlnRow = false;
                }
            }
            bool isMaxlnCol = true;
            for (int k = 0; k < M; k++){
                if (a[k][j] > a [i][j]){
                    isMaxlnCol = false;
                }
            }
            if (isMinlnRow && isMaxlnCol){
                cout << "saddle point at (" << i << ", " << j << ") " << a[i][j] << endl;
                found = true;
            }
        }
    }
    if (!found){
        cout << "no saddle points " << endl;
    }
    return 0;
}
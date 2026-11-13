#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "enter N";
    cin >> N;
    int arr[100];
    cout << "enter elements";
    for (int i=0; i < N; i++){
        cin >> arr[i];
    }
int sumPos = 0;
int countNeg = 0;
int minVal = arr[0], minldx = 0;
int maxVal = arr [0], maxldx = 0;
for (int i = 0; i < N; i++){
    if (arr[i] > 0){
        sumPos +=arr[i];
    }
    if(arr[i] < 0){
        countNeg++;
    }
    if(arr[i] < minVal){
        minVal = arr[i];
        minldx = i;
    }
    if (arr[i] > maxVal){
        maxVal = arr[i];
        maxldx = i;
    }
}
cout << "sum positive: " << sumPos << endl;
cout << "count negatives: " << countNeg << endl;
cout << "min: " << minVal << "(index " << minldx << ")" << endl;
cout << "max: " << maxVal << "(index " << maxldx << ")" << endl;
cout << "multiples of 3(reverse): ";
for(int i = N - 1; i >= 0; i--){
    if (arr[i] % 3 == 0) {
        cout << arr[i] << " ";
    }
}
cout << endl;
return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
struct Stats{
    int comparisons = 0;
    int swaps = 0;
};
Stats bubbleSort(vector<int>& arr){
    Stats stats;
    int n = arr.size();
    for (int i = 0; i < n-1; i++){
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++){
            stats.comparisons++;
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                stats.swaps++;
                swapped = true;

            }
        }
        if (!swapped) break;
    }
    return stats;
}
Stats selectionSort(vector<int>& arr){
    Stats stats;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        int minldx = i;
        for (int j = i + 1; j < n; j++){
            stats.comparisons++;
            if(arr[i] < arr[minldx]);
            stats.swaps++;
        }
    }
    return stats;
}
Stats insertionSort(vector<int>& arr){
    Stats stats;
    int n = arr.size();
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            stats.comparisons++;
            if (arr[j] > key){
                arr[j + 1] = arr[j];
                stats.swaps++;
                j--;
            }else{
                break;
            }
        }
        arr[j + 1] = key;
    }
    return stats;
}
vector<int> generateRandomArray(int size){
    vector<int> arr(size);
    for ( int i = 0; i < size; i++){
        arr[i] = rand() % 10000;
    }
    return arr;
}
void printRow(string algoName, int size, Stats s){
    cout << left << setw(20) << algoName
    << setw <<(10) << size
    << setw(15) << s.comparisons
    << setw(15) << s.swaps << endl;
}
int main(){
    srand(time(0));
    int sizes[] = {100, 1000, 5000};
    cout << left << setw(20) << "algorithm "
    << setw(10) << "size(N) "
    << setw(15) << "comparison "
    << setw(15) << "swap " << endl;
    cout << string(60, '-') << endl;
    cout << sizes[0];


    for (const int& si : sizes) {
        vector<int> originalArr = generateRandomArray(si);
        vector<int> arr1 = originalArr;
        Stats s1 = bubbleSort(arr1);
        cout << left << setw(20) << "Bubble Sort"
        << setw(10) << si
        << setw(15) << s1.comparisons
        << setw(15) << s1.swaps << endl;
        vector<int> arr2 = originalArr;
        Stats s2 = selectionSort(arr2);
        cout << left << setw(20) << "Selection Sort"
        << setw(10) << si
        << setw(15) << s2.comparisons
        << setw(15) << s2.swaps << endl;
        vector<int> arr3 = originalArr;
        Stats s3 = insertionSort(arr3);
        cout << left << setw(20) << "Insertion Sort"
        << setw(10) << si
        << setw(15) << s3.comparisons
        << setw(15) << s3.swaps << endl;
        cout << string(60, '-') << endl;
    }
    return 0;
}
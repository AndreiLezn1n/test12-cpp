#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int N, T;
    cout << "enter N and T: ";
    cin >> N >> T;
    vector <int> v;
    for (int i = 0; i < N; i++){
        v.push_back(rand()%101 - 50);
    }
    cout << "originsl vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    vector<int> filtered;
    for (int x : v) {
        if (abs(x) >= T){
            filtered.push_back(x);
        }
    }
    v = filtered;
    cout << "after filtered (abs(x) >= " << T << "): ";
    for (int x : v) cout << x << " ";
    cout << endl;
    int even = 0, odd = 0;
    for (int x : v) {
        if (x % 2 == 0) even ++;
        else odd++;
    }
    cout << "even: " << even << ", odd: " << odd << endl;
    int left = 0;
    int right = v.size() - 1;
    while (left < right) {
        int temp = v[left];
        v[left] = v[right];
        v[right] = temp;
        left++;
        right--;
    }
    cout << "reverse vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
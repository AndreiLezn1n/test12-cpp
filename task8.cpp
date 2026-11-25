#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "N: ";
    cin >> n;
    cin.ignore();
    vector<string> words(n);
    cout << "enter " << n << "strings ";
    for (int i = 0; i < n; i++){
        getline(cin, words[i]);
    }
    cout << "result: ";
    string longestWord = "";
    for (const string& word : words) {
        if (word.length() > longestWord.length()){
            longestWord = word;
        }
    }
    cout << " longest string: " << longestWord << "\" (length: " <<longestWord.length() << ")\n";
    vector<string> sortedAlpha = words;
    sort(sortedAlpha.begin(), sortedAlpha.end());
    cout << "by alphabet: ";
    for (const string& w : sortedAlpha){
        cout << "\"" << w << "\" ";
    }
    cout << "\n";
    vector<string> sortedByLength = words;
    sort(sortedByLength.begin(), sortedByLength.end(), [](const string& a,const string& b){
        if (a.length() != b.length()){
            return a.length() < b.length();
        }
        return a < b;
    });
    cout << "by length: ";
    for (const string& w : sortedByLength) cout << w <<" ";
    cout << "\n";
    vector<string> uniqueWords;
    set<string> seen;
    for (const string& w : words) {
        if (seen.find(w) == seen.end()){
            uniqueWords.push_back(w);
            seen.insert(w);
        }
    }
    cout << "unique: ";
    for (const string& w : uniqueWords) cout << w << " ";
    cout << "\n";
    return 0;
}
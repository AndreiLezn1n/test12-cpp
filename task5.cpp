#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
int main(){
    string s;
    cout << "enter spring: ";
    getline(cin, s);
    istringstream iss(s);
    string word;
    string longest = "";
    int count = 0;
    while (iss >> word){
        count ++;
        if (word.length() > longest.length()){
            longest = word;
        }
    }
    cout << "word: " << count << endl;
    cout << "longest: " << longest << endl;
    string noVowels = "";
    string vowels = "aeiouyAEIOUYаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    for (int i = 0; i < s.length(); i++){
        if (vowels.find(s[i]) == string::npos){
            noVowels += s[i];
        }
    }
    cout << "without vowels: " << noVowels << endl;
    string cleanStr = "";
    for (int i = 0; i < s.length(); i++){
        if (isalpha(s[i])){
            cleanStr += tolower(s[i]);
        }
    }
    bool isPal = true;
    int left = 0;
    int right = cleanStr.length() - 1;
    while (left < right){
        if (cleanStr[left] != cleanStr[right]){
            isPal = false;
            break;
        }
        left++;
        right--;
    }
    if (isPal) cout << "palindrome: yes " << endl;
    else cout << "palindrome: no " << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string text;
    cout << "Enter your text : ";
    getline(cin, text, '\n');
    
    string pattern;
    cout << "Enter your pattern to find in text : ";
    getline(cin, pattern, '\n');
    
    int n = text.size();
    int m = pattern.size();
    bool foo = false;
    
    for(int i=0 ; i<n-m+1 ; i++) {
        
        int p = 0;
        for(int j=i ; j<i+m ; j++) {
            if(text[j] == pattern[p]) {
                p++;
            }
            else {
                break;
            }
        }
        
        if(p == m) {
            cout << "Match is found at : " << i << endl;
            foo = true;
        }
    }
    
    if(foo == false) {
        cout << "No match is found" << endl;
    }
    
    cout << "computation is done" << endl;
    
    return 0;
}

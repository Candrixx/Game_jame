#include<iostream>
#include<string.h>
#include<cctype>

using namespace std;

int main(){

    string text;
    bool flag = false;
    getline(cin, text);
    for(int i=0; i<text.length()-1; i++){
        char c = int(text[i]) + int(text[i+1]) - 154;
        cout << c;
    }
    return 0;
}
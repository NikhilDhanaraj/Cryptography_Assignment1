#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> findPosition(vector <int> numSeq){
    vector<int> positions(numSeq.size(),-1);
    
    for (int i = 0; i < numSeq.size(); i++) {
        positions[numSeq[i]] = i;
    }
    
    return positions;
}

vector<int> numSequence(string word){
    vector <int> result(word.length(),-1);
    int count = 0;
    for(int i = 65;i<=90;i++){
        for(int j = 0;j<word.length();j++){
            if(i == word[j] && result[j] == -1){
                result[j] = count++;
            }
        }
    }
    return result;
    
}

string insertX(const string &str) {
    string result;
    for (int i = 0; i < str.length(); i += 2) {
        result += str[i];
        if (i + 1 < str.length() && str[i] == str[i + 1]) {
            result += 'X';
        }
        if (i + 1 < str.length()) {
            result += str[i + 1];
        }
    }
    return result;
}

int findRow(char c, const vector<vector<char>> &matrix){
    int found = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(c==matrix[i][j]){
                found = i;
            }
            if(found != 0){
                break;
            }
        }
        if(found != 0){
                break;
        }
    }
    return found;
}

int findColumn(char c, const vector<vector<char>> &matrix){
    int found = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(c==matrix[i][j]){
                found = j;
            }
            if(found != 0){
                break;
            }
        }
        if(found != 0){
                break;
        }
    }
    return found;
}

string playFairDecipher(string cipherText, string key){
    vector<vector<char>> matrix(5,vector<char>(5,'x'));
    vector<int> count(26,0);
    count[9] = 1;
    
    int rindex = 0;
    int cindex = 0;
    int index = 0;
    
    while(index<key.size()){
        if(count[key[index]-'A']==0){
            matrix[rindex][cindex] = key[index];
            count[key[index]-'A'] = 1;
            if(cindex+1 >= 5){
                cindex = 0;
                rindex++;
            }else{
                cindex++;
            }
        }
        index++;
    }
    int temp = 0;
    for(int i = 0; i<5;i++){
        for(int j = 0;j<5;j++){
            if(matrix[i][j] == 'x'){
                int flag = 0;
                while(flag == 0){
                    if(temp>=26){
                        break;
                    }
                    if(count[temp]==0){
                        flag = 1;
                        matrix[i][j] = temp +'A';
                    }
                    temp++;
                }
            }
        }
    }
    
    // for(int i = 0;i<5;i++){
    //     for(int j = 0;j<5;j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    string plainText;
    
    string latentText = insertX(cipherText);
    // string latentText = cipherText;
    
    if(latentText.length()%2 == 1){
        latentText += 'X';
    }
    
    //cout << latentText << endl;
    
    for(int k = 0;k<latentText.length();k+=2){
        int iOne = findRow(latentText[k],matrix);
        int jOne = findColumn(latentText[k],matrix);
        int iTwo = findRow(latentText[k+1],matrix);
        int jTwo = findColumn(latentText[k+1],matrix);
        
        if(iOne == iTwo){
            int newJOne = (jOne - 1) >= 0 ? (jOne - 1) : 4;
            plainText += matrix[iOne][newJOne];
            int newJTwo = (jTwo - 1) >= 0 ? (jTwo - 1) : 4;
            plainText += matrix[iTwo][newJTwo];    
        }else if(jOne == jTwo){
            int newIOne = (iOne - 1) >= 0 ? (iOne - 1) : 4;
            plainText += matrix[newIOne][jOne];
            int newITwo = (iTwo - 1) >= 0 ? (iTwo - 1) : 4;
            plainText += matrix[newITwo][jTwo];
        }else{
            plainText += matrix[iOne][jTwo];
            plainText += matrix[iTwo][jOne];
        }
    }
    
    
    //cout << plainText << endl;
    
    return plainText;
}

string vigenereDecipher(string cipherText, string Key){
    vector<int> cipherNum(cipherText.length(),-1);
    vector<int> keyNum(Key.length(),-1);
    
    for(int i = 0;i<cipherText.length();i++){
        cipherNum[i] = cipherText[i] - 'A';
    }
    for(int i = 0;i<Key.length();i++){
        keyNum[i] = Key[i] - 'A';
    }
    int k = 0;
    vector<int> plainNum(cipherText.length(),-1);
    for(int i = 0;i<cipherNum.size();i++){
        plainNum[i] = (cipherNum[i] - keyNum[k])%26;
        k = (k+1)%keyNum.size();
    }
    string plainText;
    for(int i = 0;i<plainNum.size();i++){
        plainText += plainNum[i] + 'A';
    }
    //cout << plainText << endl;
    return plainText;
}

string columnarDecipher(string cipherText, string Key){
    int cols = Key.length();
    int rows = cipherText.length()/cols;
    vector<vector<char>> matrix(rows, vector<char>(cols,'X'));
    
    vector<int> numSeq = numSequence(Key);
    vector<int> position = findPosition(numSeq);
    int index = 0;
    for(int j= 0;j<cols;j++){
        for(int i = 0;i<rows;i++){
            if(index<cipherText.length()){
                matrix[i][position[j]] = cipherText[index++];
            }
        }
    }
    
    // for(int i = 0;i<rows;i++){
    //     for(int j = 0;j<cols;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    string plainText;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(matrix[i][j]!='X'){
                plainText += matrix[i][j];
            }
        }
    }
    //cout << plainText << endl;
    return plainText;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string playFairKey;
    string vigenereKey;
    string columnarKey;
    
    string cipherText;
    
    cin >> playFairKey;
    cin >> vigenereKey;
    cin >> columnarKey;
    
    cin >> cipherText;
    
    string cipherOne = columnarDecipher(cipherText, columnarKey);
    //string cipherTwo = vigenereDecipher(cipherOne, vigenereKey);
    //string plainText = playFairDecipher(cipherTwo, playFairKey);
    
    //cout << plainText;

    return 0;
}

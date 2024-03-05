#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

vector<int> numSequence(string word)
{
    vector<int> result(word.length(), -1);
    int count = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 0; j < word.length(); j++)
        {
            if (i == word[j] && result[j] == -1)
            {
                result[j] = count++;
            }
        }
    }
    return result;
}

string columnTransformation(string codeWord, string columnKey)
{

    int cols = columnKey.length();
    int rows = codeWord.length() / cols;
    if (codeWord.length() % cols != 0)
    {
        rows += 1;
    }
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    int index = 0;

    vector<int> numSeq = numSequence(columnKey);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (index < codeWord.length())
            {
                matrix[i][numSeq[j]] = codeWord[index++];
            }
        }
    }

    // for(int i = 0;i<rows;i++){
    //     for(int j = 0;j<cols;j++){
    //         cout<<matrix[i][numSeq[j]]<<" ";
    //     }
    //     cout <<endl;
    // }
    string cipherText;
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            cipherText += matrix[i][j];
        }
    }

    return cipherText;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string columnKey;
    string polybiusKey;
    string plaintext;
    cin >> columnKey;
    cin >> polybiusKey;
    cin >> plaintext;
    string squareKeyOne = "CRYPTO";
    string squareKeyTwo = "GRAPHY";

    int k = 0;
    vector<vector<char>> polybius(6, vector<char>(6, ' '));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            polybius[i][j] = polybiusKey[k++];
        }
    }

    string codeWord;
    for (int i = 0; i < plaintext.length(); i++)
    {
        for (int m = 0; m < 6; m++)
        {
            for (int n = 0; n < 6; n++)
            {
                if (polybius[m][n] == plaintext[i])
                {
                    codeWord += squareKeyOne[m];
                    codeWord += squareKeyTwo[n];
                }
            }
        }
    }

    // cout << codeWord<<endl;

    string cipherText = columnTransformation(codeWord, columnKey);

    cout << cipherText;

    return 0;
}
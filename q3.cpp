#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string straddleKey;
    int excOne;
    int excTwo;
    string cipherText;
    int depth;

    cin >> straddleKey;
    cin >> excOne;
    cin >> excTwo;
    cin >> cipherText;
    cin >> depth;

    int k = 0;
    vector<vector<char>> straddleMatrix(3, vector<char>(10, ' '));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 && (j == excOne || j == excTwo))
            {
                continue;
            }
            else
            {
                if (k < straddleKey.length())
                {
                    straddleMatrix[i][j] = straddleKey[k++];
                }
            }
        }
    }

    // for(int i = 0;i<3;i++){
    //     for(int j = 0;j<10;j++){
    //         cout<<straddleMatrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //     for(int i = 0;i<cipherText.length();i++){
    //         char temp;
    //         if(cipherText[i]-'0'==excOne){
    //             if(i+1>=cipherText.length()){
    //                 break;
    //             }
    //             i++;
    //             temp = straddleMatrix[1][cipherText[i]-'0'];
    //             latentCipher += temp;
    //         }else if(cipherText[i]-'0'==excTwo){
    //             if(i+1>=cipherText.length()){
    //                 break;
    //             }
    //             i++;
    //             temp = straddleMatrix[2][cipherText[i]-'0'];
    //             latentCipher += temp;
    //         }else{
    //             temp = straddleMatrix[0][cipherText[i]-'0'];
    //             latentCipher += temp;
    //         }

    //     }

    k = 0;
    int n = cipherText.length();
    int i = 0;
    int j = 0;
    vector<vector<char>> railText(depth, vector<char>(n, '-'));

    int flag = 0;
    while (k < n)
    {
        railText[i][j] = 'x';
        k++;
        if (flag == 0)
        {
            if (i + 1 >= depth)
            {
                flag = 1;
                i--;
            }
            else
            {
                i++;
            }
            j++;
        }
        else
        {
            if (i - 1 < 0)
            {
                flag = 0;
                i++;
            }
            else
            {
                i--;
            }
            j++;
        }
    }
    k = 0;
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (railText[i][j] == 'x')
            {
                railText[i][j] = cipherText[k++];
            }
        }
    }

    // for(int i = 0;i<depth;i++){
    //     for(int j = 0;j<n;j++){
    //        cout<<railText[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    i = 0;
    j = 0;
    flag = 0;
    string latentCipher;

    while (j < n)
    {
        if (flag == 0)
        {
            latentCipher += railText[i][j];
            if (i + 1 >= depth)
            {
                flag = 1;
                i--;
            }
            else
            {
                i++;
            }
            j++;
        }
        else
        {
            latentCipher += railText[i][j];
            if (i - 1 < 0)
            {
                flag = 0;
                i++;
            }
            else
            {
                i--;
            }
            j++;
        }
    }

    // cout << latentCipher << endl;

    string plainText;

    for (int i = 0; i < latentCipher.length(); i++)
    {
        char temp;
        if (latentCipher[i] - '0' == excOne)
        {
            if (i + 1 >= latentCipher.length())
            {
                break;
            }
            i++;
            temp = straddleMatrix[1][latentCipher[i] - '0'];
            plainText += temp;
        }
        else if (latentCipher[i] - '0' == excTwo)
        {
            if (i + 1 >= latentCipher.length())
            {
                break;
            }
            i++;
            temp = straddleMatrix[2][latentCipher[i] - '0'];
            plainText += temp;
        }
        else
        {
            temp = straddleMatrix[0][latentCipher[i] - '0'];
            plainText += temp;
        }
    }

    cout << plainText;

    return 0;
}
# Cryptography_Assignment1
Different techniques to encipher and decipher different texts based on substitution, transposition and product ciphers.

Q1:
  About the algorithm:
  
  This algorithm is an example of a substitution cipher. More specifically, it’s a type of steganography, where a message is encoded within another message. The algorithm is roughly explained as follows:
  Convert each letter to its binary representation.
  Each binary bit is then substituted with either SecretCharacter1 (SC1) or SecretCharacter2 (SC2), based on its value.
  Refer to this link for a detailed explanation with example.
  Input Format
  The input consists of 2 lines where:
  The first line contains SC1 followed by SC2, separated by a space.
  The second line contains the ciphertext to be decrypted.
  
  Constraints
  The input string will pertain to the language {SC1, SC2}.
  You are not allowed to use libraries like cryptography available in python.
  
  Output Format
  Print the plaintext in uppercase string format.

Q2:
  This algorithm is a product cipher of two ciphers: polybius square cipher and columnar transposition. The encrypting takes place in two phases. First phase is performing substitution while the second phase is fractionating.
  
  During the substitution phase, we substitute each letter with two letters retrieved from the polybius square (https://en.wikipedia.org/wiki/Polybius_square)
  After this, fill the enciphered text below the keyword in a matrix format left to right in a row and top to bottom fashion. Now perform columnar transposition by sorting the keyword in alphabetical order. (https://privacycanada.net/columnar-transposition-cipher/)
  Now retrieve the text from the matrix column wise top to down to get the final ciphered text. Refer to the following link for a detailed explanation with example:  http://practicalcryptography.com/ciphers/classical-era/adfgvx/
  
  Input Format
  The input consists of 3 lines where:
  The first line consists of the keyword for columnar transposition
  The second line consists of a permutation of the alphabets (in upper case) and digits. This should be used to fill the polybius square in left to right fashion
  The third line consists of the plain text to encrypt
  
  Constraints
  The input string will consist of A-Z characters i.e.., English alphabets in upper case and 0-9 digits only. (Total 36 characters in the Polybius Square key)
  You have to fill the empty spaces in the matrix during the columnar transposition step using the character ‘X’. Which means that your cipher text may contain the character ‘X’ along with a certain permutation 
  of the characters of the word ‘CRYPTOGRAPHY’.
  
  Output Format
  Cipher text – String

Q3:
  This algorithm is a product cipher of two ciphers: Straddle Checkerboard and Rail fence Transposition. The encrypting takes place in two phases. First phase is performing substitution while the second phase is transposition.
  
  During the substitution phase, we substitute each letter with either one or more digits retrieved from the straddle checkerboard (https://en.m.wikipedia.org/wiki/Straddling_checkerboard)
  After this, impose rail fence transposition on the output of the straddle checkerboard. (https://privacycanada.net/rail-fence-cipher/)
  Refer to the following link for a detailed explanation with example: http://practicalcryptography.com/ciphers/straddle-checkerboard-cipher/
  
  NOTE:
  
  Remember we stop the algorithm after encoding it with the initial matrix setup. We DO NOT proceed to add a new secrect key number nor do we convert the cipher numbers to letters again using the same setup during encryption.
  Please keep in mind that the above algorithm is that of Encryption whereas you are asked to write the code for Decryption of this particular algorithm.
  
  Input Format
  The input consists of 4 lines where:
  The first line consists of the “key” for straddling checkerboard
  The second line consists of digits excluded from the first row of the straddle checkerboard
  The third line consists of the ciphertext to decrypt
  The fourth line consists of an integer which will be the “Key” (denoting the number of rows to be used) for the rail fence transposition.
  
  Constraints
  The ciphertext to decrypt consists of a permutation of the digits [0-9] only.
  
  Output Format
  Plain text – String

Q4:
  The given algorithm is a product cipher, combining the strengths of Playfair, Vigenère, and Columnar Transposition ciphers to enhance the security of the encryption process.
  
  Playfair cipher: Employing the Playfair cipher involves the generation of a key table derived from a given keyword. The plaintext is then broken into digraphs, pairs of letters, and each digraph undergoes the Playfair encryption process. This step serves as the initial layer in our product cipher, introducing a spatial transformation to the original message.
  Vigenère Cipher: The Vigenère cipher introduces an additional layer of complexity. Utilizing a chosen keyword, it is repeated to match the length of the plaintext. The combination of this extended keyword and the original plaintext occurs through the Vigenère square, resulting in a transformed ciphertext. This second layer adds a dynamic element to our cryptographic puzzle.
  Columnar Transposition Cipher: The third and final layer involves the Columnar Transposition cipher. The Vigenère ciphertext is systematically rearranged into a grid, adhering to a specified columnar transposition key. Reading the columns of this grid in the order dictated by the key produces the ultimate ciphertext. This sequential application of ciphers in a product fashion contributes to the overall robustness of our cryptographic algorithm.
  Please refer to the following three links for a detailed explanation with examples for the specified algorithms:
  Playfair cipher: https://privacycanada.net/playfair-cipher/
  Vigenère Cipher: https://privacycanada.net/classical-encryption/vigenere-cipher/
  Columnar Transposition Cipher: https://privacycanada.net/columnar-transposition-cipher/
  NOTE:
  
  In the Playfair cipher, the convention we follow here is to exclude 'I' and 'J' from sharing the same cell, and 'J' is removed from the matrix.
  For the columnar transposition cipher during encryption, if the last row has empty cells, they should be filled with the character 'X'.
  It's important to note that the decryption process for these adjustments will need to be considered and implemented accordingly.
  
  Input Format
  The input consists of 4 lines where:
  The first line contains the key for the Playfair cipher.
  The second line contains the key for the Vigenere cipher.
  The third line contains the key for the Columnar Transposition cipher.
  The fourth line contains the ciphertext to be decrypted.
  
  Constraints
  It is to be assumed that in the outputs generated by the Playfair and Vigenère ciphers, none will contain the alphabet 'X'. Therefore, the presence of 'X' in the final ciphertext can be attributed solely to the application of the columnar transposition cipher.
  The input strings will pertain to the language {A-Z}.
  You are not allowed to use libraries like cryptography available in python.
  
  Output Format
  Print the plaintext in uppercase string format.

/*
Name: Miranda Seibers
Course Number/Title/Number: CS215 Data Structures 11443
Assignment ID: Secure Computing Program
Semester/Year: Spring 2024
Program discription:
Overall the program reads the input file Cats.txt and encrypts it in an output file. 
The program then decrypts the encrypted message and displays it on the screen.

Input: Cats.txt file for input file. Two paragraphs in file.
Output: encrypted_message.txt for output file. 
The program also decrypts this file and outputs it in English on the screen.
*/
#include <iostream>
#include <fstream>

using namespace std;

//Function to encrypt 
char encryptChar(char c, char key) 
{
    //Check if the character is a letter
    if (isalpha(c)) 
    {
        char base = isupper(c) ? 'A' : 'a'; //Check if upper or lower case
        return (c - base + key - 'A') % 26 + base; //Encrypt using the key
    }
    return c;
}

//Function to decrypt
char decryptChar(char c, char key) 
{
    //Check if the character is a letter
    if (isalpha(c)) 
    {
        char base = isupper(c) ? 'A' : 'a'; //Check if upper or lower case
        return (c - base - (key - 'A') + 26) % 26 + base; //Decrypt using key
    }
    return c;
}
//Function to ecrypt a file
void encrypt(const char* inputFileName, const char* outputFileName, char key) 
{
    ifstream inputFile(inputFileName); //Read input file
    ofstream outputFile(outputFileName); //Open output file for writing
    char c;

    //Encrypt the letters and write to output file
    while (inputFile.get(c)) 
    {
        outputFile.put(encryptChar(c, key));
    }

    inputFile.close(); //Close input file
    outputFile.close(); //Close output file
}

//Funtion to decrypt a file
void decrypt(const char* inputFileName, char key) 
{
    ifstream inputFile(inputFileName); //Read file
    char c;

    //Decrypt the letters and output on screen
    while (inputFile.get(c)) 
    {
        cout << decryptChar(c, key);
    }

    inputFile.close(); //Close input file
}

int main() 
{
    char key = 'C'; //Key is C for Cats

    //Ecrypt the input file and save to output file
    encrypt("Cats.txt", "encrypted_message.txt", key);
    cout << "Encrypted message saved to encrypted_message.txt" << endl;

    //Decrypt the encrypted message and output on screen
    cout << "Decrypted Message: ";
    decrypt("encrypted_message.txt", key);

    return 0;
}




// FCAI – Programming 1 – 2022 - Assignment 4.
// Program Name: CS112-203-2nd - S9,10 -20210090-20210492-20211109-A4- TextEditorApp.cpp
// Last Modification Date: 10/05/2022
// Author1 and ID and Group: Basmala Mohamed Sayed Gad  ID: 20210090  Group: s10 - Functions : 1 - 5
// Author2 and ID and Group: Sohaila Abdelazim Khalifa  ID: 20210492  Group: s10 - Functions : 6 - 10
// Author3 and ID and Group: Hadeer Abdelnasser         ID: 20211109  Group: s10 - Functions : 11 - 15
// Teaching Assistant: Afaf Abdelmonem
/* Purpose: The purpose of this program is to allow the user to apply different opeartions upon the text files  .*/

#include "textlib.cpp"

int main(){

    string nOperation;
    cout << "Ahlan ya user ya habibi :)" << "\n";
    cout << "Please enter the name of the file you want to deal with:" << "\n";
    checkExisting();

    while (true)
    {
        nOperation = "";
        cout << "Please select an option to apply, 15 to save or 0 to exit:" << "\n";
        cout << "1- Add new text to the end of the file" << "\n" << "2- Display the content of the file" << "\n"
             << "3- Empty the file" << "\n" << "4- Encrypt the file content" << "\n"
             << "5- Decrypt the file content" << "\n" << "6- Merge another file" << "\n"
             << "7- Count the number of words in the file." << "\n" << "8- Count the number of characters in the file" << "\n"
             << "9- Count the number of lines in the file" << "\n" <<"10- Search for a word in the file" << "\n"
             << "11- Count the number of times a word exists in the file" << "\n" << "12- Turn the file content to upper case" << "\n"
             << "13- Turn the file content to lower case." << "\n" << "14- Turn file content to 1st caps (1st char of each word is capital)" << "\n"
             << "15- Save" << "\n" << "0- Exit" << "\n";

        cin.clear();
        cin >> nOperation;

        if (nOperation == "1")
        {
            addNewText();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "2")
        {
            displayContent();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "3")
        {
            deleteContent();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "4")
        {
            encryptContent();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "5")
        {
            decryptContent();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "6")
        {
            mergeFile();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "7")
        {
            countWordsNumber();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "8")
        {
            countCharNumber();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "9")
        {
            countLinesNumber();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "10")
        {
            searchWord();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "11")
        {
            countWordExists();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "12")
        {
            upperCase();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "13")
        {
            lowerCase();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "14")
        {
            firstCaps();
            cout << "Process is done !" << "\n" << "\n";

        }
        else if (nOperation == "15")
        {
            saveFile();
            cout << "Process is done !" << "\n" << "\n";
        }
        else if (nOperation == "0")
        {
            break;
        }
        else
        {
            cout << "Please enter valid choice: " << "\n";
        }
    }
    cout << "Thank you for using this program :)" << "\n";
    return 0;
}

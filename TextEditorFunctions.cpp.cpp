#include "textlib.h"

void checkExisting()
{
    cout << "Please enter the file name: " << "\n";
    cin >> fileName;
    strcat(fileName,".txt");    // adding ".txt" to file name using string concatenate.

    file.open(fileName,ios::in);   // open file with input made.

    // check if file is existing or not.
    if(!(file.fail()))
    {
        cout << "This File Already Exists" << "\n";
        file.close();
    }
    else
    {
        file.open(fileName,ios::out);   // if file does not exist it will open new one in out put made.
        cout << "This is a new file. I created it for you :)" << "\n";
        file.close();
    }
}

void addNewText()
{
    string line;
    cout << "Please, enter text here:" << "\n";
    file.open(fileName,ios::app);  // open file in append mode.
    cin.ignore();
    while(getline(cin,line))  // to get whole line as input.
    {
        file << line << "\n";
    }
    file.close();
}

void displayContent()
{
    file.open(fileName);
    cout << file.rdbuf();  // to read all buffer.
    file.close();
}

void deleteContent()
{
    file.open(fileName,ios::out|ios::trunc);  // output and trunc mode to delete all content.
    file.close();
}

void encryptContent()
{
    string content, encryptedContent;

    ostringstream buffer;
    file.open(fileName);
    buffer << file.rdbuf();  // read all buffer in output string stream.
    content = buffer.str();  // convert this string stream to string.
    file.close();

    for (int i = 0; i < content.length(); ++i)
    {
        encryptedContent += char(content[i]+1);
    }

    file.open(fileName,ios::out);
    file << encryptedContent;
}

void decryptContent()
{
    string content, decryptedContent;

    ostringstream buffer;
    file.open(fileName);
    buffer << file.rdbuf();  // read all buffer in output string stream.
    content = buffer.str();  // convert this string stream to string.
    file.close();

    for (int i = 0; i < content.length(); ++i)
    {
        decryptedContent += char(content[i]-1);
    }

    file.open(fileName,ios::out);
    file << decryptedContent;
}

void mergeFile()
{
    fstream file2;
    string content;
    char fileName2[100];

    // getting file2 name and check if it is existing.
    cout << "Please enter name of file to merge with: " << "\n";
    cin >> fileName2;
    strcat(fileName2,".txt");

    file2.open(fileName2);
    while (file2.fail()) {
        cout << " Invalid File Name \n";
        cin >> fileName2;
    }

    ostringstream buffer;
    file2.open(fileName2);
    buffer << file2.rdbuf();
    content = buffer.str();
    file2.close();

    file.open(fileName,ios::out|ios::app);
    file << content;
    file.close();
}

void countWordsNumber()
{
    int nWords = 0;
    char character;

    file.open(fileName);
    file.seekg(0,ios::beg);  // bring position of file pointer to the beginning of file.
    while (!file.eof())
    {
        file.get(character);
        if (character == ' ' || character == '\n'|| character == '\t')
        {
            nWords++;
        }
    }
    cout<< "Number of Words = " << nWords << "\n";
    file.close();
}

void countCharNumber()
{

    int nChar = 0;  // it counts the EOF character.
    char character;

    file.open(fileName);
    while (!file.eof())
    {
        file.get(character);  // to get only one char every iteration.
        cout << character;
        nChar++;
    }
    cout << "Number of characters = " << nChar << "\n";
    file.close();
}

void countLinesNumber()
{
    int nLines = 1;  // start from 1 to count the first line.
    char character;

    file.open(fileName);
    while (!file.eof())
    {
        file.get(character);
        if ( character == '\n')  // takes the last line left as extra line.
        {
            nLines++;
        }
    }
    cout << "Number of Lines = " <<  nLines << "\n";
    file.close();
}

void searchWord()
{
    lowerCase();
    file.close();

    bool wordFound = false;
    string word, fileWord;

    cout << "Please enter the word you want to search for : " << "\n";
    cin >> word;

    for (int i = 0; i < word.length(); ++i)
    {
        word[i] = tolower(word[i]);
    }

    file.open(fileName,ios:: in);
    while( file >> fileWord)
    {
        if (fileWord == word)
        {
            wordFound = true;
            break;
        }
    }
    file.close();

    if (wordFound == true){
        cout << "Word was found in the file" << "\n";
    }
    else {
        cout << "Word was not found in the file" << "\n";
    }
}

void countWordExists()
{
    lowerCase();
    file.close();

    int nWords = 0;
    string word, fileWord;

    cout << "Please enter the word you want to search for : " << "\n";
    cin >> word;

    for (int i = 0; i < word.length(); ++i)
    {
        word[i] = tolower(word[i]);
    }

    file.open(fileName,ios::in);
    while( file >> fileWord)
    {
        if(fileWord == word)
        {
            nWords++;
        }
    }
    file.close();
    cout << "The word " << word << " was found " << nWords << " times in the file." << "\n";
}

void upperCase()
{
    string upperString;
    char character;

    file.open(fileName);
    file.seekg(0,ios::beg);  // bring position of file pointer to the beginning of file.

    while (!file.eof())
    {
        character = file.get();  // to get only one char every iteration.
        if (isalpha(character))
        {
            upperString += toupper(character);
        }
        else
        {
            upperString += character;
        }
    }
    upperString.pop_back();  // to delete EOF.
    file.close();

    file.open(fileName,ios::out);
    file << upperString;
}

void lowerCase()
{
    string lowerString;
    char character;

    file.open(fileName);
    file.seekg(0,ios::beg);  // bring position of file pointer to the beginning of file.

    while (!file.eof())
    {
        character = file.get();  // to get only one char every iteration.
        if (isalpha(character))
        {
            lowerString += tolower(character);
        }
        else
        {
            lowerString += character;
        }

    }
    lowerString.pop_back();  // to delete EOF.
    file.close();

    file.open(fileName,ios::out);
    file << lowerString;
}

void firstCaps()
{
    lowerCase();
    file.close();

    string content;
    ostringstream buffer;
    file.open(fileName);
    buffer << file.rdbuf();
    content = buffer.str();
    file.close();

    for (int i = 0; i < content.length(); i++)
    {
        content[0] = toupper(content[0]);

        if ((isalpha(content[i]) and content[i - 1] == ' ') or
            ((isalpha(content[i])and content[i - 1] == '\n' )) or
            (isalpha(content[i]) and content[i - 1] == '\t' ) or
            (isalpha(content[i]) and content[i - 1] == '-' ) )
        {
            content[i] = toupper(content[i]);
        }
        else
        {
            content[i] = content[i];
        }
    }

    file.open(fileName, ios::out);
    file << content;
}

void saveFile()
{
    fstream file2;
    string choice;
    char newFileName [200];

    cout << "Please choose to save (s) on same file or under a (d) different name." << "\n";
    cin >> choice;

    // check if user entered more than one letter.
    while (choice.length() > 1)
    {
        cout << "Please choose one choice." << "\n";
        cin >> choice;
    }

    if(tolower(choice[0]) == 's')
    {
        file.close();
        cout << "Done!";
    }
    else if(tolower(choice[0]) == 'd')
    {
        cout << "Please enter new file name : " << "\n";
        cin >> newFileName;
        strcat(newFileName,".txt");

        string content;
        ostringstream buffer;
        file.open(fileName);
        buffer << file.rdbuf();
        content = buffer.str();
        file.close();

        file2.open(newFileName,ios::out);
        file2 << content;
        file2.close();
    }
    else
    {
        cout << "Invalid Operation" << "\n";
    }
}
/*
 * Name: Noah Taylor
 * Date: November 27/23
 * Filename: MorseCode > main.cpp
 * Program: Convert English to morse code and vice versa
 * */

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>//toupper function

using namespace std;

//Convert single character to morse
string charToMorse(char c) {
    switch (toupper(c)) { //toupper function allows a less cluttered switch statement as you don't have to have: case 'a': case 'A': {}
        //Morse code mapping for letters
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        default:  return ""; // Space or unknown characters
    }
}

//Convert single character to English
char morseToChar(const string& morse) {
    //Map for Morse -> character conversion
    static map<string, char> morseToCharMap = {
            {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
            {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
            {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
            {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
            {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
            {"--..", 'Z'}
    };

    //Find the morse code in map and return to the corresponding character
    auto it = morseToCharMap.find(morse);
    if (it != morseToCharMap.end()) {
        return it->second;
    }

    //Return spaces for unknown morse code
    return ' ';
}

//English -> Morse
string stringToMorse(const string& input) {
    string morseCode;
    for (char c : input) {
        if (isspace(c)) {
            //Add space between words
            morseCode += " ";
        } else {
            //Convert character to Morse and append
            string charMorse = charToMorse(c);
            if (!charMorse.empty()) {
                morseCode += charMorse + " ";
            }
        }
    }
    return morseCode;
}

//Morse -> English
string morseToString(const string& morseCode) {
    stringstream ss(morseCode);
    string morseSegment;
    string result;

    //Process each Morse segment and convert to character
    while (ss >> morseSegment) {
        char englishChar = morseToChar(morseSegment);
        result += englishChar;
    }

    return result;
}

//Main
int main() {
    int menuIn;

    //Menu Display
    cout << "1. English to Morse" << endl;
    cout << "2. Convert Morse Code to English" << endl;
    cout << "3. Exit" << endl;

    //Get user choice
    cin >> menuIn;
    cin.ignore(); //Consume newline character

    switch (menuIn) {
        case 1: {
            //English -> Morse
            string userIn;
            cout << "Enter an English string: ";
            getline(cin, userIn);
            string morseCode = stringToMorse(userIn);
            cout << "Morse Code: " << morseCode << endl;
            break;
        }
        case 2: {
            //Morse -> English
            string userIn;
            cout << "Enter Morse code: ";
            getline(cin, userIn);
            string englishString = morseToString(userIn);
            cout << "English: " << englishString << endl;
            break;
        }
        case 3: {
            exit(0);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }
    return 0;
}
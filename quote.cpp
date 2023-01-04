// Copyright Johanna Liu 2022
//
// Created by Johanna Liu
// Created in Dec 2022
// This program calculates the average

#include <iostream>
#include <list>
#include <string>
// below for splitting string
// reference: https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
#include <sstream>
#include <iterator>  // call specific points in list
#include <tuple>  // multiple return values

std::string createBorder(std::list<std::string> words) {
    list<std::string>::iterator pointer = words.begin();
    std::string nextString;
    std::string string;
    int width;
    std::string border;

    std::advance(pointer, 0);
    std::string largestString = *pointer;

    // reference: https://stackoverflow.com/questions/16747591/how-to-get-an-element-at-specified-index-from-c-list
    for (int loopCounter = 0; loopCounter < words.size(); loopCounter++) {
        std::advance(pointer, loopCounter);
        nextString = *pointer;
        if (largestString.size() < nextString.size()) {
            largestString = nextString;
        }
    }
    width = largestString.size() + 4;

    for (int loopCounter = 0; loopCounter < width; loopCounter++) {
        border += "#";
    }

    return border;
}

auto createLines(std::list<std::string> words) {
    list<std::string>::iterator pointer = words.begin();
    std::string string;
    int width;
    int extraSpaces;
    std::string space;
    std::string line;
    std::list<std::string> lines;
    std::string nextString;

    std::advance(pointer, 0);
    std::string largestString = *pointer;

    for (int loopCounter = 0; loopCounter < words.size(); loopCounter++) {
        std::advance(pointer, loopCounter);
        nextString = *pointer;
        if (largestString.size() < nextString.size()) {
            largestString = nextString;
        }
    }
    width = largestString.size() + 4;

    for (int loopCounter = 0; loopCounter < words.size(); loopCounter++) {
        pointer = words.begin();
        std::advance(pointer, loopCounter);
        string = *pointer;
        extraSpaces = width - string.size() - 3;
        for (int counter = 0; counter < extraSpaces; counter++) {
            space += " ";
        }
        line = "# " + string + space + "#";
        lines.push_back(line);
        space = "";
    }
    return lines;
}

int main() {
    // This function makes the list

    std::list<std::string> words;
    std::string quote = "";
    std::string border;
    std::list<std::string> finishedLines;
    int size = words.size();
    std::string quoteLines;

    std::cout << "This program creates a frame around a quote." << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Enter what would you like to write: ";
    getline(cin, quote);

    // process
    // spliting string
    // reference: https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
    stringstream ss(quote);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    border = createBorder(words);
    finishedLines = createLines(words);
    std::cout << border << std::endl;

    list<std::string>::iterator pointer = finishedLines.begin();
    for (int loopCounter = 0; loopCounter < finishedLines.size();
    loopCounter++) {
        std::advance(pointer, loopCounter);
        std::cout << *pointer << std::endl;
    }
    std::cout << border << std::endl;

    std::cout << "\nDone." << std::endl;
}

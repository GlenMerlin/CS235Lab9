#include <set>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

list<string> words;
set<string> uniqueWords;

void fileRead(const char* filename){
    string next_line;
        ifstream in(filename);
        while (getline(in, next_line)){
            istringstream iss(next_line);
            string word;
            while (iss >> word)
            {
                string nopunct = "";
                for (auto &c : word){
                    if (isalpha(c)){
                        nopunct += c;
                        transform(nopunct.begin(), nopunct.end(), nopunct.begin(), ::tolower);
                    }
                }
                if (nopunct != ""){
                    words.push_back(nopunct);
                    uniqueWords.insert(nopunct);
                }
            }
        }
}

int averageCount(list<string> words){
    stringstream ss;
    for (auto it = words.begin(); it != words.end(); it++)
    {
        ss << *it;
    }
    return ss.str().size()/words.size();
}

void mostLeastCommon(list<string> words){
    words.sort();
    string currentWord = "";
    string mostCommon = "";
    string leastCommon = "";
    int counter = 0;
    int largestCount = 1;
    int smallestCount = 0;
    for (auto it = words.begin(); it != words.end(); it++)
    {
        if (currentWord == ""){
            currentWord = *it;
            mostCommon = *it;
            leastCommon = *it;
            counter = 0;
        }
        if(currentWord == *it){
            counter++;
            if (counter > largestCount){
                mostCommon = currentWord;
                largestCount = counter;
            }
        }
        else if (currentWord != *it){
            
            if (counter > largestCount){
                mostCommon = currentWord;
                largestCount = counter;
            }
            else {
                if(smallestCount == 0){
                    smallestCount = counter;
                    leastCommon = currentWord;
                }
                else if (counter < smallestCount){
                    smallestCount = counter;
                    leastCommon = currentWord;
                }
            }
            currentWord = *it;
            counter= 1;
        }
        
    }

    cout << "The most common word is: '" << mostCommon << "' with " << largestCount << " occurrences" << endl;
    cout << "The least common word is: '" << leastCommon << "' with " << smallestCount << " occurrences" << endl << endl;
}

int main(int argc, char *argv[]){
    
    if (argv[1] == NULL){
        cerr << "To run this program please supply a valid text file like so: " << endl << "./wordcounter 1Nephi.txt" << endl;
        return 1;
    }
    int i = 1;
    while (argv[i] != NULL) {
        cout << argv[i] << endl << "---------------------------" << endl;
        
        fileRead(argv[i]);
        cout << "Unique words found: " << uniqueWords.size() << endl;
        cout << "Total words found: " << words.size() << endl << endl;
        
        int averageSize = averageCount(words);
        cout << "Average word length: " << averageSize << " characters" << endl << endl;

        mostLeastCommon(words);

        double time = words.size()/300;
        cout << "It would take the average college student aproximately " << time << " min ";
        cout << "or " << fixed << setprecision(2) << time/60 << " hrs to read" << endl << endl;

        time = words.size()/75;
        cout << "If you typed at 75WPM it would take you " << time << " min or about " << fixed << setprecision(2) << time/60 <<" hrs to type up this document" << endl << endl;
        words.erase(words.begin(), words.end());
        uniqueWords.erase(uniqueWords.begin(), uniqueWords.end());
        i++;

    }
    return 0;    
}


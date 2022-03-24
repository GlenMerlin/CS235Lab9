# Word Counter

This program accepts command line arguments and gives you statistics about a text file.

```bash
./wordcounter 1Nephi.txt
```
> it also allows multiple files by simply adding a space and the name of the next file you want to check.

It uses a set to store the unique words and a list to store the entire file.

# Each Function

```c++
void fileRead(const char* filename)
```
accepts the command line input for the name of the file it needs to open and populate the set and list with.

```c++
int averageCount(list<string> words)
```
takes the words array and counts the average word length of the document.

```c++
void mostLeastCommon(list<string> words)
```
sorts the words list and then finds the most and least commonly used words in the document.

```c++
int main(int argc, char *argv[])
```
takes in commandline arguments and `cout`s the information.
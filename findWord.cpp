///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            P5
// Files:            findWord.cpp echoArgs.cpp
// Semester:         CS368 Spring 2016
//
// Author:           Michael Simon
// Email:            masimon2@wisc.edu
// CS Login:         msimon
// Lecturer's Name:  Deppeler
// Lab Section:      (your lab section number)
//
//
//////////////////////////// 80 columns wide //////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/**
 * This reads in a word and the name of a file from the command line then
 * checks whether the file can be opened. If it can be opened, the file is
 * searched line by line for occurrences of a given word. For each line in 
 * which the given word occurs, the program will print out the entire line
 * preceded by the line number. It will then print out the total number of 
 * occurrences for that given word.
 *
 * <p>Bugs:
 *
 * @author Michael Simon
 */
int main(int argc, char * argv[]){
	
    //checks to see if the line was printed
	bool printed = false;
    
    //Current line number
	int lineNum = 1;
    
    //the number of times the key word was found
	int numFound = 0;
    
    //the current position on the line
	int currLinePos = 0;
    
    //The word that we are searching for
	string keyPhrase;
    
    //The current line that is being read from the file
	string currLine;

	//checks for proper number of inputs
	if(argc < 3){
		cerr << "Proper usage: findWord <word> <file>\n";
		cerr << "where\n";
		cerr << "  <word> is a sequence of non-whitespace characters\n";
		cerr << "  <file> is the file in which to search for the word\n";
		cerr << "example: findWord the test.txt" << endl;
		return 1;
	}

	//enter normal operation
	
	//import the keyPhrase and the file we are working with
	for(int i = 1; i < argc - 1; i++){
		keyPhrase.append(argv[i]);
		if(i < argc - 2)
			keyPhrase.append(" ");
	}
	ifstream infile(argv[argc - 1]); 
	
	// if the file opens, then print the initial statement, process the file
	// until EOF and print the current line and instance when the keyPhrase 
	// is found. Then print out the total amount of times the keyPhrase 
	// occured
	if(infile){
		cout << "Searching for \'" << keyPhrase
			 << "\' in file \'" << argv[argc - 1] << "\'\n";	
		while(!getline(infile, currLine).eof()){
			currLinePos = currLine.find(keyPhrase);
			while(currLinePos != -1){
				if(!printed){
					cout << lineNum << " : " << currLine << '\n';
					printed = true;
				}
				numFound++;
				if(currLinePos + keyPhrase.size() >= currLine.size())
					break;
				currLinePos = currLine.find(keyPhrase, currLinePos + keyPhrase.size());
				
			}
			lineNum++;
			printed = false;
		}
		cout << "# occurrences of \'" << keyPhrase << "\' = " 
			 << numFound << endl;
	}
	else{
		cerr << "File \'" << argv[argc - 1] << "\' could not be opened" << endl;
		return 2;
	}
	return 0;
}

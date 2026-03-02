// COMSC210 | Lab 15 | Gillian Rhett
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string FILENAME = "movies.txt";

class Movie {
    string writer;
    int year;
    string title;

    public:
        // setters and getters
        void setYear(int year) { // TODO data validation
            this->year = year;
        }
        void setWriter(string writer) { this->writer = writer; } // inline function to set the screenwriter's name
        void setTitle(string title) { this->title = title; } // inline function to set the movie title
        int getYear() { return year; } // inline function to get the movie's release year
        string getWriter() { return writer; } // inline function to get the screenwriter's name
        string getTitle() { return title; } // inline function to get the movie's title

        // other function
        void print() { // display the info about the movie
            cout << "Movie: " << title << endl;
            cout << "    Year released: " << year << endl;
            cout << "    Screenwriter: " << writer << endl;
        }
};

int main() {
    // read the movies from a file and store them in a vector
    ifstream moviesFile;
    // try to open the file
    try {
        moviesFile.open(FILENAME, ios::in);
        if(moviesFile.fail()) 
            throw invalid_argument("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }

    vector<Movie> movies; // empty vector to store movies from the file

    // read each line from the file and store the values in a Movie object
    string tempInput; // for getting each line from the file
    int tempInt; // for validating input
    bool validInput = false;
    while(!moviesFile.eof()) {
        Movie tempMovie; // this will store the values then a copy will be added to the vector
        
        moviesFile >> tempInput; // read the first line of this movie, the title
        tempMovie.setTitle(tempInput);
        
        moviesFile >> tempInput; // read the second line of this movie, the year
        try {
            tempInt = stoi(tempInput);
        }
        catch(const exception& e) {
            moviesFile.clear(); // skip this line
            tempInt = -1; // rather than ending the program, put this in to indicate there wasn't a valid year            
        }
        tempMovie.setYear(tempInt);

        moviesFile >> tempInput; // read the third line of this movie, the writer's name
        tempMovie.setWriter(tempInput);

        movies.push_back(tempMovie); // store a copy of this movie in the vector
    }
    
    // show the info for the movies stored in the vector
    for (Movie eachMovie : movies)
        eachMovie.print();    

    return 0;
}
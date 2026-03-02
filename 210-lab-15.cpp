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
    

    return 0;
}
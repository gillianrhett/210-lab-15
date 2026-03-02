// COMSC210 | Lab 15 | Gillian Rhett
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

const string FILENAME = "movies.txt";
const int EARLIEST = 1888; 
// the earliest known surviving movie was filmed in 1888, per Wikipedia

class Movie {
    string writer;
    int year;
    string title;

    public:
        // setters and getters
        void setYear(int year) {
            // check whether it is a valid year
            //   (checking whether it's an int happens when the file is read)
            time_t now = time(0);
            tm* local = localtime(&now);
            int currYear = local->tm_year + 1900;
            if (EARLIEST <= year && year <= currYear)
                this->year = year;
            else {
                cout << "Error: invalid year." << endl;
                this -> year = -1;
                // since input is from a file, rather than end the program, store an error value
            }
        }
        void setWriter(string writer) { this->writer = writer; } // inline function to set the screenwriter's name
        void setTitle(string title) { this->title = title; } // inline function to set the movie title
        int getYear() const { return year; } // inline function to get the movie's release year
        string getWriter() const { return writer; } // inline function to get the screenwriter's name
        string getTitle() const { return title; } // inline function to get the movie's title

        // other function
        void print() { // display the info about the movie
            cout << "Movie: " << title << endl;
            cout << "   Year released: " << year << endl;
            cout << "   Screenwriter: " << writer << endl;
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
        return -1; // end the program if it can't open the file
    }

    vector<Movie> movies; // empty vector to store movies from the file

    // read each line from the file and store the values in a Movie object
    string tempInput; // for getting each line from the file
    int tempInt; // for validating input
    while(!moviesFile.eof()) {
        Movie tempMovie; // this will store the values then a copy will be added to the vector
        
        getline(moviesFile, tempInput); // read the first line of this movie, the title
        tempMovie.setTitle(tempInput);
        
        getline(moviesFile, tempInput); // read the second line of this movie, the year
        try {
            tempInt = stoi(tempInput);
        }
        catch(const exception& e) {
            cout << "Error: invalid year." << endl;
            moviesFile.clear(); // skip this line
            tempInt = -1; // rather than ending the program, put -1 in to indicate there wasn't a valid year
        }
        tempMovie.setYear(tempInt);

        getline(moviesFile, tempInput); // read the third line of this movie, the writer's name
        tempMovie.setWriter(tempInput);

        movies.push_back(tempMovie); // store a copy of this movie in the vector
    }
    
    // show the info for the movies stored in the vector
    for (Movie eachMovie : movies)
        eachMovie.print();    

    return 0;
}
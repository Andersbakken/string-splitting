// http://stackoverflow.com/q/9378500/106471
#include <iostream>                                                              
#include <string>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

void split2(vector<string> &tokens, const string &str, char delim=' ') {
    stringstream ss(str); //convert string to stream
    string item;
    while(getline(ss, item, delim)) {
        tokens.push_back(item); //add token to vector
    }
}

int main() {
    string input_line;
    vector<string> spline;
    long count = 0;
    int sec, lps;
    time_t start = time(NULL);

    cin.sync_with_stdio(false); //disable synchronous IO

    while(cin) {
        getline(cin, input_line);
        spline.clear(); //empty the vector for the next line to parse

        split2(spline, input_line);

        count++;
    };

    count--; //subtract for final over-read
    sec = (int) time(NULL) - start;
    cerr << "C++   : Saw " << count << " lines in " << sec << " seconds." ;
    if (sec > 0) {
        lps = count / sec;
        cerr << "  Crunch speed: " << lps << endl;
    } else
        cerr << endl;
    return 0;
}

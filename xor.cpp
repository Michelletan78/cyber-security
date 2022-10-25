#include <iostream>
#include <fstream>
#include<sstream>
#include<iterator>
#include<vector>

using namespace std;
using StringTable = vector<vector<string>>;

StringTable readData(string const & path){
    ifstream ifs(path);
    if (!ifs){
        throw runtime_error("Error opening file.");
    }
    StringTable table;
    string line;
    while (getline(ifs,line)) {
        istringstream iss(line);
        table.emplace_back(istream_iterator<string>(iss),
                            istream_iterator<string>());

        }

    cout<<"Done Reading" << endl << endl;
    return table;
}

string Decrypt(string toDecrypt, char key){
    string output = toDecrypt;
    for (int i = 0; i < toDecrypt.size(); i++)
    output [i] = toDecrypt[i] ^ key;
    return output;

}

void doMain(){
    char abc[] = " ";
    string path = " ";
    StringTable table = readData(path);
}
vvvvvvvvvvvvvvvvvvvvvv

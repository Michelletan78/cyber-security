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
    char abc[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string path = " ";
    StringTable table = readData(path);

    for (unsigned long int i = 0; i < table.size(); i ++){
        string oldString = table.at(i).at(0);
        unsigned long int len = oldString.length();
        string newString;
        for (unsigned long int j = 0; j < len; j+=2) {

            string byte = oldString.substr(j,2);
            char chr = (char) (int) strtol(byte.c_str(), NULL, 16);
            newString.push_back(chr);
        }

        for (int j = 0; j <= ((26*2)+10); j++) {
            string out = Decrypt(newString, abc[j]);

            if (out.find_first_not_of ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_./ '\n ")==std::string :: npos) {
                cout << out << endl;
            }
        }
    }
}

int main ()
{
    try {
        doMain();
    }

    catch(exception const & e){
        cout << "Exception: " << e.what() << "\n";
        throw;
    }

    catch(...) {
        cout << " Exception: Unkown\n";
        throw;
    }

    return 0;

}

#include <vector>
#include <iostream>
#include <sstream>
#include <array>
#include <limits>

using namespace std;

class inputcontroller{
    public:
        inputcontroller();
        ~ inputcontroller();
        vector<string> getInputAsVector(string hostname);
        string checkInputExists(vector<string> input);
    private:
        void setInput();
        vector<string> inputs_;
};
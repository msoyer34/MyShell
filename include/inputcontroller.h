#include <vector>
#include <iostream>
#include <sstream>
#include <array>
#include <limits>

using namespace std;

class inputcontroller{
    public:
        inputcontroller();
        ~inputcontroller();
        vector<string> getInputAsVector(string hostname);
        string checkInputExists(vector<string> input);
    private:
        void setInput();
        vector<string> inputs_;
        array<vector<string>, 15> holded_inputs = {};
        int input_counter{0};
};
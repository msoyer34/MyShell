#include "inputcontroller.h"

/*
    Constructor of inputcontroller.
*/
inputcontroller::inputcontroller()
{

}
inputcontroller::~inputcontroller()
{

}
/*
    gets input.
*/
void inputcontroller::setInput()
{   
    inputs_.clear();
    string input;
    std::getline(cin, input);
    if(input == ""){
        inputs_.emplace_back(input);
        return;
    }
    istringstream input_divider(input);
    string s;
    while(std::getline(input_divider, s, ' ')){
        inputs_.emplace_back(s);
    }
}
/*
    gets input as string and returns input as vector.
*/
vector<string> inputcontroller::getInputAsVector(string hostname)
{
    std::cout << hostname << " >> ";
    setInput();
    return inputs_;
}

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
    if(input_counter == 15){
        input_counter = 0;
    }
    holded_inputs[input_counter++] = inputs_;
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
/*
    Check the input if it exist or not.
*/
string inputcontroller::checkInputExists(vector<string> input){
    for(auto holded_input : holded_inputs){
        if(input.size() == 2 && holded_input.size() == 1 && "\"" + holded_input[0] + "\""  == input[1]){
            return "Yes";
        }
        else if(input.size() == 3 &&  holded_input.size() == 2 && "\"" + holded_input[0] == input[1]){
            if(holded_input[1] + "\"" == input[2]){
                return "Yes";
            }
        }
        else if(input.size() == 5 && holded_input.size() == 4 && "\"" + holded_input[0] == input[1]){
            if(holded_input[1] == input[2] && holded_input[3] + "\"" == input[4]){
                return "Yes";
            }
        }
        else
            continue;
    }
    return "No";
}

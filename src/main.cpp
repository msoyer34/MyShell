#include "operationsservice.h"
#include "inputcontroller.h"

/*
    Main Shell implementation. Get Arguments and make operations.
*/
int main(int argc, char** argv)
{
    std::shared_ptr<inputcontroller> input_controller = std::make_shared<inputcontroller>();
    std::shared_ptr<operationsservice> operations_service = std::make_shared<operationsservice>();
    //gets user name to set to the shell username.
    auto pc_user_name = std::getenv("USER");
    std::cout << "!----- Hello,  Welcome " << pc_user_name  << " To The Shell -----!" << std::endl;
    auto inputs = input_controller->getInputAsVector(pc_user_name);
    
    //Make Operations unless input is exit.
    while (inputs.front() != "exit")
    {
        if(inputs.front() == "listdir")
        {   
            operations_service->listFilesInDirectory();
        }
        else if(inputs.front() == "mycomputername")
        {
            std::cout << "Computer name is: " << operations_service->returnHostName() << std::endl;

        }
        else if(inputs.front() == "whatismyip")
        {
            std::cout << operations_service->returnIPOfMachine() << std::endl;
            
        }
        else if(inputs.front() == "printfile")
        {
            if(inputs.size() == 2){     
                operations_service->printFileToTerminal(inputs[1]); 
            }
            else if(inputs.size() == 4)
            {
                operations_service->copyFileToLocation(inputs[1], inputs[3]);
            }
            else
            {
                std::cout << "wrong input" << std::endl;
            }
        }
        else if(inputs.front() == "hellotext")
        {
            if(!fork())
            {
                system("gedit");
            }
        }
        else if(inputs.front() == "dididothat")
        {
            cout << input_controller->checkInputExists(inputs) << endl;
        }
        else{
            std::cout << "wrong input" << std::endl;
        }
        inputs = input_controller->getInputAsVector(pc_user_name);
    } 
    std::cout << "Good Bye" << std::endl;
    return 0;
}

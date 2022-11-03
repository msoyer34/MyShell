#include "inputcontroller.h"
#include "commands.h"

/*
    Main Shell implementation. Get Arguments and make operations.
*/
int main(int argc, char** argv)
{
    std::shared_ptr<inputcontroller> input_controller = std::make_shared<inputcontroller>();
    std::shared_ptr<operationsservice> operations_service = std::make_shared<operationsservice>();
    std::shared_ptr<CommandInitializer> initializer = std::make_shared<CommandInitializer>();
    //gets user name to set to the shell username.
    auto pc_user_name = std::getenv("USER");
    std::cout << "!----- Hello,  Welcome " << pc_user_name  << " To The Shell -----!" << std::endl;
    auto operations = initializer->getOperations();
    //Make Operations unless input is exit.
    do
    {
        try{
            auto inputs = input_controller->getInputAsVector(pc_user_name);
            ICommand* operation = operations.at(inputs.front()); //throws exception if command is not defined.
            operation->Execute(operations_service, inputs);

        }
        catch(std::out_of_range ex)
        {
            std::cout << "Command is not defined" << std::endl;
        }

    }
    while(true);
}

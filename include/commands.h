#include <iostream>
#include <map>
#include "dirent.h"
#include <vector>
#include "operationsservice.h"

class ICommand
{
public:
    virtual ~ICommand()
    {
    }
    virtual void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs) = 0;

};

class Listdir : public ICommand
{
public: 
    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs) override
    {
        operations_service->listFilesInDirectory();
        operations_service->setInputToHistory(inputs);
    }
};

class MyComputerName : public ICommand
{
public:

    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs) override
    {
        operations_service->returnHostName();
        operations_service->setInputToHistory(inputs);
    }
};

class WhatIsMyIp : public ICommand
{
public:
    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs = {}) override
    {
        operations_service->returnIPOfMachine();
        operations_service->setInputToHistory(inputs);
    }
};

class PrintFile : public ICommand
{
public:
    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs = {}) override
    {
        if(inputs.size() == 2){
            operations_service->printFileToTerminal(inputs[1]);
        }
        else if(inputs.size() == 4){
            if(inputs[2] != ">"){
                std::cout  << "Wrong Command usage" << std::endl;
                return;
            }
            operations_service->copyFileToLocation(inputs[1], inputs[3]);
        }
        else
            std::cout  << "Wrong Command usage" << std::endl;
            return;
        operations_service->setInputToHistory(inputs);
    }
};

class HelloText : public ICommand
{
public:
    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs) override
    {
        system("gedit");
        operations_service->setInputToHistory(inputs);
    }
};

class DidIDoThat : public ICommand
{
public:
    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs) override
    {
        operations_service->checkInputExists(inputs);
        operations_service->setInputToHistory(inputs);
    }
};

class Exit : public ICommand
{
public:
    void Execute(std::shared_ptr<operationsservice> operations_service, std::vector<std::string> inputs ) override
    {
        std::cout << "Good Bye" << std::endl;
        exit(0);  
    }
};

class CommandInitializer{
public:
    CommandInitializer()
    {
        Listdir* listdir = new Listdir;
        MyComputerName* mycomputername = new MyComputerName;
        WhatIsMyIp* whatismyip = new WhatIsMyIp;
        HelloText* hellotext = new HelloText;
        PrintFile* printfile = new PrintFile;
        DidIDoThat* dididothat = new DidIDoThat;
        Exit* exit = new Exit;

        operations_.insert_or_assign("listdir", listdir);
        operations_.insert_or_assign("mycomputername", mycomputername);
        operations_.insert_or_assign("whatismyip", whatismyip);
        operations_.insert_or_assign("hellotext", hellotext);
        operations_.insert_or_assign("printfile", printfile);
        operations_.insert_or_assign("dididothat", dididothat);
        operations_.insert_or_assign("exit", exit);
    }

    std::map<std::string, ICommand*> getOperations(){
        return operations_;
    }
private:

    std::map<std::string, ICommand*> operations_;


};

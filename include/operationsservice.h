#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "dirent.h"
#include <paths.h>
#include <vector>
#include <string>
#include <array>

class operationsservice{
    public:
        operationsservice();
        ~ operationsservice();

         std::string returnIPOfMachine();
         std::string returnHostName();
         void listFilesInDirectory();
         void printFileToTerminal(std::string filepath);
         void copyFileToLocation(std::string incoming_filepath, std::string out_filepath);
         void setInputToHistory(std::vector<std::string> inputs);
         void checkInputExists(std::vector<std::string> inputs);
         void getInputHistory();
         
    private:
        char host[256];
        char *IP;
        struct hostent *host_entry;
        int hostname;
        bool checkHostEntry(struct hostent * hostentry);
        bool formatIP(char *IPbuffer);
        bool checkHostName(int hostname);
        std::array<std::vector<std::string>, 15> holded_inputs_ = {};
        int input_counter_{0};
};
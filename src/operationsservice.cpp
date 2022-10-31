#include "operationsservice.h"

/*
    Constructor of operationsservice.
*/
operationsservice::operationsservice(){
    hostname = gethostname(host, sizeof(host)); //find the host name
    host_entry = gethostbyname(host); //find host information
}
operationsservice::~operationsservice(){

}
bool operationsservice::checkHostName(int hostname) { //Check hostname exists.
   if (hostname == -1) {
    return false;
   }
   return true;
}

bool operationsservice::checkHostEntry(struct hostent * hostentry) { //find host info from host name.
    if (hostentry == NULL){
        return false;
    }
    return true;
}

bool operationsservice::formatIP(char *IPbuffer) { //check ip is in the right format.
    if (NULL == IPbuffer) {
        return false;
    }
    return true;
}

/*
    This function returns hostname of the computer.
*/
std::string operationsservice::returnHostName()
{
    if(!checkHostName(hostname)){
        std::cout << "Host name not found." << std::endl;
    }
    host_entry = gethostbyname(host); //find host information
    if(!checkHostEntry(host_entry)){
        std::cout << "Host entry of this name is not found." << std::endl;
    }
    return host_entry->h_name;
}

/*
    return ip of the host
*/
std::string operationsservice::returnIPOfMachine(){
    if(!checkHostName(hostname)){
        std::cout << "Host name not found." << std::endl;
    }
    if(!checkHostEntry(host_entry)){
        std::cout << "Host entry of this name is not found." << std::endl;
    }
    IP = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));
    return IP;
}

/*
    Print lines with enter press.
*/
void operationsservice::printFileToTerminal(std::string filepath)
{
    
    std::filesystem::path path_input(filepath);
    std::fstream ifs{path_input};
    if(ifs.is_open()){
        std::string data;
        while(getline(ifs, data)){ //read data from file object and put it into string.
            std::cout << data;
            std::cin.get();
        }
        ifs.close();
    }
}
/*
    list all files in the current directory
*/
void operationsservice::listFilesInDirectory()
{
    if(const char* env_p = std::getenv("PWD")) //get environment variable for current directory
    { 
        DIR* readed_dir = opendir(env_p); //open the to be readed dir
        struct dirent *ent; //
        while((ent = readdir(readed_dir)) != NULL)
        {   
            if(ent->d_name[0] != '.')
            {
                std::cout << ent->d_name << std::endl;
            }
        }
    } 
}
/*
    open file incoming_filepath and copy it to location out_filepath another line by line
*/
void operationsservice::copyFileToLocation(std::string incoming_filepath, std::string out_filepath)
{
    std::ifstream in_file(incoming_filepath,std::ios::in); 
    std::ofstream out_file(out_filepath,std::ios::out | std::ios::app);

    if (in_file.is_open())
    {
        std::string line;
        getline (in_file,line);
        while (in_file.good())
        {
            out_file << line << std::endl;
            getline (in_file,line);          
        }
        in_file.close();
        out_file.close();
    }
}
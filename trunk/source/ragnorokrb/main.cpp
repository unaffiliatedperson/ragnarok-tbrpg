#include<iostream>
#include "boost/multi_array.hpp" //for entity inventory
#include "common_inclusions.h"

int main(void) {

    file_io * File = new file_io("test.txt");                   //creates object and handles save file "test.txt"

    File->file_load();                                          //first load file to use
    File->file_find("player", "", '0');                         //find the appropriate line
    File->file_write("player", '!', 'y', 0, 0, 0, 0, 0, 0, 0);  //zero out stats
    File->file_write("player", 'a', 'n', 255);                  //sets attack to 255
    std::cout << "Values At 0: " << File->values.at(1);         //returns location
    File->values.clear();                                       //clears stats for next usage
    File->file_load();                                          //loads another instance of test.txt
//    entity * Entity("hello");
    delete File;                                                //destructs the object

return 0;

}

#include "scan.h"
#include "scan.cpp"
#include <fstream>
#include <iostream>
#include <stdio.h>

int main (int argc, char** argv){

    
    remove("movedata.log");    
    Scan *S = new Scan();
    std::ofstream outfile;

    outfile.open("movedata.log", std::ofstream::out | std::ofstream::app);

    outfile << "NODE 0 0 0 0 0 0" << std::endl;

    S->perform_scan(outfile);
    
    int x,y,z;
    
    std::cout << "Input Distance: ";
    while (std::cin >> x >> y >> z){

        if (x == -1000) break;

        outfile << "NODE " << x << " " << y << " " << z << " 0 0 0" << std::endl;
        S->perform_scan(outfile);

        std::cout << "Input Distance: ";
    }

    outfile.close();

    return 0;    



}

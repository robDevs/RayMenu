#include "helpers.h"

#include <cstdio>
#include <fstream>
#include <iostream>

bool file_exists(const std::string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void split_line(std::vector<std::string> *args, std::string line) {
    int split = line.find(" ");
    if(split != std::string::npos) {
        std::string new_val = line.substr(0, split);
        args->push_back(new_val);
        new_val = line.substr(split+1, line.length());
        args->push_back(new_val);
    }
}

void read_config(const std::string path, Config *config) {
    if(file_exists(path)) {
        std::string line;
        std::ifstream file (path.c_str());
        if(file.is_open()) {
            while(getline(file, line)) {
                if(line[0] != '#') {
                    std::vector<std::string> args;
                    split_line(&args, line);
                    std::cout << args[0] << " " << args[1] << std::endl;
                    if(args[0].find("win_x") != std::string::npos) {
                        config->win_x = std::stoi(args[1]);
                        std::cout << "win_x= " << config->win_x;
                    }
                    if(args[0].find("win_y") != std::string::npos) {
                        config->win_y = std::stoi(args[1]);
                    }
                    if(args[0].find("win_w") != std::string::npos) {
                        config->win_w = std::stoi(args[1]);
                    }
                    if(args[0].find("win_h") != std::string::npos) {
                        config->win_h = std::stoi(args[1]);
                    }
                }
            }
        }
    }
}
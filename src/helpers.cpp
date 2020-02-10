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

Config read_config(const std::string path) {
    Config new_config;
    new_config.win_x = -1;
    new_config.win_y = -1;
    new_config.win_w = -1;
    new_config.win_h = -1;
    new_config.bg_r = 255;
    new_config.bg_g = 255;
    new_config.bg_b = 255;
    new_config.bg_b = 255;
    new_config.i3 = false;
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
                        new_config.win_x = std::stoi(args[1]);
                    }
                    if(args[0].find("win_y") != std::string::npos) {
                        new_config.win_y = std::stoi(args[1]);
                    }
                    if(args[0].find("win_w") != std::string::npos) {
                        new_config.win_w = std::stoi(args[1]);
                    }
                    if(args[0].find("win_h") != std::string::npos) {
                        new_config.win_h = std::stoi(args[1]);
                    }
                    if(args[0].find("i3") != std::string::npos) {
                        new_config.i3 = std::stoi(args[1]);
                    }
                    if(args[0].find("bg_r") != std::string::npos) {
                        new_config.bg_r = std::stoi(args[1]);
                    }
                    if(args[0].find("bg_g") != std::string::npos) {
                        new_config.bg_g = std::stoi(args[1]);
                    }
                    if(args[0].find("bg_b") != std::string::npos) {
                        new_config.bg_b = std::stoi(args[1]);
                    }
                    if(args[0].find("bg_a") != std::string::npos) {
                        new_config.bg_a = std::stoi(args[1]);
                    }
                    if(args[0].find("text_r") != std::string::npos) {
                        new_config.text_r = std::stoi(args[1]);
                    }
                    if(args[0].find("text_g") != std::string::npos) {
                        new_config.text_g = std::stoi(args[1]);
                    }
                    if(args[0].find("text_b") != std::string::npos) {
                        new_config.text_b = std::stoi(args[1]);
                    }
                    if(args[0].find("text_a") != std::string::npos) {
                        new_config.text_a = std::stoi(args[1]);
                    }
                    if(args[0].find("bar_r") != std::string::npos) {
                        new_config.bar_r = std::stoi(args[1]);
                    }
                    if(args[0].find("bar_g") != std::string::npos) {
                        new_config.bar_g = std::stoi(args[1]);
                    }
                    if(args[0].find("bar_b") != std::string::npos) {
                        new_config.bar_b = std::stoi(args[1]);
                    }
                    if(args[0].find("bar_a") != std::string::npos) {
                        new_config.bar_a = std::stoi(args[1]);
                    }
                }
            }
        }
    }
    return new_config;
}
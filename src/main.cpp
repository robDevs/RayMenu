#include "raylib.h"
#include "term.h"
#include "binarySearchDeluxe.h"
#include "textBox.h"
#include "helpers.h"
#include "config.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <dirent.h>


void readFolder(std::string path, std::vector<std::string> *list) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path.c_str());
    if (dir != NULL){
        while (entry = readdir(dir)){
        //printf("%s\n",entry->d_name);
        std::string filename = entry->d_name;
        if(filename.length() > 1)
            list->push_back(filename);
        // std::cout << epdf->d_name << std::endl;
   }
}
closedir(dir);
}

bool termComp(Term i, Term j) {return i.compareTo(j) == -1;}
bool stringComp(std::string i, std::string j) {
    std::string string1 = i;
    std::string string2 = j;
    for(int i = 0; i < string1.length(); i++) {
        string1[i] = tolower(string1[i]);
    }
    for(int i = 0; i < string2.length(); i++) {
        string2[i] = tolower(string2[i]);
    }
    return string1.compare(string2) > 0;
    }

int main(int argc, char* argv[])
{
    Config config;
    read_config("/home/rob/.config/raymenu.conf", &config);
    // Initialization
    //-------------------------------------------------------------------------------------

    
    const int screenWidth = config.win_w;
    const int screenHeight = config.win_h;
    
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TRANSPARENT);
    InitWindow(screenWidth, screenHeight, "RayMenu");

    //while(!IsWindowReady()) {}
    //SetWindowPosition(config.win_x, config.win_y);
    if(config.win_x != -1 && config.win_y != -1) 
        SetWindowPosition(config.win_x, config.win_y);

    std::vector<std::string> progs;

    readFolder("/usr/bin/", &progs);

    std::stable_sort(progs.begin(), progs.end(), stringComp);

    std::vector<Term> terms;

    int count = 0;
    while(!progs.empty()) {
        int pos = progs.size() - 1;
        if(pos < 0) break;
        Term newTerm(progs[pos], count);
        terms.push_back(newTerm);
        count++;
        progs.pop_back();
    }

    //std::sort(terms.begin(), terms.end(), termComp);

    int termSize = terms.size() - 1;
    for(int i = 0; i < termSize; i++) {
        //std::cout << terms[i].toString() << std::endl;
    }

    BinarySearchDeluxe search;

    textBox input(10, 10, 100, 40, 40);
    input.setMessage(" ");

    SetTargetFPS(60);
    std::string input_query;
    std::string old_query;
    
    bool done = false;

    int first = 0; 
    int last = 0;

    int pos = 0;
    std::string command;

    while (!WindowShouldClose() && !done)
    {
        //update section 
        if(IsKeyReleased(KEY_ENTER)) {
            if(first == -1 || last == -1) command = input_query;
            else command = terms[first+pos].toString() + " &";
            done = true;
        }
        if(IsKeyReleased(KEY_UP)){
            pos--;
            if(pos > last-first+1) pos = last-first+1;
            if(pos > 10) pos = 10;
        }

        if(IsKeyReleased(KEY_DOWN)) {
            pos++;
            if(pos > last-first+1) pos = 0;
            if(pos > 10) pos = 0;
        }
        if(last-first+1 == 1) pos = 0;
        
        if(pos < 0) pos = last-first+1;
        
        input.update();

        old_query = input_query;
        input_query = input.message;
        if(old_query.compare(input_query) != 0) {
            pos = 0;
        }

        first = search.firstIndexOf(terms, input_query);
        last = search.lastIndexOf(terms, input_query);

        //end update section. 
        
        //draw section. 
        BeginDrawing();

            ClearBackground((Color) {73, 87, 92, 100});
            input.draw();

            std::string first_index = "First index of query = " + std::to_string(first);
            std::string last_index = "last index of query = " + std::to_string(last);

            if(first != -1 && last != -1){
                    for(int i = 0; i < last-first+1; i++) {
                    if(i > 10) break;
                    if(pos == i) DrawRectangle(0, 50+i*20-2, screenWidth, 24, BLACK);
                    DrawText(terms[first+i].toString().c_str(), 10, 50+i*20, 20, WHITE);
                }
            }



        EndDrawing();

        //end draw section. 
    }

    //Close the window. 
    //free things here. 
    CloseWindow(); 
    if(done) std::system("i3-msg workspace 3;");
    //if(done) std::system("i3-msg workspace 3; layout tabbed; exec && google-chrome-stable -s");
    if(done) std::system(command.c_str());

    return 0;
}
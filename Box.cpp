#include "shut_the_box.h"

Box::Box(int doorAmnt){
    for (int i=0; i<doorAmnt; i++){
        doors.push_back("|" + std::to_string(i+1) + "|");
        openDoors.push_back(i+1);
    }
    size = doorAmnt;
}

void Box::close(int door){
    doors[door-1] = ("[" + std::to_string(door) + "]");
    auto it = std::find(openDoors.begin(), openDoors.end(), door);
    if (it != openDoors.end()) {
        openDoors.erase(it);
    }
}

void Box::print() const{
    for (int i = 0; i<doors.size(); i++){
        std::cout << doors[i] << " ";
    }
    std::cout << "\n";
}

bool Box::isDoorOpen(int door) const{
        auto it = find(openDoors.begin(), openDoors.end(), door);
        if (it != openDoors.end())
            return true;
        else return false;
}
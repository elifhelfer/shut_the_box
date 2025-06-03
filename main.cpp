#include "shut_the_box.h"

int main(){

    std::cout << Dice::roll() << "\n";

    Box box = Box(7);

    box.print();

    box.close(5);

    box.print();

    return 0;
}
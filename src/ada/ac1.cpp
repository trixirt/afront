#include "ada/driver.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 2) {
    Ada::Driver driver;
    if (!driver.parse(argv[1])) {
      std::cout << driver.result() << std::endl;
    }
  }
}

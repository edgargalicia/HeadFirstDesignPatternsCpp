#include "machine.hpp"

int main(int argc, char *argv[]) {
  GumballMachine *gumballMachine = new GumballMachine(5);

  gumballMachine->printStatus();

  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();

  gumballMachine->printStatus();

  gumballMachine->insertQuarter();
  gumballMachine->ejectQuarter();
  gumballMachine->turnCrank();

  gumballMachine->printStatus();

  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  gumballMachine->ejectQuarter();

  gumballMachine->printStatus();

  gumballMachine->insertQuarter();
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();

  gumballMachine->printStatus();

  return 0;
}

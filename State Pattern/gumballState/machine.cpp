#include "machine.hpp"
#include <iostream>

GumballMachine::GumballMachine(int numberGumballs)
    : count{numberGumballs}, noQuarterState{new NoQuarterState(this)},
      hasQuarterState{new HasQuarterState(this)},
      soldState{new SoldState(this)}, soldOutState{new SoldOutState(this)} {
  if (numberGumballs > 0) {
    state = noQuarterState;
  } else {
    state = soldOutState;
  }
}
GumballMachine::~GumballMachine() {
  delete noQuarterState;
  delete hasQuarterState;
  delete soldState;
  delete soldOutState;
  delete state;
}
void GumballMachine::insertQuarter() { state->insertQuarter(); }
void GumballMachine::ejectQuarter() { state->ejectQuarter(); }
void GumballMachine::turnCrank() {
  state->turnCrank();
  state->dispense();
}
void GumballMachine::setState(State *s) { state = s; }
void GumballMachine::releaseBall() {
  std::cout << "A gumball comes rolling out the slot...\n";
  if (count != 0) {
    --count;
  }
}

State *GumballMachine::getHasQuarterState() const { return hasQuarterState; }
State *GumballMachine::getNoQuarterState() const { return noQuarterState; }
State *GumballMachine::getSoldState() const { return soldState; }
State *GumballMachine::getSoldOutState() const { return soldOutState; }
int GumballMachine::getCount() const { return count; }
void GumballMachine::printStatus() {
  std::cout << "\nMighty Gumball, Inc.\n";
  std::cout << "C++-enabled Standing Gumball Model #2025\n";
  std::cout << "Inventory: " << count << " gumballs\n";
  if (count > 0) {
    std::cout << "Machine is waiting for a quarter\n";
  } else {
    std::cout << "Machine is sold out\n";
  }
  std::cout << std::endl;
}

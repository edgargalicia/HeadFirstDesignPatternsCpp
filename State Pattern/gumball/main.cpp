#include <iostream>

class GumballMachine {
public:
  static const int SOLD_OUT = 0;
  static const int NO_QUARTER = 1;
  static const int HAS_QUARTER = 2;
  static const int SOLD = 3;
  // NOTE: This achieves the same result as above
  // enum State { SOLD_OUT, NO_QUARTER, HAS_QUARTER, SOLD }

  int state = SOLD_OUT;
  int count = 0;

  explicit GumballMachine(int c) : count{c} {
    if (count > 0) {
      state = NO_QUARTER;
    }
  }

  void insertQuarter() {
    if (state == HAS_QUARTER) {
      std::cout << "You can't insert another quarter\n";
    } else if (state == SOLD_OUT) {
      std::cout << "You can't insert a quarter, the machine is sold out\n";
    } else if (state == SOLD) {
      std::cout << "Please wait, we're already giving you a gumball\n";
    } else if (state == NO_QUARTER) {
      state = HAS_QUARTER;
      std::cout << "You inserted a quarter\n";
    }
  }

  void ejectQuarter() {
    if (state == HAS_QUARTER) {
      std::cout << "Quarter returned\n";
      state = NO_QUARTER;
    } else if (state == NO_QUARTER) {
      std::cout << "You haven't inserted a quarter\n";
    } else if (state == SOLD) {
      std::cout << "Sorry, you already turned the crank\n";
    } else if (state == SOLD_OUT) {
      std::cout << "You can't eject, you haven't inserted a quarter yet\n";
    }
  }

  void turnCrank() {
    if (state == SOLD) {
      std::cout << "Turning twice doesn't get you another gumball\n";
    } else if (state == NO_QUARTER) {
      std::cout << "You turned but there's no quarter\n";
    } else if (state == SOLD_OUT) {
      std::cout << "You turned, but there are no gumballs\n";
    } else if (state == HAS_QUARTER) {
      std::cout << "You turned...\n";
      state = SOLD;
      dispense();
    }
  }

  void dispense() {
    if (state == SOLD) {
      std::cout << "A gumball comes rolling out the slot\n";
      --count;
      if (count == 0) {
        std::cout << "Oops, out of gumballs!\n";
        state = SOLD_OUT;
      } else {
        state = NO_QUARTER;
      }
    } else if (state == NO_QUARTER) {
      std::cout << "You need to pay first\n";
    } else if (state == SOLD_OUT) {
      std::cout << "No gumball dispensed\n";
    } else if (state == HAS_QUARTER) {
      std::cout << "No gumball dispensed\n";
    }
  }

  void printStatus() {
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
};

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

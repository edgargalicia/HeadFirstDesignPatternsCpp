#include "machine.hpp"
#include <iostream>

void NoQuarterState::insertQuarter() {
  std::cout << "You inserted a quarter\n";
  gumballMachine->setState(gumballMachine->getHasQuarterState());
}
void NoQuarterState::ejectQuarter() {
  std::cout << "You haven't inserted a quarter\n";
}
void NoQuarterState::turnCrank() {
  std::cout << "You turned but there's no quarter\n";
}
void NoQuarterState::dispense() { std::cout << "You need to pay first\n"; }

void HasQuarterState::insertQuarter() {
  std::cout << "You can't insert another quarter\n";
}
void HasQuarterState::ejectQuarter() {
  std::cout << "Quarter returned\n";
  gumballMachine->setState(gumballMachine->getNoQuarterState());
}
void HasQuarterState::turnCrank() {
  std::cout << "You turned...\n";

  std::uniform_int_distribution<int> dist(0, 9);
  int winner = dist(randomWinner);
  if ((winner == 0) && (gumballMachine->getCount() > 1)) {
    gumballMachine->setState(gumballMachine->getWinnerState());
  } else {
    gumballMachine->setState(gumballMachine->getSoldState());
  }
}
void HasQuarterState::dispense() { std::cout << "No gumball dispensed\n"; }

void SoldState::insertQuarter() {
  std::cout << "Please wait, we're already giving you a gumball\n";
}
void SoldState::ejectQuarter() {
  std::cout << "Sorry, you already turned the crank\n";
}
void SoldState::turnCrank() {
  std::cout << "Turning twice doesn't get you another gumball\n";
}
void SoldState::dispense() {
  gumballMachine->releaseBall();
  if (gumballMachine->getCount() > 0) {
    gumballMachine->setState(gumballMachine->getNoQuarterState());
  } else {
    std::cout << "Oops, out of gumballs!\n";
    gumballMachine->setState(gumballMachine->getSoldOutState());
  }
}

void SoldOutState::insertQuarter() {
  std::cout << "You can't insert a quarter, the machine is sold out\n";
}
void SoldOutState::ejectQuarter() {
  std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}
void SoldOutState::turnCrank() {
  std::cout << "You turned, but there are no gumballs\n";
}
void SoldOutState::dispense() { std::cout << "No gumball dispensed\n"; }

void WinnerState::insertQuarter() {
  std::cout << "Please wait, we're already giving you a gumball\n";
}
void WinnerState::ejectQuarter() {
  std::cout << "Please wait, we're already giving you a gumball\n";
}
void WinnerState::turnCrank() {
  std::cout << "Turning twice doesn't get you another gumball\n";
}
void WinnerState::dispense() {
  std::cout << "YOU'RE A WINNER! You get two gumballs for your quarter\n";
  gumballMachine->releaseBall();
  if (gumballMachine->getCount() == 0) {
    gumballMachine->setState(gumballMachine->getSoldOutState());
  } else {
    gumballMachine->releaseBall();
    if (gumballMachine->getCount() > 0) {
      gumballMachine->setState(gumballMachine->getNoQuarterState());
    } else {
      std::cout << "Oops, out of gumballs!\n";
      gumballMachine->setState(gumballMachine->getSoldOutState());
    }
  }
}

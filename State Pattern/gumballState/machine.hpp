#include "state.hpp"

class GumballMachine {
private:
  State *noQuarterState{nullptr};
  State *hasQuarterState{nullptr};
  State *soldState{nullptr};
  State *soldOutState{nullptr};

  State *state{nullptr};
  int count{0};

public:
  GumballMachine();
  explicit GumballMachine(int numberGumballs);
  ~GumballMachine();

  void insertQuarter();
  void ejectQuarter();
  void turnCrank();
  void dispense();
  void setState(State *s);
  void releaseBall();

  State *getHasQuarterState() const;
  State *getNoQuarterState() const;
  State *getSoldState() const;
  State *getSoldOutState() const;
  int getCount() const;
  void printStatus();
};


class State {
public:
  virtual void insertQuarter() = 0;
  virtual void ejectQuarter() = 0;
  virtual void turnCrank() = 0;
  virtual void dispense() = 0;
  virtual ~State() = default;
};

class GumballMachine;

class NoQuarterState : public State {
private:
  GumballMachine *gumballMachine;

public:
  explicit NoQuarterState(GumballMachine *gm) : gumballMachine{gm} {}

  void insertQuarter() override;
  void ejectQuarter() override;
  void turnCrank() override;
  void dispense() override;
};

class HasQuarterState : public State {
private:
  GumballMachine *gumballMachine;

public:
  explicit HasQuarterState(GumballMachine *gm) : gumballMachine{gm} {}

  void insertQuarter() override;
  void ejectQuarter() override;
  void turnCrank() override;
  void dispense() override;
};

class SoldState : public State {
private:
  GumballMachine *gumballMachine;

public:
  explicit SoldState(GumballMachine *gm) : gumballMachine{gm} {}

  void insertQuarter() override;
  void ejectQuarter() override;
  void turnCrank() override;
  void dispense() override;
};

class SoldOutState : public State {
private:
  GumballMachine *gumballMachine;

public:
  explicit SoldOutState(GumballMachine *gm) : gumballMachine{gm} {}

  void insertQuarter() override;
  void ejectQuarter() override;
  void turnCrank() override;
  void dispense() override;
};

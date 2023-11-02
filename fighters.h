#include<string>
#ifndef FIGHTERS_H_include
#define FIGHTERS_H

class Fighter
{

#ifdef TESTS
public:
#else
protected:  //only children's classes can access
    //Only the object itself can be private
#endif
    int healthPoints = 100;
    int offensePoints;
    int defensePoints;
    std::string description;
public:
    bool dead = false;
    std::string name;
    Fighter(const std::string&);    //constructor
    virtual ~Fighter() {};           //destructor
    virtual double specialAttack() = 0; // virtual means ...
    virtual double specialDefense() = 0;//...is defined in subclass
    void attack(Fighter&);
    const void showStats();
};

class Warrior : public Fighter
{
public:
    Warrior(const std::string&);    //constructor
    virtual ~Warrior() {};           //destructor
    double specialAttack();
    double specialDefense();
};

class Ninja : public Fighter
{
public:
    Ninja(const std::string&);  //constructor
    virtual ~Ninja() {};         //destructor
    double specialAttack();
    double specialDefense();
};

//2 further fighter types
class ChuckNorris : public Fighter
{
public:
    ChuckNorris(const std::string&);    //constructor
    virtual ~ChuckNorris() {};           //destructor
    double specialAttack();
    double specialDefense();
};

class Mage : public Fighter
{
public:
    Mage(const std::string&);   //constructor
    virtual ~Mage() {};          //destructor
    double specialAttack();
    double specialDefense();
};



void create(Fighter* []);
void fight(Fighter* [], int, int);
void pick(Fighter* []);
void lastManStanding(Fighter* []);
void view(Fighter* []);
#endif
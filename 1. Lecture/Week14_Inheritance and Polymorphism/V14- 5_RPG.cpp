#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// ===========================================================================
// Character Part
// ===========================================================================
class Character{
  protected:
    static const int EXP_LV = 100;
    string name;
    int level;
    int exp;
    int power;
    int knowledge;
    int luck;
    void levelUp(int pInc, int kInc, int lInc);
  public:
    Character(string n, int lv, int po, int kn, int lu);
    virtual void beatMonster(int exp) = 0;
    virtual void print();
    string getName();
};

Character::Character(string n, int lv, int po, int kn, int lu) : name(n), level(lv), exp( pow(lv - 1, 2) * EXP_LV ), power(po), knowledge(kn), luck(lu) {}

void Character::print(){
    cout<< this->name 
        << ": Level " << this->level << " (" << this->exp << "/" << pow(this->level, 2) * EXP_LV
        << "), " << this->power << "-" << this->knowledge << "-" << this->luck << "\n";
}

void Character::levelUp(int pInc, int kInc, int lInc){
    this->level++;
    this->power += pInc;
    this->knowledge += kInc;
    this->luck += lInc;    
}

string Character::getName(){
    return this->name;
}
// ===========================================================================
// Character Part end
// ===========================================================================

//Warrior
class Warrior : public Character{
  private:
    static const int PO_LV = 10;
    static const int KN_LV = 5;
    static const int LU_LV = 5;
  public:
    Warrior(string n) : Character(n, 1, PO_LV, KN_LV, LU_LV) {}
    Warrior(string n, int lv) : Character(n, lv, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}
    void print(){
        cout << "Warrior ";
        Character::print();
    }  
    void beatMonster(int exp){
        this->exp += exp;
        while( this->exp >= pow(this->level, 2) * EXP_LV )
            this->levelUp(PO_LV, KN_LV, LU_LV);
    }
};

//Wizard
class Wizard : public Character{
  private:
    static const int PO_LV = 4;
    static const int KN_LV = 9;
    static const int LU_LV = 7;
  public:
    Wizard(string n) : Character(n, 1, PO_LV, KN_LV, LU_LV) {}
    Wizard(string n, int lv) : Character(n, lv, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}
    void print(){
        cout << "Wizard ";
        Character::print();
    }  
    void beatMonster(int exp){
        this->exp += exp;
        while(this->exp >= pow(this->level, 2) * EXP_LV)
            this->levelUp(PO_LV, KN_LV, LU_LV);
    }
};



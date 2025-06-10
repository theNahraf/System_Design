#include <iostream>
using namespace std;

class Character{
public:
    virtual string getAbilities() const =0;
    virtual ~Character(){};
};
class Mario : public Character{
public:
    string getAbilities() const override {
        return "Mario";
    }
};

class CharacterDecorator : public Character {
protected:
    Character* character;
public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
};

class Heightup: public CharacterDecorator {
public:
    Heightup(Character* c): CharacterDecorator(c) {}
    
    string getAbilities() const override {
        return character->getAbilities() + " height up";
    }
};

class Gunpower: public CharacterDecorator {
public:
    Gunpower(Character* c): CharacterDecorator(c) {}
    
    string getAbilities() const override {
        return character->getAbilities() + " gun power";
    }
};

class Starpower: public CharacterDecorator {    
public:
    Starpower(Character* c): CharacterDecorator(c) {}
    
    string getAbilities() const override {
        return character->getAbilities() + " star power for 10 seconds";
    }
};

int main() {
    Character *mario = new Mario();
    cout << "basic abilities: " << mario->getAbilities() << endl;
    mario =  new Heightup(mario);
    cout << "abilities after height up: " << mario->getAbilities() << endl;
    mario  = new Gunpower(mario);
    cout << "abilities after gun power: " << mario->getAbilities() << endl;
    mario = new Starpower(mario);
    cout << "abilities after star power: " << mario->getAbilities() << endl;
    delete mario; // Clean up the dynamically allocated memory

    return 0;
}
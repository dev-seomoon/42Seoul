#include "Character.hpp"

std::string const &  Character::getName(void) const
{
    return name;
}

void    Character::equip(AMateria* materia)
{
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = materia;
            return;
        }
    }
    if (materia != NULL) delete materia;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx > 3) return;
    inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3) return;
    if (inventory[idx] == NULL) return;
    inventory[idx]->use(target);
}

void    Character::print_inventory() const
{
    std::cout << name << "'s inventory" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL)
            std::cout << i << " : " << inventory[i]->getType() << std::endl;
    }
    std::cout << std::endl;
}

Character::Character(const std::string name): name(name) {
    std::cout << "Character constructor called. " << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::~Character() {
    std::cout << "Character destructor called. " << std::endl;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) {
            delete inventory[i];
        }
    }
}

Character&  Character::operator=(Character character) {
    if (this != &character) {
        name = character.getName();
        for (int i = 0; i < 4; i++) {
            if (inventory[i] != NULL) delete inventory[i];
        }
        for (int i = 0; i < 4; i++) {
            if (character.inventory[i] != NULL)
                inventory[i] = character.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::Character(const Character &character) {
    std::cout << "Character copy constructor called. " << std::endl;
    *this = character;
}
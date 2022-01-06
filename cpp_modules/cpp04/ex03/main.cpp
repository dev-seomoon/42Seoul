#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void    test_basic()
{
    std::cout << "--------------------- basic test" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl;
}

void    test_materia_source()
{
    std::cout << "--------------------- materia source test" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());

    AMateria *materia = src->createMateria("cure");
    if (materia == NULL)
        std::cout << "Cannot create a materia which is not learned" << std::endl;
    
    delete src;
    delete materia;

    std::cout << std::endl;
}

void    test_character()
{
    std::cout << "--------------------- character test" << std::endl;
    // character A - full inventory test
    IMateriaSource *src = new MateriaSource();
    Character *A = new Character("A");

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    A->equip(src->createMateria("ice"));
    A->equip(src->createMateria("ice"));
    A->equip(src->createMateria("ice"));
    A->equip(src->createMateria("ice"));

    A->print_inventory();

    A->equip(src->createMateria("cure"));
    A->equip(src->createMateria("cure"));

    A->print_inventory();

    delete A;

    // character B - equip & unequip test
    Character *B = new Character("B");
    AMateria *tmp = src->createMateria("ice");

    B->equip(tmp);
    B->print_inventory();

    B->unequip(0);
    B->print_inventory();

    delete tmp;
    delete B;

    // character C - use (unequiped or not existed) test
    Character *C = new Character("C");
    Character *Enemy = new Character("Enemy");

    C->equip(src->createMateria("ice"));
    C->equip(src->createMateria("cure"));

    C->print_inventory();

    C->use(2, *Enemy);

    C->use(-1, *Enemy);
    C->use(4, *Enemy);

    delete C;
    delete Enemy;
    
    delete src;
}

int     main()
{
    test_basic();
    test_materia_source();
    test_character();

    system("leaks test | grep LEAK");
    return 0;
}
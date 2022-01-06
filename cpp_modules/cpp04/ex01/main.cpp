#include "Cat.hpp"
#include "Dog.hpp"

void    simple_test(void) //ok
{
    const Animal    *j = new Dog();
    const Animal    *i = new Cat();

    delete j;
    delete i;
}

void    array_test(void) //ok
{
    const Animal    *animal[4];

    for (int i = 0; i < 4; i++) {
        if (i < 2) animal[i] = new Dog();
        else animal[i] = new Cat();
    }

    for (int i = 0; i < 4; i++) {
        delete animal[i];
    }
}

void    assign_operator_test(void) //ok
{
    // dog, operator=
    Dog dog;
    Brain   *dogBrain = dog.getBrain();
    dogBrain->setIdea(1, "Dogs have brain");
    std::cout << "Dog: " << dogBrain->getIdea(1) << std::endl;
    std::cout << std::endl;

    Dog dog_copy;
    Brain   *copiedDogBrain = dog_copy.getBrain();
    copiedDogBrain->setIdea(1, "Dog's copies also have brain");
    std::cout << "Dog copy: " << copiedDogBrain->getIdea(1) << std::endl;
    std::cout << std::endl;

    dog_copy = dog;
    std::cout << "Dog copy: " << copiedDogBrain->getIdea(1) << std::endl;
    std::cout << std::endl;

    // cat, operator=
    Cat cat;
    Brain   *catBrain = cat.getBrain();
    catBrain->setIdea(1, "Cats have brain");
    std::cout << "Cat: " << catBrain->getIdea(1) << std::endl;
    std::cout << std::endl;

    Cat cat_copy;
    Brain   *copiedCatBrain = cat_copy.getBrain();
    copiedCatBrain->setIdea(1, "Cat's copies also have brain");
    std::cout << "Cat copy: " << copiedCatBrain->getIdea(1) << std::endl;
    std::cout << std::endl;
    
    cat_copy = cat;
    std::cout << "Cat copy: " << copiedCatBrain->getIdea(1) << std::endl;
    std::cout << std::endl;
}

void    copy_constructor_test(void)
{
    std::cout << "---------------------- heap" << std::endl;
    // heap
    Dog *dog = new Dog();
    std::cout << std::endl;
    Dog *dog_copy = new Dog(*dog);
    std::cout << std::endl;

    delete dog_copy;
    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;

    Cat *cat = new Cat();
    std::cout << std::endl;
    Cat *cat_copy = new Cat(*cat);
    std::cout << std::endl;

    delete cat_copy;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;

    std::cout << "---------------------- stack" << std::endl;
    // stack
    Dog dog_stack;
    std::cout << std::endl;
    Dog dog_stack_copy = dog_stack;
    std::cout << std::endl;

    Cat cat_stack;
    std::cout << std::endl;
    Cat cat_stack_copy = cat_stack;
    std::cout << std::endl;
}

int     main(void)
{
    simple_test();
    array_test();
    assign_operator_test();
    copy_constructor_test();

    system("leaks test | grep LEAK");

    return (0);
}
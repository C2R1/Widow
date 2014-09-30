#pragma once

namespace genetic {

template<typename T>
class Person
{
public:
    Person();
    Person(int lengthRep);
    ~Person();
    void mutate();

    T generateRep(int lengthRep);
    T representation;
    double score;
};

}

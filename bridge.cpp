#include <iostream>

using namespace std;

class Implementor
{
    public:
        virtual void operationImp(){}
};

class Abstraction
{
    public:
        Abstraction()
        {
        }
        Abstraction(Implementor* im)
        {
            pImp = im;
        }
        virtual void operation()
        {
        }
    protected:
        Implementor *pImp;
};

class RefinedAbstraction : public Abstraction
{
    public:
        RefinedAbstraction()
        {
        }
        RefinedAbstraction(Implementor *im) : Abstraction(im)
        {
        }
        void operation()
        {
            cout << "do something and then" << endl;
            pImp->operationImp();
        }

};

class ConcreteImplementorA : public Implementor
{
    public:
       void operationImp()
       {
           cout << "ConcreteImplementorA" << endl;
       }
};

class ConcreteImplementorB : public Implementor
{
    public:
        void operationImp()
        {
           cout << "ConcreteImplementorB" << endl;
        }
};

int main()
{
    Implementor *pImp = new ConcreteImplementorA();
    Abstraction *pa = new RefinedAbstraction(pImp);
    pa->operation();

    pImp = new ConcreteImplementorB();
    Abstraction *pb = new RefinedAbstraction(pImp);
    pb->operation();
}

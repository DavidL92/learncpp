#include <iostream>

using namespace std;

class Component
{
    public:
        virtual void operation()
        {
            cout << "virtual Component.operation()" << endl;
        }
};

class ConcreteComponent : public Component
{
    public:
        void operation()
        {
            cout << "ConcreteComponent.operation()" << endl;
        }
};

class Decorator : public Component
{
    public:
        Decorator(Component *com) : m_pCom(com) {}
        void operation()
        {
            m_pCom->operation();
        }
    protected:
        Component *m_pCom;
};

class ConcreteDecoratorA : public Decorator
{
    public:
        ConcreteDecoratorA(Component *com) : Decorator(com) {}
        void operation()
        {
            AddedBehavior();
            Decorator::operation();
        }
        void AddedBehavior()
        {
            cout << "This is added behavior A." << endl;
        }
};
class ConcreteDecoratorB : public Decorator
{
    public:
        ConcreteDecoratorB(Component *com) : Decorator(com) {}
        void operation()
        {
            AddedBehavior();
            Decorator::operation();
        }
        void AddedBehavior()
        {
            cout << "This is added behavior B." << endl;
        }
};

int main()
{
    Component *pCom = new ConcreteComponent();
    Decorator *pDec = new ConcreteDecoratorA(pCom);
    pDec->operation();

    pDec = new ConcreteDecoratorB(pCom);
    pDec->operation();
}

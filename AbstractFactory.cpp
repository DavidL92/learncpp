#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class AbstractFactory
{
    public:
        virtual void createProductA() {};
        virtual void createProductB() {};
};

class AbstractProductA
{
    public:
        virtual void use() {};
};

class ProductA1 : public AbstractProductA
{
    public:
        void use()
        {
            cout << "A1.use" << endl;
        }
};

class ProductA2 : public AbstractProductA
{
    public:
        void use()
        {
            cout << "A2.use" << endl;
        }
};

class AbstractProductB
{
    public:
        virtual void use() {};
};

class ProductB1 : public AbstractProductB
{
    public:
        void use()
        {
            cout << "B1.use" << endl;
        }
};

class ProductB2 : public AbstractProductB
{
    public:
        void use()
        {
            cout << "B2.use" << endl;
        }
};

class ConcreteFactory1 : public AbstractFactory
{
    public:
        void createProductA()
        {
            ProductA1 A1;
            A1.use();
        }
        
        void createProductB()
        {
            ProductB1 B1;
            B1.use();
        }
        
};

class ConcreteFactory2 : public AbstractFactory
{
    public:
        void createProductA()
        {
            ProductA2 A2;
            A2.use();
        }
        
        void createProductB()
        {
            ProductB2 B2;
            B2.use();
        }
        
};

class Sell
{
    public:
        Sell *getInstance()
        {
            static Sell *_instance;
            if(_instance == NULL)
            {
                _instance = new Sell();
                return _instance;
            }
            else
                return _instance;
        }
        void run()
        {
            while(cin >> product_type)
            {
                if(atoi(&product_type[1]) == 1)
                {
                    fc = new ConcreteFactory1();
                }
                else
                {
                    fc = new ConcreteFactory2();
                }
                switch(product_type[0])
                {
                    case 'A':
                        fc->createProductA();
                        break;
                    case 'B':
                        fc->createProductB();
                        break;
                    default:
                        break;

                }
            }
        }
    private:
        string product_type;
        AbstractFactory *fc;

};

int main()
{
    Sell *sell = new Sell();
    sell->getInstance()->run();
    return 0;
    
}

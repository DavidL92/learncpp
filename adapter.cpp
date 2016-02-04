#include <iostream>

using namespace std;

class Target
{
    public:
        virtual void request()
        {
        }
};

class Adaptee
{
    public:
        void specificRequest()
        {
            cout << "specificRequest" << endl;
        }
};

class Adapter : public Target
{
    public:
        Adapter(Adaptee *adaptee)
        {
           m_adaptee = adaptee; 
        }
        void request()
        {
            m_adaptee->specificRequest();
        }
    private:
        Adaptee *m_adaptee;
};

int main()
{
    Adaptee *ad = new Adaptee();
    Target *target = new Adapter(ad);
    target->request();
    return 0;
}

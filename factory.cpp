#include <iostream>

using namespace std;

class Car
{
    public:
        Car()
        {
        }
        ~Car()
        {
        }
        virtual void create_car() {}
};
class Car1 : public Car
{
    public:
        Car1()
        {
        }
        ~Car1()
        {
        }
        void create_car()
        {
            cout << "Car 1 Created" << endl; 
        }

};

class Car2 : public Car
{
    public:
        Car2()
        {
        }
        ~Car2()
        {
        }
        void create_car()
        {
            cout << "Car 2 Created" << endl; 
        }
};

class Factory
{
    public:
        void GetCar(int num)
        {
            if(num == 1)
                car = new Car1();
            else
                car = new Car2(); 
            car->create_car();
        }
    private:
        Car *car = new Car();
};
int main()
{
    Factory *fac = new Factory();
    int num;
    for(;;)
    {
        cin >> num;
        
        fac->GetCar(num);
    }
    return 0;
}

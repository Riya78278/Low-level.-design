#include <iostream>
#include <memory>
using namespace std;

class Transmission{
    public:
    virtual void changeGear()=0;
    virtual ~Transmission(){}
};
class Manual: public Transmission{
    public:
    void changeGear() override{
        cout<<" this gear activated for manual"<<endl;
    }  
};
class Automatic: public Transmission{
    public:
    void changeGear() override{
        cout<<" this gear activated for automatic "<<endl;
    }  
};

class NoGear: public Transmission{
    public:
    void changeGear() override{
        cout<<" this has no gear"<<endl;
    }  
};

class Vehicle {
    protected:
    unique_ptr<Transmission> transmission;
    public:
    Vehicle (unique_ptr<Transmission>t){
        transmission=move(t);
    }
    virtual void start()=0;
    virtual void stop()=0;
    void changeGear(){
        transmission->changeGear();
    }
    virtual ~Vehicle() {}
};
class Car : public Vehicle {
public:
    Car(unique_ptr<Transmission> t)
        : Vehicle(move(t)) {}

    void start() override {
        cout << "Car starts using ignition"
             << endl;
    }

    void stop() override {
        cout << "Car stops using brakes"
             << endl;
    }
};
class Bike: public Vehicle{
    public:
    Bike(unique_ptr<Transmission>t):Vehicle(move(t)){}
    void start() override{
        cout<<"Bike starts using "<<endl;
    }
    void stop() override{
        cout<<" Bike is stopped"<<endl;
    }
};
class AutoGear: public Vehicle{
    public:
    AutoGear(unique_ptr<Transmission>t): Vehicle(move(t)){}
    void start() override{
        cout<<"autogear start"<<endl;
    }
    void stop() override{
        cout<<"autogear stopped"<<endl;
    }
};


int main() {

    Vehicle* car = new Car(
        make_unique<Manual>()
    );

    Vehicle* bike = new Bike(
        make_unique<Automatic>()
    );

    Vehicle* autoGear = new AutoGear(
        make_unique<NoGear>()
    );

    car->start();
    car->changeGear();
    car->stop();

    cout << endl;

    bike->start();
    bike->changeGear();
    bike->stop();

    cout << endl;

    autoGear->start();
    autoGear->changeGear();
    autoGear->stop();

    delete car;
    delete bike;
    delete autoGear;

    return 0;
}

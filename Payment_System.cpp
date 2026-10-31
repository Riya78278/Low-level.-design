#include <iostream>
using namespace std;

class PaymentMethod{
    public:
    virtual bool ProcessPayment(double amout)=0;

    virtual ~PaymentMethod(){}
};

class CreditCard: public PaymentMethod {
    public:
    bool ProcessPayment(double amount ){
        cout<<"credit card payment"<<amount<<endl;

        cout<<"credit card payment successful"<<endl;
        return true;
    }
    
};

class UPI : public PaymentMethod{
    public:
    bool ProcessPayment(double amount ){
        cout<<"UPI payment"<<amount<<endl;

        cout<<"UPI payment successful"<<endl;
        return true;
    }
    
};
class DebitCard : public PaymentMethod{
    public:
    bool ProcessPayment(double amount ){
        cout<<"DebitCard payment"<<amount<<endl;

        cout<<"DebitCard payment successful"<<endl;
        return true;
    }
    
};

class PayPal : public PaymentMethod{
    public:
    bool ProcessPayment(double amount ){
        cout<<"PayPal payment"<<amount<<endl;

        cout<<"PayPal payment successful"<<endl;
        return true;
    }
    
};

class PaymentService{
    public:
    void makepayment(PaymentMethod& paymentmethod ,double amount){
        bool result= paymentmethod.ProcessPayment(amount);

        if(result ==true){
            cout<<"order payment successfully done"<<endl;
        }
        else{
            cout<<"order is not placed"<<endl;
        }
    }
};



int main(){
    CreditCard creditcard;
    PaymentService service;
    service.makepayment(creditcard,2000);
    cout<<"all is done"<<endl;
    return 0;
} 

// what this follows :

/* Abstraction: PaymentMethod defines the common payment interface.
Inheritance: CreditCard, UPI, DebitCard, and PayPal inherit from PaymentMethod.
Polymorphism: PaymentService calls ProcessPayment() through a PaymentMethod&.
Strategy Pattern: Each payment type has its own payment processing logic.
Open/Closed Principle: You can add a new payment type without modifying the existing PaymentService.*/

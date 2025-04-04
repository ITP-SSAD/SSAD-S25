
#include <iostream>
#include <unordered_map>

class PaymentProvider {
public:
    virtual void processPayment(std::string paymentInfo) = 0;
    virtual void handleRefund(std::string refundInfo) = 0;
    virtual bool verifyPayment(std::string transactionId) = 0;
};

class PayPal {
public:
    void makePayment(std::string item) {
        std::cout << "Making PayPal payment for item: " << item << std::endl;
    }

    bool verifyPayment(std::string transactionId) {
        std::cout << "Verifying PayPal payment with transaction ID: " << transactionId << std::endl;
        return true;
    }

    void refundPayment(std::string item) {
        std::cout << "Refunding PayPal payment for item: " << item << std::endl;
    }
};


class PayPalAdapter: public PaymentProvider{
private:
    PayPal* paypal;

public:
    PayPalAdapter(PayPal* paypal) {
        this->paypal = paypal;
    }

    void processPayment(std::string item) override {
        paypal->makePayment(item);
    }

    bool verifyPayment(std::string transactionId) override {
       return paypal->verifyPayment(transactionId);
    }

    void handleRefund(std::string item) override {
        paypal->refundPayment(item);
    }
};

class Stripe {
public:
    void chargePayment(std::string item) {
        std::cout << "Charging Stripe payment for item: " << item << std::endl;
    }

    bool verifyCharge(std::string transactionId) {
        std::cout << "Verifying Stripe payment with transaction ID: " << transactionId << std::endl;
        return true;
    }

    void issueRefund(std::string item) {
        std::cout << "Issuing Refund for Stripe payment for item: " << item << std::endl;
    }
};

class StripeAdapter: public PaymentProvider {
private:
    Stripe* stripe;

public:
    StripeAdapter(Stripe* stripe) {
        this->stripe = stripe;
    }

    void processPayment(std::string item) override {
        stripe->chargePayment(item);
    }

    bool verifyPayment(std::string transactionId) override {
        return stripe->verifyCharge(transactionId);
    }

    void handleRefund(std::string item) override {
        stripe->issueRefund(item);
    }
};

class PaymentGateWay {
private:
    std::unordered_map<std::string, PaymentProvider*> paymentProviders;

public:
    void addPaymentProvider(std::string providerName, PaymentProvider* provider) {
        paymentProviders[providerName] = provider;
    }

    void processPayment(std::string providerName, std::string item) {
        if (paymentProviders.find(providerName) != paymentProviders.end()) {
            paymentProviders[providerName]->processPayment(item);
        } else {
            std::cout << "Payment provider not found: " << providerName << std::endl;
        }
    }

    void verifyPayment(std::string providerName, std::string transactionId) {
        if (paymentProviders.find(providerName) != paymentProviders.end()) {
            paymentProviders[providerName]->verifyPayment(transactionId);
        } else {
            std::cout << "Payment provider not found: " << providerName << std::endl;
        }
    }

    void refundPayment(std::string providerName, std::string item) {
        if (paymentProviders.find(providerName) != paymentProviders.end()) {
            paymentProviders[providerName]->handleRefund(item);
        } else {
            std::cout << "Payment provider not found: " << providerName << std::endl;
        }
    }
};

int main() {
    PayPalAdapter* paypalAdapter = new PayPalAdapter(new PayPal());
    StripeAdapter* stripeAdapter = new StripeAdapter(new Stripe());

    PaymentGateWay paymentGateWay;
    paymentGateWay.addPaymentProvider("STRIPE", stripeAdapter);
    paymentGateWay.processPayment("STRIPE", "SHEIN-SHOES");
    paymentGateWay.verifyPayment("STRIPE", "transactionId:001001");
    paymentGateWay.refundPayment("STRIPE", "Refund SHEIN-SHOES");
    std::cout << std::endl;
    paymentGateWay.addPaymentProvider("PAYPAL", paypalAdapter);
    paymentGateWay.processPayment("PAYPAL", "KAZAN-EXPRESS-HATS");
    paymentGateWay.verifyPayment("PAYPAL", "transactionId:061041");
    paymentGateWay.refundPayment("PAYPAL", "Refund KAZAN-EXPRESS-HATS");

    delete paypalAdapter;
    delete stripeAdapter;

    return 0;
}


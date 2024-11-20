#include <iostream>
#include <iomanip>
using namespace std;

void displayCurrencies() {
    cout << "Available currencies:" << endl;
    cout << "1. USD (US Dollar)" << endl;
    cout << "2. EUR (Euro)" << endl;
    cout << "3. GBP (British Pound)" << endl;
    cout << "4. INR (Indian Rupee)" << endl;
    cout << "5. JPY (Japanese Yen)" << endl;
    cout << "6. PKR (Pakistani Rupee)" << endl; // Added PKR
    cout << endl;
}

double getConversionRate(int fromCurrency, int toCurrency) {
    double rates[6][6] = {
        {1.0, 0.92, 0.77, 83.0, 148.5, 290.0},  // From USD
        {1.09, 1.0, 0.84, 90.5, 161.5, 314.0},  // From EUR
        {1.29, 1.19, 1.0, 108.0, 191.8, 374.0}, // From GBP
        {0.012, 0.011, 0.0093, 1.0, 1.78, 3.66}, // From INR
        {0.0067, 0.0062, 0.0052, 0.56, 1.0, 2.06},// From JPY
        {0.0034, 0.0032, 0.0027, 0.27, 0.49, 1.0} // From PKR
    };
    return rates[fromCurrency - 1][toCurrency - 1];
}

int main() {
    int fromCurrency, toCurrency;
    double amount, convertedAmount;

    cout << "=== Currency Converter ===" << endl;
    displayCurrencies();

    cout << "Enter the number corresponding to your source currency: ";
    cin >> fromCurrency;
    cout << "Enter the number corresponding to your target currency: ";
    cin >> toCurrency;
    cout << "Enter the amount to convert: ";
    cin >> amount;

    if (fromCurrency < 1 || fromCurrency > 6 || toCurrency < 1 || toCurrency > 6) {
        cout << "Invalid currency selection!" << endl;
        return 1;  // Exit if invalid currency is selected
    }

    double rate = getConversionRate(fromCurrency, toCurrency);
    convertedAmount = amount * rate;

    cout << fixed << setprecision(2);  // Format the output to two decimal places
    cout << amount << " in source currency is equal to " << convertedAmount << " in target currency." << endl;

    return 0;
}

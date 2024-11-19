#include <iostream>
#include <iomanip>
using namespace std;

// Function to display available currencies
void displayCurrencies() {
    cout << "Available currencies:" << endl;
    cout << "1. USD (US Dollar)" << endl;
    cout << "2. EUR (Euro)" << endl;
    cout << "3. GBP (British Pound)" << endl;
    cout << "4. INR (Indian Rupee)" << endl;
    cout << "5. JPY (Japanese Yen)" << endl;
    cout << endl;
}

// Function to get conversion rate
double getConversionRate(int fromCurrency, int toCurrency) {
    // Conversion rates (example values)
    double rates[5][5] = {
        {1.0, 0.92, 0.77, 83.0, 148.5}, // From USD
        {1.09, 1.0, 0.84, 90.5, 161.5}, // From EUR
        {1.29, 1.19, 1.0, 108.0, 191.8}, // From GBP
        {0.012, 0.011, 0.0093, 1.0, 1.78}, // From INR
        {0.0067, 0.0062, 0.0052, 0.56, 1.0}  // From JPY
    };
    return rates[fromCurrency - 1][toCurrency - 1];
}

int main() {
    int fromCurrency, toCurrency;
    double amount, convertedAmount;

    cout << "=== Currency Converter ===" << endl;
    displayCurrencies();

    // Input from user
    cout << "Enter the number corresponding to your source currency: ";
    cin >> fromCurrency;
    cout << "Enter the number corresponding to your target currency: ";
    cin >> toCurrency;
    cout << "Enter the amount to convert: ";
    cin >> amount;

    // Validation
    if (fromCurrency < 1 || fromCurrency > 5 || toCurrency < 1 || toCurrency > 5) {
        cout << "Invalid currency selection!" << endl;
        return 1;
    }

    // Conversion
    double rate = getConversionRate(fromCurrency, toCurrency);
    convertedAmount = amount * rate;

    // Display result
    cout << fixed << setprecision(2);
    cout << amount << " in source currency is equal to " << convertedAmount << " in target currency." << endl;

    return 0;
}

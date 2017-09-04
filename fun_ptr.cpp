// fun_ptr.cpp -- wskaźniki na funkcje
#include <iostream>
double betsy(int);
double pam(int);

// drugi parametr to wskaźnik funkcji typu double, mającej jeden
// parametr typu int
void estimate(int lines, double (*pf)(int));

int main()
{
    using namespace std;
    int code;

    cout << "Ile wierszy kodu należy napisać? ";
    cin >> code;
    cout << "Oszacowanie Betsy:\n";
    estimate(code, betsy);
    cout << "Oszacowanie Pam:\n";
    estimate(code, pam);
    return 0;
}

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " wierszy wymaga ";
    cout << (*pf)(lines) << " godzin pracy\n";
}

// addpntrs.cpp -- dodawanie wskaźników
#include <iostream>
int main()
{
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

// Oto dwa sposoby określania adresu tablicy
    double * pw = wages;     // nazwa tablicy = adres
    short * ps = &stacks[0]; // można też użyć operatora adresu
// element tablicy
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "dodaj do wskaźnika pw 1:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "dodaj do wskaźnika ps 1:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "dostęp do dwóch elementów, zapis tablicowy\n";
    cout << "stacks[0] = " << stacks[0] 
         << ", stacks[1] = " << stacks[1] << endl;
    cout << "dostęp do dwóch elementów, zapis wskaźnikowy\n";
    cout << "*stacks = " << *stacks
         << ", *(stacks + 1) =  " << *(stacks + 1) << endl;
    cout << "wages= " << wages << ", *wages = " << *wages 
	 << ", *(wages + 1) = " << *(wages + 1) << endl;
	    
    cout << sizeof(wages) << " = wielkość tablicy wages\n";
    cout << sizeof(pw) << " = wielkość wskaźnika pw\n";
    return 0; 
}

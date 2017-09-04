// arfupt.cpp -- tablica wskaźników do funkcji
#include <iostream>

// różne zapisy, efektywnie te same sygnatury
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};
    // wskaźnik do funkcji
    typedef const double *(*p_fun)(const double *, int);
    p_fun p1 = f1;
    auto p2 = f2; // automatyczna dedukcja typów w C++11
    // w C++98 można użyć poniższej deklaracji:
    // const double *(*p2)(const double *, int) = f2;
    cout << "Używanie wskaźników do funkcji:\n";
    cout << " adres  wartość zwracana\n";
    cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << ": " << *p2(av,3) << endl;
    // pa to tablica wskaźników
    p_fun pa[3] = {f1,f2,f3};
    // auto nie działa przy inicjalizacji listą
    // ale działa przy inicjalizacji pojedynczą wartością
    // pb to wskaźnik do pierwszego elementu pa
    auto pb = pa;
    cout << "\nUżywanie tablicy wskaźników do funkcji:\n";
    cout << " adres  wartość zwracana\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
    cout << "\nUżywanie wskaźnika do wskaźnika do funkcji:\n";
    cout << " adres  wartość zwracana\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;
    // a co ze wskaźnikiem do tablicy wskaźników do funkcji?
    cout << "\nUżywanie wskaźników do tablicy wskaźników do funkcji:\n";
    cout << " adres  wartość zwracana\n";
    // łatwy sposób deklarowania pc
    auto pc = &pa;
    cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
    // nieco trudniejszy sposób deklarowania pd
	p_fun (*pd)[3] = &pa;
    // zapisanie zwróconej wartości w pdb
    const double * pdb = (*pd)[1](av,3);
    cout << pdb << ": " << *pdb << endl;
    // albo tak:
    cout << (*(*pd)[2])(av,3) << ": " << *(*(*pd)[2])(av,3) << endl;
    // cin.get();
    return 0;
}

// kilka funkcji-atrap
const double * f1(const double * ar, int n)
{
    return ar;
}
const double * f2(const double ar[], int n)
{
    return ar+1;
}
const double * f3(const double ar[], int n)
{
    return ar+2;
}

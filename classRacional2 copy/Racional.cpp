
// Rafael A. Arce Nazario
// 
// Implementación de la clase Racional
//
// Christopher L. Ayala-Griffin
// 801-12-0585
// ccom3034_0U1
// Pruebas e implementación de la clase Racional.
//

#include "Racional.h"
#include <algorithm>
#include <iostream>
using namespace std;
Racional::Racional() : p(0), q(1) {
}

Racional::Racional(int pa, int qa) : p(pa), q(qa) {
}

int Racional::getP() const {
    return p;
}

int Racional::getQ() const {
    return q;
}

void Racional::simplificar() {
    int g = __gcd(p,q);
    p = p / g;
    q = q / g;
}

void Racional::operator~() {
    int g = __gcd(p,q);
    p = p / g;
    q = q / g;
}

Racional Racional::suma(const Racional &r) const {
    return Racional((p * r.q) + (q * r.p) , q * r.q);
}

Racional Racional::operator+(const Racional &r) const {
    return Racional((p * r.q) + (q * r.p) , q * r.q);
}

Racional Racional::operator+(int a) const {
    return Racional((p) + (q * a) , q );
}

Racional operator+(int a, const Racional &r) {
    return Racional((a * r.getQ()) + (r.getP()) ,  r.getQ());
}

Racional suma(const Racional &r1, const Racional &r2) {
    return Racional((r1.getP() * r2.getQ()) + (r1.getQ() * r2.getP()) , r1.getP() * r2.getQ());
}

bool Racional::gt(const Racional &r) const {
    return  p * r.q > q * r.p ;
}

bool Racional::operator>(const Racional &r) const {
    return  p * r.q > q * r.p ;
}

void Racional::display() const {
    cout << p << " / " << q << endl;
}

Racional Racional::operator*(const Racional &r) const {
    return Racional(p * r.getP(), q * r.getQ());
}

Racional Racional::operator*(int a) const {
    return Racional(p * a, q);
}

Racional operator*(int a, const Racional &r) {
    return Racional(a * r.getP(), r.getQ());
}

bool Racional::operator==(const Racional &r) const {
    return  p * r.q == q * r.p ;
}

Racional Racional::operator++(int) {
    Racional temp (p, q);
    p += q;
    return temp;
}

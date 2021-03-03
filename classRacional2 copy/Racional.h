//
// Created by student on 02/05/20.
//
// Christopher L. Ayala-Griffin
// 801-12-0585
// ccom3034_0U1
// Pruebas e implementación de la clase Racional.
//

#ifndef UNTITLED1_RACIONAL_H
#define UNTITLED1_RACIONAL_H

class Racional {
private:
    int p, q;
public:
    Racional();
    Racional(int pa, int qa);
    void simplificar();
    void operator~();
    int getP() const;
    int getQ() const;
    void display() const;
    Racional suma (const Racional &r) const;
    Racional operator+(const Racional &r) const;
    Racional operator+(int a) const;
    bool gt(const Racional &r) const;
    bool operator>(const Racional &r) const;
    Racional operator*(const Racional &r) const;
    Racional operator*(int a) const;
    bool operator==(const Racional &r) const;
    Racional operator++(int);
};

Racional suma(const Racional &r1, const Racional &r2);
Racional operator+(int a, const Racional &r);
Racional operator*(int a, const Racional &r);
#endif //UNTITLED1_RACIONAL_H

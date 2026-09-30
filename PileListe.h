// PileListe.h
#ifndef PILELISTE_H
#define PILELISTE_H

#include <cstddef>
#include "IPile.h"

template <typename T>
class PILE_API PileListe : public IPile<T> {
public:
    PileListe();
    ~PileListe() override;

    PileListe(const PileListe&) = delete;
    PileListe& operator=(const PileListe&) = delete;

    void push(const T& valeur) override;
    T pop() override;
    bool isEmpty() const override;

private:
    struct Noeud {
        T valeur;
        Noeud* suivant;
        Noeud(const T& v, Noeud* s) : valeur(v), suivant(s) {}
    };

    Noeud* m_sommet;
};

#endif // PILELISTE_H

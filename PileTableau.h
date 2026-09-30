// PileTableau.h
#ifndef PILETABLEAU_H
#define PILETABLEAU_H

#include <cstddef>
#include "IPile.h"

template <typename T>
class PILE_API PileTableau : public IPile<T> {
public:
    explicit PileTableau(std::size_t capaciteInitiale = 4);
    ~PileTableau() override;

    PileTableau(const PileTableau&) = delete;
    PileTableau& operator=(const PileTableau&) = delete;

    void push(const T& valeur) override;
    T pop() override;
    bool isEmpty() const override;

private:
    void redimensionner(std::size_t nouvelleCapacite);

    T* m_donnees;
    std::size_t m_taille;
    std::size_t m_capacite;
};

#endif // PILETABLEAU_H

// PileListe.cpp
#include "PileListe.h"
#include <stdexcept>

template <typename T>
PileListe<T>::PileListe() : m_sommet(nullptr)
{
}

template <typename T>
PileListe<T>::~PileListe()
{
    while (m_sommet != nullptr) {
        Noeud* suivant = m_sommet->suivant;
        delete m_sommet;
        m_sommet = suivant;
    }
}

template <typename T>
void PileListe<T>::push(const T& valeur)
{
    m_sommet = new Noeud(valeur, m_sommet);
}

template <typename T>
T PileListe<T>::pop()
{
    if (m_sommet == nullptr) {
        throw std::underflow_error("PileListe::pop() : pile vide");
    }
    Noeud* ancien = m_sommet;
    T valeur = ancien->valeur;
    m_sommet = ancien->suivant;
    delete ancien;
    return valeur;
}

template <typename T>
bool PileListe<T>::isEmpty() const
{
    return m_sommet == nullptr;
}

// Instanciations explicites
template class PileListe<char>;
template class PileListe<int>;

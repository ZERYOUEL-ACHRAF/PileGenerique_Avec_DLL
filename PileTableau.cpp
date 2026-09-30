// PileTableau.cpp
#include "PileTableau.h"
#include <stdexcept>

template <typename T>
PileTableau<T>::PileTableau(std::size_t capaciteInitiale)
    : m_donnees(nullptr),
      m_taille(0),
      m_capacite(capaciteInitiale > 0 ? capaciteInitiale : 1)
{
    m_donnees = new T[m_capacite];
}

template <typename T>
PileTableau<T>::~PileTableau()
{
    delete[] m_donnees;
}

template <typename T>
void PileTableau<T>::redimensionner(std::size_t nouvelleCapacite)
{
    T* nouveau = new T[nouvelleCapacite];
    try {
        for (std::size_t i = 0; i < m_taille; ++i) {
            nouveau[i] = m_donnees[i];
        }
    } catch (...) {
        delete[] nouveau;
        throw;
    }
    delete[] m_donnees;
    m_donnees = nouveau;
    m_capacite = nouvelleCapacite;
}

template <typename T>
void PileTableau<T>::push(const T& valeur)
{
    if (m_taille == m_capacite) {
        redimensionner(m_capacite * 2);
    }
    m_donnees[m_taille++] = valeur;
}

template <typename T>
T PileTableau<T>::pop()
{
    if (m_taille == 0) {
        throw std::underflow_error("PileTableau::pop() : pile vide");
    }
    return m_donnees[--m_taille];
}

template <typename T>
bool PileTableau<T>::isEmpty() const
{
    return m_taille == 0;
}

// Instanciations explicites
template class PileTableau<char>;
template class PileTableau<int>;

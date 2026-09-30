// main.cpp
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include "IPile.h"
#include "PileTableau.h"
#include "PileListe.h"

namespace {

constexpr int NB_INSERTIONS = 100000;

long long mesurerInsertions(IPile<int>& pile)
{
    const auto debut = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NB_INSERTIONS; ++i) {
        pile.push(i);
    }
    const auto fin = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(fin - debut).count();
}

bool expressionValide(const std::string& expression)
{
    PileTableau<char> pile;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            pile.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pile.isEmpty()) {
                return false;
            }
            const char ouvrant = pile.pop();
            const bool correspond = (ouvrant == '(' && c == ')') ||
                                    (ouvrant == '[' && c == ']') ||
                                    (ouvrant == '{' && c == '}');
            if (!correspond) {
                return false;
            }
        }
    }
    return pile.isEmpty();
}

} // namespace

int main()
{
    std::unique_ptr<IPile<int>> tableau = std::make_unique<PileTableau<int>>();
    std::unique_ptr<IPile<int>> liste   = std::make_unique<PileListe<int>>();

    const long long tempsTableau = mesurerInsertions(*tableau);
    const long long tempsListe   = mesurerInsertions(*liste);

    // "us" en ASCII pour eviter les problemes d'encodage de la console Windows
    std::cout << "=== " << NB_INSERTIONS << " insertions successives ===\n";
    std::cout << "PileTableau<int> : " << tempsTableau << " us (microsecondes)\n";
    std::cout << "PileListe<int>   : " << tempsListe   << " us (microsecondes)\n\n";

    const std::string tests[] = {
        "(3 + 4) * [2 - 1]",
        "{(1 + 2) * [3 - 4]} / 5",
        "(3 + 4] * 2",
        "((1 + 2)",
        "1 + 2)"
    };

    std::cout << "=== Verification d'expressions (PileTableau<char>) ===\n";
    for (const std::string& expr : tests) {
        std::cout << "\"" << expr << "\" -> "
                  << (expressionValide(expr) ? "valide" : "invalide") << '\n';
    }

    return 0;
}

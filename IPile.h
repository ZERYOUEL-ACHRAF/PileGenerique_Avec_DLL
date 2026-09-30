// IPile.h
#ifndef IPILE_H
#define IPILE_H

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef BUILDING_DLL
        #define PILE_API __declspec(dllexport)
    #else
        #define PILE_API __declspec(dllimport)
    #endif
#else
    #define PILE_API
#endif

template <typename T>
class IPile {
public:
    virtual ~IPile() = default;

    virtual void push(const T& valeur) = 0;
    virtual T pop() = 0;                    // leve std::underflow_error si vide
    virtual bool isEmpty() const = 0;
};

#endif // IPILE_H

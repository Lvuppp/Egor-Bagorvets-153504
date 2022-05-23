#ifndef PAIR_H
#define PAIR_H

template<class F, class S>
struct Pair
{
    constexpr Pair();
    constexpr Pair(const Pair<F,S>& pair) : first(pair.first), second(pair.second){};
    constexpr Pair(Pair<F,S>&& pair) : first(pair.first), second(pair.second){};
    constexpr Pair(const F& first,const S& second): first(first), second(second){};

    F first;
    S second;
};

#endif // PAIR_H

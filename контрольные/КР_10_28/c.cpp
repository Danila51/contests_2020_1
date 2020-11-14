#include <vector>
#include <iostream>

#include <iterator>
#include <functional>

template<typename Iter>
using iter_vt = typename std::iterator_traits<Iter>::value_type;

template<typename Iter, typename Comp>
iter_vt<Iter> qsort_pivot(Iter beg, Iter end, Comp cmp){
    auto mid = beg + (end - beg)/2;
    auto lst = end - 1;

    if(cmp(*mid,*beg))
        std::swap(*beg, *mid);
    if(cmp(*lst,*beg))
        std::swap(*beg, *lst);
    if(cmp(*mid,*lst))
        std::swap(*mid, *lst);

    return *lst;
}

template<typename Iter, typename Comp>
Iter qsort_partition(Iter beg, Iter end, Comp cmp){
    iter_vt<Iter> pivot = qsort_pivot(beg, end, cmp);

    Iter pos = beg;
    for(; beg != end-1; ++beg){
        if(cmp(*beg, pivot)){
            std::swap(*pos, *beg);
            ++pos;
        }
    }
    std::swap(*pos, *(end-1));

    return pos;
}

template<typename Iter, typename Comp = std::less<iter_vt<Iter>>>
void Sort(Iter beg, Iter end, Comp cmp = std::less<iter_vt<Iter>>{}){
    if(std::distance(beg,end) < 2)
        return;

    Iter mid = qsort_partition(beg,end,cmp);

    Sort(beg  , mid, cmp);
    Sort(mid+1, end, cmp);
}

template<typename T, typename Comp = std::less<T>>
void Sort(std::vector<T>* pv, Comp cmp = std::less<T>{}){
    Sort(pv->begin(), pv->end(), cmp);
}

int main() {
    {
        std::vector < int32_t > a{4, 3, 2, 1};
        Sort(a.begin(), a.end());
        for (auto i: a) { std::cout << i << " "; }
        // 1 2 3 4
        std::cout << "\n";
    }
    {
        std::vector < int32_t > a{4, 3, 2, 1};
        Sort(&a);
        for (auto i: a) { std::cout << i << " "; }
        // 1 2 3 4
        std::cout << "\n";
    }
    {
        std::vector < int32_t > a{1, 2, 3, 4};
        Sort(a.begin(), a.end(), std::greater< int32_t >());
        for (auto i: a) { std::cout << i << " "; }
        // 4 3 2 1
        std::cout << "\n";
    }
}

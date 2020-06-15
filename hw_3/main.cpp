#include <iostream>
#include "int_list_t.h"

int main() {
    int_list_t l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }

    std::cout << l1 << " - list 1" << std::endl;
    int_list_t l2 = l1.splice(1, 5);
    std::cout << l2 << " - spliced part of first list: list 2" << std::endl;
    std::cout << l1 << " - first list without spliced part" << std::endl;
    std::cout << l2.back() << " - last element of second list"<< std::endl;
    l2.clear();
    std::cout << l2.empty() << " - clear func check" << std::endl;
    int_list_t l3(l1), l4(3, 4);
    std::cout << l3 << " - creating list from l1 copy" << std::endl;
    std::cout << l3.merge(l4) << " - merging {4, 4, 4} list" << std::endl;
    l3.reverse();
    std::cout << l3 << " - reverse func check" << std::endl;
    l3.insert(2, 4);
    std::cout << l3 << " - insert func check" << std::endl;
    l1.swap(l3);
    std::cout << l1 << " - list swaped with previous" << std::endl;
    std::cout << l1.size() << " - size func check" << std::endl;
    l1.pop_front();
    l1.pop_back();
    std::cout << l1 << " - pop_front/pop_back func check" << std::endl;
    std::cout <<l1[2] << " - l[2] ([] attribute check)" <<std::endl;
    int_list_t l5 = l1;
    std::cout << l5 << " - copy of previous list (= attribute check)" << std::endl << std::endl;

    int_list_t l7;
    std::cout << "ENTER SEVERAL INTEGERS WITHOUT ANY SPACES OR PUNCTUATION MARKS: ";
    std::cin >> l7;

    std::cout << l7 << " - your list";



    return 0;
}
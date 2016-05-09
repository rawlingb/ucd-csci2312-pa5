//
// Created by Brian on 5/8/2016.
//

#ifndef UCD_CSCI2312_PA5_LESS_FUNCTOR_H
#define UCD_CSCI2312_PA5_LESS_FUNCTOR_H

#include <string>
#include <cstring>

namespace CS2312 {
    template<typename T>
    class less {
        public:
            bool operator() (const T&, const T& );
    };

    template<>
    class less<const char *>{
        public:
            bool operator() (const char*, const char* );
    };

    template<>
    class less<std::string>{
    public:
        bool operator() (std::string, std::string);
    };

    template<typename T>
    bool less<T>::operator()(const T& lhs, const T& rhs) {
        return lhs < rhs;
    }

    bool less<const char *>::operator()(const char* lhs, const char* rhs) {
        return strcmp(lhs, rhs) < 0;
    }

    bool less<std::string>::operator()(std::string lhs, std::string rhs) {
        return lhs < rhs;
    }


}



#endif //UCD_CSCI2312_PA5_LESS_FUNCTOR_H

#ifndef _SEEDS_HXX_
#define _SEEDS_HXX_

#include <random>
#include <vector>
#include <algorithm>

struct Seeds
{
    static std::vector<char> Charset()
    {
        //Change this to suit
        return std::vector<char>( {
            '0','1','2','3','4',
            '5','6','7','8','9',
            'A','B','C','D','E','F',
            'G','H','I','J','K',
            'L','M','N','O','P',
            'Q','R','S','T','U',
            'V','W','X','Y','Z',
            'a','b','c','d','e','f',
            'g','h','i','j','k',
            'l','m','n','o','p',
            'q','r','s','t','u',
            'v','w','x','y','z'
        });
    };

    template <size_t Length = 10>
    static std::string RandomStringGen ()
    {
        const auto ch_set = Charset();
        std::default_random_engine rng ( std::random_device{}() );
        std::uniform_int_distribution<> dist( 0, ch_set.size() - 1 );
        std::string str ( Length, 0 );
        std::generate_n ( str.begin(), Length, [ ch_set, &dist, &rng ] (  ) {
            return ch_set[ dist(rng) ];
        } );
        return str;
    }

    template <size_t ContSize = 1000, size_t StringLength = 10>
    static std::vector<std::string> GenVectorOfStrings ()
    {
        std::vector<std::string> svec;
        for ( size_t i = 0; i < ContSize; ++i )
        {
            svec.push_back ( RandomStringGen<StringLength>() );
        }
        return svec;
    }

};

#endif
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <algorithm>

#include "timings.hxx"
#include "seeds.hxx"

using namespace std;

int main ( int argc, char * argv[] )
{
    vector<string> svec = Seeds::GenVectorOfStrings<10, 10>();
    set<string> sset ( svec.begin(), svec.end() );
    unordered_set<string> usset ( svec.begin(), svec.end() );
    list<string> slist ( svec.begin(), svec.end() );
    string target = svec.at ( svec.size() / 2 );

    auto span = Timings::TimeSpan <micro, 1000> ( [&] () {
        std::find ( svec.begin(), svec.end(),  target );
    } );
    cout << span.count() << " us" << endl;

    span = Timings::TimeSpan <micro, 1000> ( [&] () {
        std::find ( svec.begin(), svec.end(),  target );
    } );
    cout << span.count() << " us" << endl;

    span = Timings::TimeSpan <micro, 1000> ( [&] () {
        sset.find ( target );
    } );
    cout << span.count() << " us" << endl;

    span = Timings::TimeSpan <micro, 1000> ( [&] () {
        usset.find ( target );
    } );
    cout << span.count() << " us" << endl;

    span = Timings::TimeSpan <micro, 1000> ( [&] () {
        std::find ( slist.begin(), slist.end(),  target );
    } );
    cout << span.count() << " us" << endl;

    return 0;
}
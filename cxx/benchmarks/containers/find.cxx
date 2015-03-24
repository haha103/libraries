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
    //vector<string> svec = Seeds::GenVectorOfStrings<10, 10>();
    vector<string> svec;
    svec.emplace_back ( "TOM1" );
    svec.emplace_back ( "TOM2" );
    svec.emplace_back ( "TOM3" );
    svec.emplace_back ( "TOM4" );
    svec.emplace_back ( "TOM5" );
    svec.emplace_back ( "TOM6" );
    svec.emplace_back ( "TOM7" );
    svec.emplace_back ( "TOM8" );
    set<string> sset ( svec.begin(), svec.end() );
    unordered_set<string> usset ( svec.begin(), svec.end() );
    list<string> slist ( svec.begin(), svec.end() );
    string target = "TOM6";

    auto span = Timings::TimeSpan <milli, 10000000> ( [&] () {
        std::find ( svec.begin(), svec.end(),  target );
    } );
    cout << "vector: " << span.count() << " ms" << endl;

    span = Timings::TimeSpan <milli, 10000000> ( [&] () {
        sset.find ( target );
    } );
    cout << "set: " << span.count() << " ms" << endl;

    span = Timings::TimeSpan <milli, 10000000> ( [&] () {
        usset.find ( target );
    } );
    cout << "unordered_set: " << span.count() << " ms" << endl;

    span = Timings::TimeSpan <milli, 10000000> ( [&] () {
        std::find ( slist.begin(), slist.end(),  target );
    } );
    cout << "list: " << span.count() << " ms" << endl;

    return 0;
}

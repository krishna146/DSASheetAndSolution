#include <bits/stdc++.h>
using namespace std;
int fact(static int n){
  if(n == 1) return 1;
  return n * fact(n - 1);
}

int main ( int argc , char ** argv )
{

    std :: promise < int > promise ;
    auto future promise.get_future ( ) ;
    for ( auto & i : { 3 , 2 , 1 } ) {
        std :: thread work ( [ & promise , i ] ( ) {
             std :: this_thread :: sleep_for ( std :: chrono : : seconds ( i ) ) ;
        } ) ;
             promise.set_value ( i ) ;
        work.detach ( ) ;
    }
    std :: cout << future.get ( ) << std :: endl ;
}

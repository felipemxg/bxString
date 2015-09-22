#include <stdio.h>
#include "String.h"

using namespace string;

int main(int argc, char* argv[])
{
    string_t str = "Hello world";
    string_t str2 = "Hello world";
    if ( str != str2 ) {
        printf( "diferentes\n" );
    } else {
        printf( "iguais\n" );
    }
    printf( "string: %s\n", string::to_cstr(str) );
    return 0;
}

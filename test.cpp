#include <stdio.h>
#include "String.h"

using namespace string;

void test_strings()
{
    printf( " *** TEST STRING LIBRARY *** \n");
    string_t str1 = "Hello world";
    string_t str2 = "Hello, world";

    printf( "str1 = %s\tlength = %d\n", to_cstr(str1), str1.length );
    printf( "str2 = %s\tlength = %d\n", to_cstr(str2), str2.length );

    if ( str1 == str2 ) {
        printf( "iguais\n" );
    } else {
        printf( "diferentes\n" );
    }

    printf( "str2[5] = %c\n", str2[5] );
    str2[5] = ';';
    printf( "str2 = %s\n", to_cstr( str2 ) );

//    printf( "str1[20] = %c\n", str1[20] );

    string_t str3;
//    printf( "str3[0] = %c\n", str3[0] );
}

int main(int argc, char* argv[])
{
    test_strings();
    return 0;
}

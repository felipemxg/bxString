#include "String.h"

#include <cstdio>
#include <cstdlib>

static inline string_t & CopyDataToString( string_t &str, const uint8_t *data,
                                           size_t length )
{
    if ( str.data ) {
        if ( str.length < length ) {
            str.data = ( unsigned char * ) string::resize( str, length );
        }
    } else {
        str.data = ( unsigned char * ) string::allocate( length );
    }
    str.length = length;
    memcpy( str.data, data, length );
    return str;
}


string_t::string_t( void )
{
}

string_t::string_t( const char *cstr )
{
    this->operator=( cstr );
}

string_t::~string_t( void )
{
    string::clear( *this );
}

string_t & string_t::operator=( const string_t &str )
{
    return CopyDataToString( *this, str.data, str.length );
}

string_t & string_t::operator=( const char *cstr )
{
    return CopyDataToString( *this, ( const uint8_t * ) cstr, strlen( cstr ) );
}


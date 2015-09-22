#include "String.h"

#include <cstdio>
#include <cstdlib>

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

void string_t::operator=( const char *cstr )
{
    int len = strlen( cstr );
    if ( !this->data ) {
        this->data = ( unsigned char * ) string::allocate( len );
    } else {
        if ( this->length < len ) {
            this->data = ( unsigned char * ) string::resize( *this, len );
        }
    }
    this->length = len;
    memcpy( this->data, cstr, len );
}


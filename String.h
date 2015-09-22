#include <cstdlib>
#include <cstring>

struct string_t {
    size_t          length = 0;
    unsigned char   *data = nullptr;


                    string_t( void );
                    string_t( const char *cstr );

    virtual          ~string_t( void );

    
    string_t &      operator=( const string_t &str ) = default;
    void            operator=( const char *cstr );


    inline unsigned char operator[]( size_t index )
    {
        if ( index < this->length ) {
            return this->data[ index ];
        } else {
            return this->data[ 0 ];
        }
    }
};

namespace string {
    inline void * allocate( size_t size )
    {
        return malloc( size );
    }

    inline void * resize( const string_t &str, size_t size )
    {
        return realloc( ( void *) str.data, size );
    }

    inline void clear( string_t &str )
    {
        if ( str.data ) {
            free( str.data );
        }
        str.length = 0;
    }


    inline char * to_cstr( const string_t &str )
    {
        char *cstr = ( char * ) allocate( str.length );
        memcpy( cstr, str.data, str.length );
        cstr[ str.length ] = 0;
        return cstr;
    }


    inline bool operator==( const string_t &str1, const string_t &str2 )
    {
        if ( str1.length != str2.length ) {
            return false;
        }
        for ( size_t i = 0;
              ( i < str1.length ) || ( i < str2.length );
              ++i ) {
            if ( str1.data[i] != str2.data[i] ) {
                return false;
            }
        }
        return true;
    }

    inline bool operator==( const char *str1, const string_t &str2 )
    {
        return strncmp( str1, ( const char *) str2.data, str2.length ) == 0;
    }

    inline bool operator==( const string_t &str1, const char *str2 )
    {
        return strncmp( ( const char *) str1.data, str2, str1.length ) == 0;
    }

    inline bool operator!=( const string_t &str1, const string_t &str2 )
    {
        return !( str1 == str2 );
    }

    inline bool operator!=( const char *str1, const string_t &str2 )
    {
        return strncmp( str1, ( const char *) str2.data, str2.length ) != 0;
    }

    inline bool operator!=( const string_t &str1, const char *str2 )
    {
        return strncmp( ( const char *) str1.data, str2, str1.length ) != 0;
    }
}


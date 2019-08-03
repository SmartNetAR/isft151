size_t strlen_t( const char* string, size_t len )
{
    if ( string == nullptr || *string == '\0' ) return len ;
    return strlen_t( ++string, len + 1 ) ;
}

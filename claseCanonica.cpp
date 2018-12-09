
class X {
    public:
        x( void ) ;                     // void constructor X x ; => X x.X( void ) ;
        x( int ) ;                      // type constructor X x = 10 ; => X x.X( 10 ) ;
        x( const &x ) ;                 // copy constructor X x = x ;
        x& operator =( const &x ) ;

        virtual ~x( void ) ;            // virtual destructor
}
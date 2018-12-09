//
// for ( int i = 10; i > 0; i-- ) std::cout << i << std::endl ;
//
template< template Type, typename Condition, typename Action, typename Step >
void loop( Type ctrl )
{
    if ( Condition::eval( ctrl ) ) return ;
    
    Action::eval( ctrol ) ;
    
    return loop<Type, Condition, Action, Step>( Step::eval( ctrl ))
}

template< typename Type >
struct condition
{
    static bool eval( Type item )
    {
        return item == 0 ;
    }
};

template< typename Type >
struct step
{
    static Type eval( Type item )
    {
        return --item ;
    }
};

//
// 2 to 5 do: [ :item | Transcript show: item; cr ]
//
template< typename InitialValue, typename LastValue, typename Block >
void iterate( int step = 0 )
{
    if ( InitialValue::value + step > LastValue::value ) return ;
    Block::eval( InitialValue::value + step ) ;
    return iterate<InitalValue, LastValue, Block>( ++steep ) ;
}

template< int integer >
struct starting
{
    enum { value = integer } ;
};

template< int integer >
struct ending
{
    enum { value = integer } ;
};
//
// from<2>::to<5>::step<1>::do< block<int> >() ;
//
template< int initialValue >
struct from
{
    template< int lastValue >
    struct to
    {
        template < int incValue >
        struct step
        {
            
        }
    };
};

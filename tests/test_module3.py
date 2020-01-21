
import module3 as m

def module_test( name ) :
    def ext_decorator( func ) :
        def ext_function() :
            print( '*************************************************************' )
            print( 'STARTING TEST {}'.format( name ) )
            func()
            print( 'FINISHED TEST {}'.format( name ) )
            print( '*************************************************************' )
        return ext_function
    return ext_decorator

@module_test( 'scope-testing::elements' )
def test_1() :
    elm1 = m.Element( 'elm-1' )

@module_test( 'scope-testing::containers' )
def test_2() :
    cont = m.Container( 'test_2 - cont-1' )
    elm1 = m.Element( 'test_2 - elm-1' )
    elm2 = m.Element( 'test_2 - elm-2' )
    cont.addElement( elm1 )
    cont.addElement( elm2 )

@module_test( 'shared-testing::containers' )
def test_3() :
    def factory( container ) :
        container.addElement( m.Element( 'test_3 - elm-1' ) )
        container.addElement( m.Element( 'test_3 - elm-2' ) )
    cont = m.Container( 'test_3 - cont-1' )
    factory( cont )

@module_test( 'scope-testing::getter' )
def test_4() :
    cont = m.Container( 'test_4 - cont-1' )
    elm1 = m.Element( 'test_4 - elm-1' )
    elm2 = m.Element( 'test_4 - elm-2' )
    cont.addElement( elm1 )
    cont.addElement( elm2 )

    elms = cont.elements()
    print( 'elms: ', elms )

@module_test( 'shared-testing::getter' )
def test_5() :
    def factory( container ) :
        container.addElement( m.Element( 'test_5 - elm-1' ) )
        container.addElement( m.Element( 'test_5 - elm-2' ) )
        return container.elements()
    cont = m.Container( 'test_5 - cont-1' )
    elms = factory( cont )
    del cont
    print( 'nulling obj-list' )
    elms = None
    print( 'done nulling, should have release list\'s elements' )

@module_test( 'shared-testing::getter-2' )
def test_6() :
    def factory( container ) :
        container.addElement( m.Element( 'test_6 - elm-1' ) )
        container.addElement( m.Element( 'test_6 - elm-2' ) )
        return container.elements()
    cont = m.Container( 'test_6 - cont-1' )
    elms = factory( cont )
    print( 'nulling obj-list' )
    elms = None
    print( 'done nulling, SHOULDN\'T have release list\'s elements' )
    del cont

if __name__ == '__main__' :
    test_1()
    test_2()
    test_3()
    test_4()
    test_5()
    test_6()
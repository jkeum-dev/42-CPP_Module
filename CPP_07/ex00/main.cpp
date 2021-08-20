#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "-------------------------" << std::endl;

	/* ***** Evaluation Code ***** */
	Awesome e(10);
	Awesome f(20);
	::swap( e, f );
	std::cout << "e = " << e.getN() << ", f = " << f.getN() << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ).getN() << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ).getN() << std::endl;
	return 0;
}

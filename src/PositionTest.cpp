#include "doctest.h"
#include"Position.h"
/***** TESTS FOR POSITION.CPP ***

TEST_CASE( "Position" ) {
	 Position p(10,20);
	 SUBCASE( "fx x et y" ) {
	 	REQUIRE_EQ( p.x() , 10);
	 	REQUIRE_EQ( p.y() , 20);
	 }
	 SUBCASE( "Tests d'affectations" ) {
	 	SUBCASE("changer la position de x"){
	 		p.x(55);
	 		REQUIRE_EQ( p.x() , 55);
	 	}
	 	SUBCASE("changer la position de y"){
	 		p.y(60);
	 		REQUIRE_EQ( p.y() , 60);
	 	}
	 	SUBCASE("changer la position de x et y"){
	 		p.xy(2.5,28.6);
	 		REQUIRE_EQ( p.x() , 2.5);
	 		REQUIRE_EQ( p.y() , 28.6);
	 	}
	 }
	 SUBCASE("La distance"){
	 	SUBCASE("calcuper la distance a partir d'une autre position p"){
	 		Position p2(20,50);
	 		REQUIRE_EQ(p1.distance(p2),doctest::Approx(31.6228));
	 	}
	 	SUBCASE("calcuper la distance a partir de coordonnées x et y"){
	 		REQUIRE_EQ(p1.distance(20,50),doctest::Approx(31.6228));
	 	}
	 }


}
*/

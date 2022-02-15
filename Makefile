rt1d-src=roots-1d

roots1d: bin/${rt1d-src}/bisection.o bin/${rt1d-src}/solution.o bin/${rt1d-src}/iterative.o
	g++ -o tests/roots1d src/${rt1d-src}/tests.cpp bin/${rt1d-src}/bisection.o bin/${rt1d-src}/solution.o bin/${rt1d-src}/iterative.o

bin/${rt1d-src}/solution.o: src/${rt1d-src}/solution.h
	g++ -c src/${rt1d-src}/solution.cpp -o bin/${rt1d-src}/solution.o

bin/${rt1d-src}/iterative.o: src/${rt1d-src}/roots.h
	g++ -c src/${rt1d-src}/iterative.cpp -o bin/${rt1d-src}/iterative.o

bin/${rt1d-src}/bisection.o: src/${rt1d-src}/roots.h
	g++ -c src/${rt1d-src}/bisection.cpp -o bin/${rt1d-src}/bisection.o

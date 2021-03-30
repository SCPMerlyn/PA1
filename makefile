URL: URLParser.o version.o
	g++ URLParser.o version.o -o URL

URLParser.o: URLParser.cpp
	g++ -c URLParser.cpp

version.o: version.cpp
	g++ -c version.cpp

clean:
	rm *.o URL
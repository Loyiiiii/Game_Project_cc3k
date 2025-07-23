CXX =  g++-14 -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
SOURCES = racer.cc racer-impl.cc tortoise.cc tortoise-impl.cc hare.cc hare-impl.cc main.cc
HEADERS = iostream
EXEC = a.out

$(EXEC): $(SOURCES)
	$(CXX) $(HEADERFLAGS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)
	rm -rf gcm.cache

.PHONY: clean 
clean:
	rm -f $(EXEC)

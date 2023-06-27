g++ -c minhadll.cpp
g++ -shared -o minhadll.dll minhadll.o -Wl,--out-implib,minhadll.a
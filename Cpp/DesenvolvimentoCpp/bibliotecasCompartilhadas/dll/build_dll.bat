g++ -c -DBUILD_MY_DLL minhadll.cpp
g++ -shared -o minhadll.dll minhadll.o -Wl,--out-implib,minhadll.a
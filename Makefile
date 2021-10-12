GCC = C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++ 
main: main.o load.dll array.dll matrix.dll
	$(GCC) -o main main.o -L. -lload
main.o: main.cpp
	$(GCC) -c -fPIC main.cpp
load.dll: load.o
	$(GCC) -shared -o load.dll load.o
load.o: load.cpp
	$(GCC) -c -fPIC load.cpp
array.dll: array.o
	$(GCC) -shared -o array.dll array.o
array.o: array.cpp
	$(GCC) -c -fPIC array.cpp
matrix.dll: matrix.o
	$(GCC) -shared -o matrix.dll matrix.o
matrix.o: matrix.cpp
	$(GCC) -c -fPIC matrix.cpp
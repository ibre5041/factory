rm -f *.so*
rm -f test1 test2

echo test1
echo g++ -O0 -ggdb3 test1.cpp SubClass1.cpp -o test1
g++ -O0 -ggdb3 test1.cpp SubClass1.cpp -o test1

echo test2
echo echo g++ -O0 -ggdb3 -fPIC -DTEST_DLL SubClass1.cpp -shared -Wl,-soname,libSubClass1.so.1 -rdynamic -o libSubClass1.so.1.0.1
echo ln -sf libSubClass1.so.1.0.1 libSubClass1.so
echo g++ -O0 -ggdb3 test2.cpp -ldl -rdynamic -o test2
g++ -O0 -ggdb3 -fPIC -DTEST_DLL SubClass1.cpp -shared -Wl,-soname,libSubClass1.so.1 -rdynamic -o libSubClass1.so.1.0.1
ln -sf libSubClass1.so.1.0.1 libSubClass1.so
g++ -O0 -ggdb3 -DTEST_MAKE_DLL test2.cpp -ldl -rdynamic -o test2


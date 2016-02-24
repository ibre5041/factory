CXXFLAGS=-ggdb3 -O0 -I. -Iloki -D_HAVE_GCC_VISIBILITY
LDFLAGS=-rdynamic

all: test1 test2 libsubclass1

test1: test1.cpp test_export.h SubClass1.h SubClass1.cpp ABaseClass.h
	g++ $(CXXFLAGS) test1.cpp SubClass1.cpp -o test1

test2: test2.cpp test_export.h ABaseClass.h
	g++ $(CXXFLAGS) $(LDFLAGS) -DTEST_DLL test2.cpp -ldl -o test2

libsubclass1: SubClass1.h SubClass1.cpp ABaseClass.h test_export.h
	g++ $(CXXFLAGS) -fPIC -DTEST_MAKE_DLL SubClass1.cpp -shared -Wl,-soname,libSubClass1.so.1 $(LDFLAGS) -o libSubClass1.so.1.0.1
	ln -sf libSubClass1.so.1.0.1 libSubClass1.so

clean:
	rm -f test1 test2 *.so*

.PHONY: clean
#### For dynamic lib 
> a.cpp => liba.so
  b.cpp, liba.so => libb.so
  c.cpp, liba.so, libb.so => test

```
$ cd build
$ gcc ../src/a.cpp -shared -o liba.so # a.cpp => liba.so
$ gcc ../src/b.cpp -shared -L ../build -la  -o libb.so # b.cpp, liba.so => libb.so
$ gcc ../src/c.cpp -L ../build -la -lb -o test # c.cpp, liba.so, libb.so => test
$ ./test
6 - 113
```

#### For static lib
> a.cpp => liba.a
  b.cpp, liba.a => libb.a
  c.cpp, liba.a, libb.a => test

```
$ cd build
$ gcc -c ../src/a.cpp -o a.o
$ ar -rv liba.a a.o # a.cpp => liba.a
$ rm a.o
$ gcc -c ../src/b.cpp -o b.o
$ ar -xv libb.a
$ ar -rv liba.a a.o b.o # liba.a, b.cpp => libb.a
$ gcc test.cpp -L. -lb -o c #  
$ ./c
Result is: 6 - 666
```
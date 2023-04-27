all: test.exe

test.exe: test.obj
    link test.obj

test.obj: test.c
    cl /c test.c

clean:
    del *.obj *.exe

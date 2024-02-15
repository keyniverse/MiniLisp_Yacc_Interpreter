bison -d -o MiniLisp.tab.c MiniLisp.y	
gcc -c -std=gnu99 -g -I.. MiniLisp.tab.c
flex -o MiniLisp.yy.c MiniLisp.l
gcc -c -std=gnu99 -g -I.. MiniLisp.yy.c
gcc -o MiniLisp MiniLisp.tab.o MiniLisp.yy.o -ll
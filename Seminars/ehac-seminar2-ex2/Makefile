all: maliciouslib atbash
	cc -o atbash atbash.c

maliciouslib:
	cc maliciouslib.c -o maliciouslib.so -fPIC -shared -ldl

clean:
	rm -rf *.o *.so atbash

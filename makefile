triangles3d: parse_util.o mat4.o triangles3d.c 
	gcc triangles3d.c mat4.o parse_util.o -o triangles3d -lm

mat4.o: mat4.c mat4.h
	gcc mat4.c -c

parse_util.o: parse_util.c parse_util.h
	gcc parse_util.c -c

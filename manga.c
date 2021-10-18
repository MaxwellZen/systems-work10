#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct manga {
	char title[50];
	int chapters;
	struct manga *next;
};

void print_manga(struct manga *a) {
	printf("The %s manga is %d chapters long!\n", a->title, a->chapters);
}

struct manga* set_manga(char *s, int c) {
	struct manga *a = malloc(sizeof(struct manga));
	strcpy(a->title, s);
	a->chapters = c;
	a->next = 0;
	return a;
}

void print_list(struct manga *a) {
	while (a) {
		print_manga(a);
		a = a->next;
	}
}

struct manga * insert_front(struct manga *a, char *s, int c) {
	struct manga *add = set_manga(s, c);
	add->next = a;
	return add;
}

struct manga * free_list(struct manga *a) {
	while (a) {
		struct manga *b = a->next;
		free(a);
		a = b;
	}
	return 0;
}

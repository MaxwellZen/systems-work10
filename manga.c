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
	printf("%s - %d chapters long", a->title, a->chapters);
}

struct manga* set_manga(char *s, int c) {
	struct manga *a = malloc(sizeof(struct manga));
	strcpy(a->title, s);
	a->chapters = c;
	a->next = 0;
	return a;
}

void print_list(struct manga *a) {
	printf("[ ");
	while (a) {
		print_manga(a);
		if (a->next) printf(" | ");
		a = a->next;
	}
	printf(" ]\n");
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
	return a;
}

int equals(struct manga* a, char* s, int c) {
	return strcmp(a->title, s)==0 && a->chapters==c;
}

struct manga * remove_node(struct manga *front, char* s, int c) {
	if (equals(front, s, c)) {
		struct manga *ans = front->next;
		free(front);
		return ans;
	}
	struct manga *ans = front, *prev = front, *cur = front->next;
	while (cur) {
		if (equals(cur, s, c)) {
			prev->next = cur->next;
			free(cur);
			return ans;
		}
		prev = cur;
		cur = cur->next;
	}
	return ans;
}

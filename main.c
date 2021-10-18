#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "manga.h"

int main() {
	struct manga* a = 0;
	a = insert_front(a, "One Piece", 1028);
	a = insert_front(a, "Black Clover", 309);
	a = insert_front(a, "My Hero Academia", 330);
	print_list(a);
	free_list(a);
	return 0;
}

struct manga {
	char title[50];
	int chapters;
	struct manga *next;
};

void print_manga(struct manga *a);
struct manga* set_manga(char *s, int c);
void print_list(struct manga *a);
struct manga * insert_front(struct manga *a, char *s, int c);
struct manga * free_list(struct manga *a);

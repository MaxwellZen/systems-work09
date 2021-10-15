#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct manga { char title[50]; int chapters; };

void print_manga(struct manga *a) {
	printf("The %s manga is %d chapters long!\n", a->title, a->chapters);
}

struct manga* set_manga(char *s, int c) {
	struct manga *a = malloc(sizeof(struct manga));
	strcpy(a->title, s);
	a->chapters = c;
	return a;
}

int main() {
	srand(time(NULL));
	printf("Some manga you may be interested in reading:\n");
	char names[10][50];
	strcpy(names[0], "One Piece");
	strcpy(names[1], "Tokyo Revengers");
	strcpy(names[2], "Fire Force");
	strcpy(names[3], "Vinland Saga");
	strcpy(names[4], "Choujin X");
	strcpy(names[5], "Black Clover");
	strcpy(names[6], "Jujutsu Kaisen");
	strcpy(names[7], "My Hero Academia");
	strcpy(names[8], "Berserk");
	strcpy(names[9], "One Punch Man");

	int k = -1, i;
	for (i = 2; i >= 0; i--) {
		k = rand()%(9-k-i) + k + 1;
		printf("\nRecommendation #%d:\n", 3-i);
		struct manga* rec = set_manga(names[k], rand()%500+50);
		print_manga(rec);
		free(rec);
	}
}

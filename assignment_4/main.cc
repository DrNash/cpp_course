#include "scribe.h"

int main (int argc, char **argv) {
	Scribe myEditor = Scribe("test/sample_text.txt");

	myEditor.show_word_stats();
	return 0;
}
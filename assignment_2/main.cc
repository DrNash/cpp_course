#include "scribe.h"
#include "timer.cc"

int main(int argc, char **argv) {
  ESTLUtils::Timer t;
  Scribe myEditor = Scribe("test/lorem_test.txt");
  for(int i = 0; i < 50; ++i) {
	  myEditor.mark();
	  myEditor.add_line("agittis, libero diam tristique lorem,"
	  	" sit amet euismod massa dolor non lacus. Donec pharetra"
	  	" augue nec nisl facilisis volutpat. Phasellus eget nunc e"
	  	"rat. Nunc luctus quam nec lectus dignissim sit amet ultri");
	  myEditor.undo();
	  myEditor.undo();
	  myEditor.mark_portion("agittis", "lacus");
	  myEditor.insert("lectus");
	  myEditor.insert("Curabitur");
	  myEditor.insert("lectus");
	  myEditor.insert("Curabitur");
	  myEditor.delete_phrase("euismod massa dolor non lacus");
	  myEditor.delete_phrase("sapien");
	  myEditor.substitute_phrase("vel", "donkey donkey donkey");
	  myEditor.open_file("test/lorem_test.txt");
	  myEditor.mark();
	  myEditor.add_line("agittis, libero diam tristique lorem,"
	  	" sit amet euismod massa dolor non lacus. Donec pharetra"
	  	" augue nec nisl facilisis volutpat. Phasellus eget nunc e"
	  	"rat. Nunc luctus quam nec lectus dignissim sit amet ultri");
	  myEditor.add_line("agittis, libero diam tristique lorem,"
	  	" sit amet euismod massa dolor non lacus. Donec pharetra"
	  	" augue nec nisl facilisis volutpat. Phasellus eget nunc e"
	  	"rat. Nunc luctus quam nec lectus dignissim sit amet ultri");
	  myEditor.add_line("agittis, libero diam tristique lorem,"
	  	" sit amet euismod massa dolor non lacus. Donec pharetra"
	  	" augue nec nisl facilisis volutpat. Phasellus eget nunc e"
	  	"rat. Nunc luctus quam nec lectus dignissim sit amet ultri");
	  myEditor.add_line("agittis, libero diam tristique lorem,"
	  	" sit amet euismod massa dolor non lacus. Donec pharetra"
	  	" augue nec nisl facilisis volutpat. Phasellus eget nunc e"
	  	"rat. Nunc luctus quam nec lectus dignissim sit amet ultri");
	  myEditor.undo();
	}
  std::cout << "Tests done, took: " << (double)t << "\n";
  return 0;
}
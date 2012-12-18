#include <string>
#include <fstream>

class IDGen {
private:
	long uniqueish_id;
	std::string id_filename;
public:
	IDGen();

	static void clear();
	static long get_id();
};
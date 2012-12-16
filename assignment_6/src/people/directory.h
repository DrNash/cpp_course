#include <vector>
#include "user.h"

class Directory {
private:
	std::vector<User> employees;

public:
	User get_employee();
	bool authenticate_employee(User);
};
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <streambuf>

using namespace std;
int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <path-to-executable>\n";
		return 0;
	}
	
	string cmd = "valgrind --tool=lackey --trace-mem=yes --log-file=\"memtrace\" ";
	cmd += argv[1];
	cmd += " >/dev/null";
	
	cout << cmd << "\n";
	int res = system(cmd.c_str());
	
	if (res != 0) {
		cout << "Valigrind failed\n";
		return res;
	}

}


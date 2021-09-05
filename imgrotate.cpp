#include <iostream>
#include <fstream>
#include <unistd.h>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main(int argc, char** argv) {
    InitializeMagick(*argv);
    double angle = 0;
    string outfile;

    while (true) {
        char ch = getopt(argc, argv, "a:o:");
        if (ch == -1)
            break;
        else {
            switch (ch) {
                case 'a':
                    try {
                        angle = stoi(optarg);
                    } catch (const exception &e) {
                        cerr << "Invalid angle : " << optarg << '\n';
                        return -1;
                    }
                    break;
                case 'o':
                    outfile = optarg;
                    break;
            }
        }
    }

    Image img;
    try {
        img.read(argv[optind]);
        img.rotate(angle);
        img.write(outfile);
    } catch (const exception &e) {
        cout << e.what() << '\n';
    }
}

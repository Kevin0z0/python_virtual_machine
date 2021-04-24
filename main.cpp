#include "utils/BufferedInputStream.hpp"
#include "code/BinaryFileParser.hpp"
#include "runtime/Interpreter.hpp"

int main() {
    setbuf(stdout, nullptr); // debug用 把缓冲区与流相连
    char path[] = R"(C:\Users\zkw\Desktop\python_virtual_machine\__pycache__\test_func_4.pyc)";
    BufferedInputStream stream(path);
    BinaryFileParser bfp(&stream);
    CodeObject *mainCode = bfp.parse();
    mainCode->print();
    printf("\n");
    Interpreter interpreter{};
    interpreter.run(mainCode);
    return 0;
}

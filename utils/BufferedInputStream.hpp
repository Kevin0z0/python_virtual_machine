#ifndef BUFFERED_INPUT_STREAM_HPP
#define BUFFERED_INPUT_STREAM_HPP

#include <cstdio>

#define BUFFER_LEN 256

class BufferedInputStream{
public:
    explicit BufferedInputStream(char const *filename){
        fp = fopen(filename, "rb");
        readFileChar();
        index = 0;
    }

    ~BufferedInputStream(){
        close();
    }

    void readFileChar(){
        fread(szBuffer,  sizeof(char), BUFFER_LEN, fp);
    }

    char read(){
        if(index >= BUFFER_LEN){
            index = 0;
            readFileChar();
        }
        return szBuffer[index++];
    }

    int read_int(){
        int b1 = read() & 0xff;
        int b2 = read() & 0xff;
        int b3 = read() & 0xff;
        int b4 = read() & 0xff;
        return b4 << 24 | b3 << 16 | b2 << 8 | b1;
    }

    void unread(){
        index--;
    }

    void close(){
        if(fp != nullptr){
            fclose(fp);
            fp = nullptr;
        }
    }

private:
    FILE *fp;
    char szBuffer[BUFFER_LEN]{};
    unsigned short index;
};

#endif
//
// Created by 97862 on 2023/2/22.
//

#ifndef DEMO_BYTEBUF_H
#define DEMO_BYTEBUF_H

#include <cstdint>

class ByteBuf {
public:
    ByteBuf();

    ByteBuf(uint8_t data[], int size);

};

#endif //DEMO_BYTEBUF_H

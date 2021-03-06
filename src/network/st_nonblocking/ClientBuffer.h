#ifndef AFINA_NETWORK_ST_NONBLOCKING_CLIENTBUFFER_H
#define AFINA_NETWORK_ST_NONBLOCKING_CLIENTBUFFER_H

#include <cstring>

namespace Afina {
namespace Network {
namespace STnonblock {

class ClientBuffer {
public:
    ClientBuffer();
    ~ClientBuffer();
    char* ptr();
    char* read_ptr();
    char* parse_ptr();
    std::size_t size();
    std::size_t read_size();
    std::size_t parse_size();
    void read(std::size_t amount);
    void parsed(std::size_t amount);
    void reset();
    void conditional_reset();

private:
    static const std::size_t _size = 4096;
    char buffer[_size];
    std::size_t read_offset = 0;
    std::size_t parsed_offset = 0;
    static const std::size_t minsize = 100;
};

} // namespace STnonblock
} // namespace Network
} // namespace Afina

#endif // AFINA_NETWORK_ST_NONBLOCKING_CLIENTBUFFER_H

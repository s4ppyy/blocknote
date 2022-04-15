#pragma once
#include <cstdio>
#include <string>
#include <vector>

namespace IO {
    class IfStream {
    public:
        IfStream() = default;

        IfStream(const std::string& file_name);

        IfStream(FILE* in);

        friend IfStream& operator>>(IfStream& in, std::string& a);

        friend IfStream& operator>>(IfStream& in, int& a);

        friend IfStream& operator>>(IfStream& in, float& a);

        void open(const std::string& file_name);

        std::string name();

        void close();

        operator bool();

    private:
        FILE* file_{};
        std::string file_name_;
        bool eof_{};
    };
}

#pragma once

#include <cstdio>
#include <string>
#include <vector>

namespace IO {
    class OfStream {
    public:
        OfStream() = default;

        OfStream(const std::string& file_name);

        OfStream(FILE* out);

        friend OfStream& operator<<(OfStream& out, const std::string& a);

        friend OfStream& operator<<(OfStream& out, const int& a);

        friend OfStream& operator<<(OfStream& out, const float& a);

        void open(const std::string& file_name);

        std::string name();

        void close();

    private:
        FILE* file_;
        std::string file_name_;
    };
}

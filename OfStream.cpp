#include "OfStream.h"

namespace IO {
    OfStream::OfStream(const std::string& file_name)
        : file_(fopen(file_name.c_str(), "w")),
        file_name_(file_name) {
    }

    OfStream::OfStream(FILE* out)
        : file_(out),
        file_name_("") {
    }

    OfStream& operator<<(OfStream& out, const int& a) {
        fprintf(out.file_, "%d", a);
        return out;
    }

    OfStream& operator<<(OfStream& in, const float& a) {
        fprintf(in.file_, "%f", a);
        return in;
    }

    OfStream& operator<<(OfStream& out, const std::string& a) {
        fputs(a.c_str(), out.file_);
        return out;
    }

    void OfStream::open(const std::string& file_name) {
        file_name_ = file_name;
        file_ = fopen(file_name.c_str(), "w");
    }

    std::string OfStream::name() {
        return file_name_;
    }

    void OfStream::close() {
        fclose(file_);
    }
}
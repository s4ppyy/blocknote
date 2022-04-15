#include "IfStream.h"

namespace IO {

    IfStream::IfStream(const std::string& file_name)
        : file_(fopen(file_name.c_str(), "r")),
        file_name_(file_name), eof_(false) {
    }

    IfStream::IfStream(FILE* in)
        : file_(in),
        file_name_(""), eof_(false) {
    }

    IfStream& operator>>(IfStream& in, int& a) {
        in.eof_ = fscanf(in.file_, "%d", std::addressof(a)) == EOF;
        return in;
    }

    IfStream& operator>>(IfStream& in, float& a) {
        in.eof_ = fscanf(in.file_, "%f", std::addressof(a)) == EOF;
        return in;
    }

    IfStream& operator>>(IfStream& in, std::string& a) {
        int ch;
        a.clear();
        do {
            ch = fgetc(in.file_);
        } while (ch == ' ' || ch == '\n' || ch == '\t');
        while (ch != EOF && ch != ' ' && ch != '\n' && ch != '\t') {
            a.push_back(static_cast<char>(ch));
            ch = fgetc(in.file_);
        }
        in.eof_ = ch == EOF;
        return in;
    }

    void IfStream::open(const std::string& file_name) {
        file_name_ = file_name;
        file_ = fopen(file_name.c_str(), "r");
        eof_ = false;
    }

    std::string IfStream::name() {
        return file_name_;
    }

    void IfStream::close() {
        fclose(file_);
    }

    IfStream::operator bool() {
        return !eof_;
    }
}


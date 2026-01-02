/*
 * basic_io.h
 * @author: Sean Kelly
 * @date: Jan 1, 2026
 * @description: This is an abstract class to tie input and output together.
 * Because both input and output will need an _iobuf, this is where it becomes
 * a member within the class family
 */
#pragma once

namespace sk {
    /*
    * abstract class basic_io.
    * Members:
    *  - struct FILE - An IO buffer to track input and output before flushing to the proper source
    */
    class basic_io {
    public:
        virtual basic_io() = 0;
        virtual ~basic_io() = 0;

        int get_cnt() {return buffer._cnt;}
        char * get_ptr() {return buffer._ptr;}
        char * get_base() {return buffer._base;}
        int get_flag() {return buffer._flag;}			// file status flags
        int get_file() {return buffer._file;}			// file descriptor
        int get_charbuf() {return buffer._charbuf;}		// character buffer
        int get_bufsiz() {return buffer._bufsiz;}		// buffer size
        char* get_tmpfname() {return buffer._tmpfname;}	// temporary file name

        void set_cnt(int new_cnt) {buffer._cnt = new_cnt;}
        void set_ptr(char * new_ptr) {buffer._ptr = new_ptr;}
        void get_base(char * new_base) {buffer._base = new_base;}
        void set_flag(int new_flag) {buffer._flag = new_flag;}		        // file status flags
        void set_file(int new_file) {buffer._file = new_file;}		        // file descriptor
        void set_charbuf(int new_charbuf) {buffer._charbuf = new_charbuf;}	// character buffer
        void set_bufsiz(int new_bufsiz) {buffer._bufsiz = new_bufsiz;}		// buffer size
        void set_tmpfname(char * new_tmpfname) {buffer._tmpfname = new_tmpfname;}	// temporary file name

        FILE * get_iobuf() {return &buffer;}
    protected:
        FILE buffer;
    };
}
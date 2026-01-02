#include <cstdio>

#include <systemk/basic_out.h>
#include <systemk/vga_out.h>

using namespace sk;

extern {
    bool attach_to_stdout(basic_tty_out * out) {
        if(NULL != (stdout->_base = out->characterBuffer)) {
            stdout->_cnt = out->TTY_BUFFER_SIZE;
            stdout->_ptr = out->characterBuffer;
            stdout->_flag = _WRITE;
            stdout->
        }
        return false;
    }

    // I don't have enough yet to do this part
    bool attach_to_stdin(void) {

    }

    bool attach_to_stderr(basic_tty_out * out) {
        return false;
    } 
}
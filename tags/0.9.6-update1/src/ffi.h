/*
    Ypsilon Scheme System
    Copyright (c) 2004-2008 Y.FUJITA / LittleWing Company Limited.
    See license.txt for terms and conditions of use
*/

#include "core.h"

#define FFI_MAX_ARGC    32

struct c_stack_frame_t {
    c_stack_frame_t(VM* vm) : m_vm(vm), m_count(0) {}
    intptr_t m_frame[FFI_MAX_ARGC];
    VM* m_vm;
    int m_count;
    const char* push(scm_obj_t obj);
};

extern "C" {

    int         c_callback_int(uint32_t uid, uint32_t argc, uint32_t* base);

#if _MSC_VER
    double      stdcall_func_stub_double(void* func, int argc, intptr_t argv[]);
    intptr_t    stdcall_func_stub_intptr(void* func, int argc, intptr_t argv[]);
#endif

    double      c_func_stub_double(void* func, int argc, intptr_t argv[]);
    intptr_t    c_func_stub_intptr(void* func, int argc, intptr_t argv[]);
    int         c_callback_stub_int();

}

scm_obj_t make_callback(VM* vm, int type, int argc, scm_closure_t closure);

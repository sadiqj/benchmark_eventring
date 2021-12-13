#define CAML_INTERNALS

#include "caml/mlvalues.h"
#include "caml/memory.h"
#include "caml/eventring.h"

value benchmark_ev_begin_end(value iterations) {
    CAMLparam0();

    for( int c = Long_val(iterations); c > 0 ; c-- ) {
        caml_ev_begin(EV_MINOR);
        caml_ev_end(EV_MINOR);
    }

    CAMLreturn(Val_unit);
}

value benchmark_ev_counter(value iterations) {
    CAMLparam0();

    for( int c = Long_val(iterations); c > 0 ; c-- ) {
        caml_ev_counter(EV_C_MINOR_PROMOTED, 0);
    }

    CAMLreturn(Val_unit);
}

value benchmark_ev_lifecycle(value iterations) {
    CAMLparam0();

    for( int c = Long_val(iterations); c > 0 ; c-- ) {
        caml_ev_lifecycle(EV_RING_START, 0);
    }

    CAMLreturn(Val_unit);
}
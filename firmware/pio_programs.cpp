#include "pio_programs.h"

#if defined(SLAVTEK)
#include "comms_stek.pio.h"
#include "data_bus_stek.pio.h"
#else
#include "comms.pio.h"
#include "data_bus.pio.h"
#endif
#include <hardware/pio.h>

PIOProgram prg_comms_detect;
#if defined(FEATURE_CLOCK)
PIOProgram prg_comms_clock;
#endif
#if !defined(SLAVTEK)
PIOProgram prg_write_tca_bits;
#endif
PIOProgram prg_data_output;
PIOProgram prg_set_output_enable;
PIOProgram prg_set_pindir_hi;
PIOProgram prg_set_pindir_lo;
PIOProgram prg_report_data_access;


#define add_program(p, s, name, prg) \
    do \
    { \
        prg.pio_index = PIO_NUM(p); \
        prg.sm = s; \
        prg.config_func = name ## _program_get_default_config; \
        prg.offset = pio_add_program(p, &name ## _program); \
        if (prg.offset < 0) return false; \
    } while(false)


void pio_programs_reset()
{
    pio_clear_instruction_memory(pio0);
    pio_clear_instruction_memory(pio1);

    prg_comms_detect.reset();
#if defined(FEATURE_CLOCK)
    prg_comms_clock.reset();
#endif
#if !defined(SLAVTEK)
    prg_write_tca_bits.reset();
#endif
    prg_data_output.reset();
    prg_set_output_enable.reset();
    prg_set_pindir_hi.reset();
    prg_set_pindir_lo.reset();
}


bool pio_programs_init()
{
    pio_programs_reset();

    add_program(pio0, 0, set_pindir, prg_set_pindir_lo);
    prg_set_pindir_hi = prg_set_pindir_lo;
    prg_set_pindir_hi.sm = 1;
    add_program(pio0, 2, comms_detect, prg_comms_detect);
    add_program(pio0, 3, data_output, prg_data_output);

    add_program(pio1, 0, set_output_enable, prg_set_output_enable);
    add_program(pio1, 1, report_data_access, prg_report_data_access);
#if defined(FEATURE_CLOCK)
    add_program(pio1, 2, comms_clock, prg_comms_clock);
#endif
#if !defined(SLAVTEK)
    add_program(pio1, 3, write_tca_bits, prg_write_tca_bits);
#endif

    return true;
}

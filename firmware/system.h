#if !defined(SYSTEM_H)
#define SYSTEM_H 1

#include <stdint.h>

static constexpr uint32_t N_DATA_PINS = 8;
static constexpr uint32_t BASE_DATA_PIN = 22;
static constexpr uint32_t DATA_PIN_MASK = ((1 << N_DATA_PINS) - 1) << BASE_DATA_PIN;

#if defined(SLAVTEK)
static constexpr uint32_t N_OE_PINS = 1;
#else
static constexpr uint32_t N_OE_PINS = 2;
#endif

static constexpr uint32_t CS_PIN_BASE = 20;
//~ static constexpr uint32_t OE_PIN_MASK = ((1 << N_OE_PINS) - 1) << CS_PIN_BASE;

#if defined(FEATURE_CLOCK)
static constexpr uint32_t CLOCK_PIN = 17;
static constexpr uint32_t N_ADDR_PINS = 17;
#else
static constexpr uint32_t N_ADDR_PINS = 18;
#endif

static constexpr uint32_t BASE_ADDR_PIN = 0;
static constexpr uint32_t ADDR_PIN_MASK = ((1 << N_ADDR_PINS) - 1) << BASE_ADDR_PIN;


static constexpr uint32_t BUF_OE_PIN = 19;
//~ static constexpr uint32_t BUF_OE_PIN_MASK = 1 << BUF_OE_PIN;

/* *********************** */
#if defined(SLAVTEK)
#define LS125
static constexpr uint32_t PCA_ADDR = 0x20;
static constexpr uint32_t PCA_SCL_PIN = 18;
static constexpr uint32_t PCA_SCL_PIN_MASK = 1 << PCA_SCL_PIN;
static constexpr uint32_t PCA_SDA_PIN = 21;
static constexpr uint32_t PCA_SDA_PIN_MASK = 1 << PCA_SDA_PIN;

static constexpr uint32_t PCA_RESET_VALUE_PIN = 1;
static constexpr uint32_t PCA_RESET_PIN = 0;
static constexpr uint32_t PCA_LINK_PIN = 2;
static constexpr uint32_t PCA_READ_PIN = 3;
#else
static constexpr uint32_t TCA_EXPANDER_PIN = 18;
static constexpr uint32_t TCA_EXPANDER_PIN_MASK = 1 << TCA_EXPANDER_PIN;

static constexpr uint32_t TCA_LINK_PIN = 1;
static constexpr uint32_t TCA_READ_PIN = 2;
static constexpr uint32_t TCA_RESET_VALUE_PIN = 3;
static constexpr uint32_t TCA_RESET_PIN = 4;
#endif 

static constexpr uint32_t ROM_SIZE = 0x40000;
static constexpr uint32_t ADDR_MASK = ((1 << N_ADDR_PINS) - 1);
static constexpr uint32_t FLASH_SIZE = 1 * 1024 * 1024;

static constexpr uint32_t STATUS_PIO_INIT = 0x00000001;

static constexpr uint32_t DMA_CH_FLASH = 0;
static constexpr uint32_t DMA_CH_CLOCK_PING = 2;
static constexpr uint32_t DMA_CH_CLOCK_PONG = 3;

/* if using 1G125 buffer instead of '126, buffer enable becomes active low */
#if defined(LS125)
#define RESET_ACTIVE false
#define RESET_INACTIVE true
#endif

#endif // SYSTEM_H

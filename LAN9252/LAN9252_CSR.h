#ifndef LAN9252_CSR_H_
#define LAN9252_CSR_H_

enum CSR : int {
    ECAT_PRAM_RD_DATA   = 0x000,
    ECAT_PRAM_WR_DATA   = 0x020,
    ID_REV              = 0x050,
    IRQ_CFG             = 0x054,
    INT_STS             = 0x058,
    INT_EN              = 0x05C,
    BYTE_TEST           = 0x064,
    HW_CFG              = 0x074,
    RMT_CTRL            = 0x084,
    GPT_CFG             = 0x08C,
    GPT_CNT             = 0x090,
    FREE_RUN            = 0x09C,

    // Reset Register
    RESET_CTL   = 0x1F8,

    // EtherCAT Register
    ECAT_CSR_DATA   = 0x300,
    ECAT_CSR_CMD    = 0x304,
    ECAT_PRAM_RD_ADDR_LEN   = 0x308,
    ECAT_PRAM_RD_CMD    = 0x30C,
    ECAT_PRAM_WE_ADDR_LEN   = 0x310,
    ECAT_PRAM_WR_CMD    = 0x314
};

#endif
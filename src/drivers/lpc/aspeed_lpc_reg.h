/*
 * Copyright (c) 2020-2021 Aspeed Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef _ASPEED_LPC_REG_H_
#define _ASPEED_LPC_REG_H_

/* LPC register offset */
#define	HICR0	0x000
#define		HICR0_LPC3E	BIT(7)
#define		HICR0_LPC2E	BIT(6)
#define		HICR0_LPC1E	BIT(5)
#define	HICR1	0x004
#define	HICR2	0x008
#define		HICR2_IBFIF3	BIT(3)
#define		HICR2_IBFIF2	BIT(2)
#define		HICR2_IBFIF1	BIT(1)
#define	HICR3	0x00c
#define	HICR4	0x010
#define		HICR4_LADR12AS	BIT(7)
#define		HICR4_KCSENBL	BIT(2)
#define	LADR3H	0x014
#define	LADR3L	0x018
#define	LADR12H	0x01c
#define	LADR12L	0x020
#define	IDR1	0x024
#define	IDR2	0x028
#define	IDR3	0x02c
#define	ODR1	0x030
#define	ODR2	0x034
#define	ODR3	0x038
#define	STR1	0x03c
#define	STR2	0x040
#define	STR3	0x044
#define	HICR5	0x080
#define		HICR5_ENINT_SNP1W	BIT(3)
#define		HICR5_EN_SNP1W		BIT(2)
#define		HICR5_ENINT_SNP0W	BIT(1)
#define		HICR5_EN_SNP0W		BIT(0)
#define	HICR6	0x084
#define		HICR6_STR_SNP1W	BIT(1)
#define		HICR6_STR_SNP0W	BIT(0)
#define	SNPWADR	0x090
#define		SNPWADR_ADDR1_MASK	GENMASK(31, 16)
#define		SNPWADR_ADDR1_SHIFT	16
#define		SNPWADR_ADDR0_MASK	GENMASK(15, 0)
#define		SNPWADR_ADDR0_SHIFT	0
#define	SNPWDR	0x094
#define		SNPWDR_DATA1_MASK	GENMASK(15, 8)
#define		SNPWDR_DATA1_SHIFT	8
#define		SNPWDR_DATA0_MASK	GENMASK(7, 0)
#define		SNPWDR_DATA0_SHIFT	0
#define	PCCR6	0x0c4
#define	PCCR4	0x0d0
#define	PCCR5	0x0d4
#define	HICRB	0x100
#define		HICRB_ENSNP1D	BIT(15)
#define		HICRB_ENSNP0D	BIT(14)
#define		HICRB_IBFIF4	BIT(1)
#define		HICRB_LPC4E	BIT(0)
#define	LADR4	0x110
#define	IDR4	0x114
#define	ODR4	0x118
#define	STR4	0x11c
#define		STR4_STAT_MASK		GENMASK(7, 6)
#define		STR4_STAT_SHIFT		6
#define	PCCR0	0x130
#define		PCCR0_EN_DMA_INT	BIT(31)
#define		PCCR0_EN_DMA_MODE	BIT(14)
#define		PCCR0_ADDR_SEL_MASK	GENMASK(13, 12)
#define		PCCR0_ADDR_SEL_SHIFT	12
#define		PCCR0_RX_TRIG_LVL_MASK	GENMASK(10, 8)
#define		PCCR0_RX_TRIG_LVL_SHIFT	8
#define		PCCR0_CLR_RX_FIFO	BIT(7)
#define		PCCR0_MODE_SEL_MASK	GENMASK(5, 4)
#define		PCCR0_MODE_SEL_SHIFT	4
#define		PCCR0_EN_RX_OVR_INT	BIT(3)
#define		PCCR0_EN_RX_TMOUT_INT	BIT(2)
#define		PCCR0_EN_RX_AVAIL_INT	BIT(1)
#define		PCCR0_EN		BIT(0)
#define	PCCR1	0x134
#define		PCCR1_DONT_CARE_BITS_MASK	GENMASK(21, 16)
#define		PCCR1_DONT_CARE_BITS_SHIFT	16
#define		PCCR1_BASE_ADDR_MASK		GENMASK(15, 0)
#define		PCCR1_BASE_ADDR_SHIFT		0
#define	PCCR2	0x138
#define		PCCR2_DMA_DONE		BIT(4)
#define		PCCR2_DATA_RDY		PCCR2_DMA_DONE
#define		PCCR2_RX_OVR_INT	BIT(3)
#define		PCCR2_RX_TMOUT_INT	BIT(2)
#define		PCCR2_RX_AVAIL_INT	BIT(1)
#define	PCCR3	0x13c
#define		PCCR3_FIFO_DATA_MASK	GENMASK(7, 0)
#define	IBTCR0	0x140
#define		IBTCR0_ADDR_MASK	GENMASK(31, 18) /* [17:16] are RAZ */
#define		IBTCR0_ADDR_SHIFT	16
#define		IBTCR0_SIRQ_MASK	GENMASK(15, 12)
#define		IBTCR0_SIRQ_SHIFT	12
#define		IBTCR0_EN_CLR_SLV_RDP	BIT(3)
#define		IBTCR0_EN_CLR_SLV_WRP	BIT(2)
#define		IBTCR0_EN		BIT(0)
#define	IBTCR1	0x144
#define		IBTCR1_INT_EN_HBUSY	BIT(6)
#define		IBTCR1_INT_EN_H2B	BIT(0)
#define	IBTCR2	0x148
#define		IBTCR2_INT_HBUSY	BIT(6)
#define		IBTCR2_INT_H2B		BIT(0)
#define	IBTCR3	0x14c
#define	IBTCR4	0x150
#define	IBTCR5	0x154
#define	IBTCR6	0x158

#endif

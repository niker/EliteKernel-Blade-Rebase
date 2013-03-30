/*
 * arch/arm/mach-tegra/tegra_pmqos.h
 *
 * Copyright (C) 2012 Paul Reioux (aka Faux123)
 *
 * Author:
 *	faux123 <reioux@gmail.com>
 *
 * History:
 *      -original version (Paul Reioux)
 *      -cleaned since oc was reworked (Dennis Rassmann)
 *      -added comment for T3_VARIANT_BOOST (Dennis Rassmann)
 *      -adapted for grouper (Dennis Rassmann)
 *      -removed distinction between 0boost and xboost
 *      -minimized version
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/* Default constants */
#define CAP_CPU_FREQ_MAX	475000
#define BOOST_CPU_FREQ_MIN	1400000


#define DEF_T3_CPU_MIN_FREQ     51000
#define AUD_T3_CPU_MIN_FREQ     102000
#define PS_AUD_T3_CPU_MIN_FREQ     51000
#define T3_LP_MAX_FREQ     	475000


#define PS_T3_CPU_MAX_FREQ     1150000
#define PS_T3_CPU_MAX_CORES    3


extern unsigned int T3_CPU_MIN_FREQ;
extern unsigned int tegra_pmqos_boost_freq;
extern unsigned int tegra_pmqos_cpu_freq_limits[];

/* EliteKernel Extreme Powersaving*/
extern unsigned int tegra_pmqos_powersave;
extern unsigned int tegra_pmqos_audio;
static inline void update_tegra_pmqos_freqs()
{
	if((tegra_pmqos_powersave == 0) && (tegra_pmqos_audio == 0))
	{
		T3_CPU_MIN_FREQ = DEF_T3_CPU_MIN_FREQ;
	}
	
	if((tegra_pmqos_powersave == 0) && (tegra_pmqos_audio == 1))
	{
		T3_CPU_MIN_FREQ = AUD_T3_CPU_MIN_FREQ;
	}
	
	if((tegra_pmqos_powersave == 1) && (tegra_pmqos_audio == 0))
	{
		T3_CPU_MIN_FREQ = DEF_T3_CPU_MIN_FREQ;
	}
	
	if((tegra_pmqos_powersave == 1) && (tegra_pmqos_audio == 1))
	{
		T3_CPU_MIN_FREQ = PS_AUD_T3_CPU_MIN_FREQ;
	}
}

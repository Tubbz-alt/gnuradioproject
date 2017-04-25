/* -*- c++ -*- */
/*
 * Copyright 2010,2012,2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PACKETIZR_WHITENER_H
#define INCLUDED_PACKETIZR_WHITENER_H

#include <packetizr/api.h>
#include <limits.h>
#include <vector>
#include <gnuradio/blocks/lfsr_15_1_0.h>

namespace gr {
namespace packetizr {
namespace kernel {

class whitener
{
private:
	bool d_use_lfsr;
	blocks::lfsr_15_1_0 d_lfsr;
	unsigned char* d_random_mask;
	unsigned int d_random_mask_length;
	unsigned char d_lsb_mask;

public:
	whitener();

	whitener(std::vector<unsigned char> random_mask, int bits_per_byte);

	whitener(bool use_lfsr, int bits_per_byte);

	static unsigned char
	lsb_mask(int bits_per_byte) {
		return (((unsigned char) - 1) >> ((sizeof(unsigned char) * CHAR_BIT) - (unsigned char) bits_per_byte));
	}

	void
	do_whitening(const unsigned char* data_in, unsigned char* data_out, unsigned int data_length, unsigned int whitening_offset);

	static unsigned char default_random_mask[];
};


} /* namespace kernel */
} /* namespace packetizr */
} /* namespace gr */

#endif /* INCLUDED_PACKETZIR_WHITENER_H */
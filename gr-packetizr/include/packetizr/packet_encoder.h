/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_PACKETIZR_PACKET_ENCODER_H
#define INCLUDED_PACKETIZR_PACKET_ENCODER_H

#include <packetizr/api.h>
#include <gnuradio/digital/api.h>
#include <gnuradio/tagged_stream_block.h>
#include <gnuradio/digital/constellation.h>
#include <gnuradio/digital/packet_header_default.h>
#include <gnuradio/block.h>

namespace gr {
  namespace packetizr {

    /*!
     * \brief <+description of block+>
     * \ingroup packetizr
     *
     */
    class PACKETIZR_API packet_encoder : virtual public gr::tagged_stream_block
    {
     public:
      typedef boost::shared_ptr<packet_encoder> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of packetizr::packet_encoder.
       *
       * To avoid accidental use of raw pointers, packetizr::packet_encoder's
       * constructor is in a private implementation
       * class. packetizr::packet_encoder::make is the public interface for
       * creating new instances.
       */
      static sptr make(const std::vector<int> preamble, gr::digital::constellation_sptr constel_header, gr::digital::constellation_sptr  constel_payload, const gr::digital::packet_header_default::sptr &header_formatter, const std::string &lengthtagname, size_t itemsize);


    };

  } // namespace packetizr
} // namespace gr

#endif /* INCLUDED_PACKETIZR_PACKET_ENCODER_H */


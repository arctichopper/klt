#pragma once

#include <boost/gil/io/typedefs.hpp>

namespace klt
{
    /* Use this for runtime image processing
    #include <boost/gil.hpp>
    #include <boost/gil/extension/dynamic_image/any_image.hpp>
    #include <boost/mp11.hpp>
    using image_t = boost::gil::any_image< boost::gil::gray8_image_t,
                                           boost::gil::gray16_image_t,
                                           boost::gil::rgb8_image_t,
                                           boost::gil::rgb16_image_t >;
    */
    using image_t = boost::gil::rgb8_image_t;

    class i_image
    {
        public:
            virtual image_t& get_image() = 0;
            virtual void read_image() = 0;
            virtual void write_image() = 0;

        protected:
            image_t m_image;
    };
}


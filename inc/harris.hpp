#pragma once

#include <vector>

#include <boost/gil/io/typedefs.hpp>

#include "i_image.hpp"

namespace klt
{
    class harris
    {
        public:
            using image_vector_t = std::vector< std::unique_ptr< klt::i_image > >;

            harris();
            harris( image_vector_t &image_vector);

            void add_image( std::unique_ptr< klt::i_image > image );
            void execute();

        private:
            image_vector_t m_image_vector;
    };
}

#include "harris.hpp"

#include <iostream>

#include <boost/gil/color_convert.hpp>
#include <boost/gil/extension/dynamic_image/any_image_view.hpp>

namespace klt
{
    harris::harris() :
        m_image_vector()
    {
    }

    harris::harris( image_vector_t &image_vector) :
        m_image_vector( std::move( image_vector ) )
    {
    }

    void harris::add_image( std::unique_ptr< klt::i_image > image )
    {
        m_image_vector.push_back( std::move( image ) );
    }

    void harris::execute()
    {
        for( auto& image_ptr : m_image_vector )
        {
            auto view = boost::gil::view( image_ptr->get_image() ); 
            std::cout << "Getting here..." << std::endl;
            std::cout << "Reading image..." << std::endl;
            for( auto it = std::begin( view ); it < std::end( view ); it++ )
            {
                // Study an example of iterating through pixels
            }
            std::cout << std::endl;

            std::cout << "Reading image..." << std::endl;
            for( auto& it : view )
            {
                std::cout << std::hex << static_cast< uint8_t >( it[ 0 ] );
            }
            std::cout << std::endl;
        }
    }
}

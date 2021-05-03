#include <iostream>
#include <string>

#include "image.hpp"
#include "harris.hpp"

int main( int argc, char** argv )
{
    if( argv[ 1 ] == NULL )
    {
        std::cout << "Insert first input image pathname." << std::endl;
        return 1;
    }

    if( argv[ 2 ] == NULL )
    {
        std::cout << "Insert second input image pathname." << std::endl;
        return 1;
    }

    if( argv[ 3 ] == NULL )
    {
        std::cout << "Insert output image pathname." << std::endl;
        return 1;
    }

    auto input_left_filename = std::string( argv[ 1 ] );
    auto input_right_filename = std::string( argv[ 2 ] );
    auto output_filename = std::string( argv[ 3 ] );
    auto image_left = klt::image::pointer( input_left_filename, output_filename );
    auto image_right = klt::image::pointer( input_right_filename, output_filename );

    auto harris = std::make_unique< klt::harris >();
    harris->add_image( std::move( image_left ) );
    harris->add_image( std::move( image_right ) );
    harris->execute();

    return 0;
}

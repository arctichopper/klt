#include <iostream>
#include <string>

#include "image.hpp"

int main( int argc, char** argv )
{
    if( argv[ 1 ] == NULL )
    {
        std::cout << "Insert input image pathname." << std::endl;
        return 1;
    }

    if( argv[ 2 ] == NULL )
    {
        std::cout << "Insert output image pathname." << std::endl;
        return 1;
    }

    auto input_filename = std::string( argv[ 1 ] );
    auto output_filename = std::string( argv[ 2 ] );
    auto image = klt::image::pointer( input_filename, output_filename );

    image->read_image();
    image->write_image();
    return 0;
}

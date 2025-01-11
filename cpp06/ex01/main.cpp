#include "Data.hpp"
#include "Serializer.hpp"

int	main( void )
{
	Data		d( "Hello World" );
	uintptr_t	raw = Serializer::serialize(&d);
	Data		*deserializedPtr = Serializer::deserialize(raw);
	
	std::cout << "Data deserialized: [" << deserializedPtr->getData() << "]" << std::endl;
	return (0);
}

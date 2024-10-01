
#include "shapes_variant.h"

int main(void)
{
    variant::Shapes shapes = variant::makeShapes(1000000);
    variant::drawAllShapes(shapes);
}

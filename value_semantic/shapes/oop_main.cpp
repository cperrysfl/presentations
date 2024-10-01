
#include "shapes_oop.h"

int main(void)
{
    oop::Shapes shapes = oop::makeShapes(1000000);
    oop::drawAllShapes(shapes);
}

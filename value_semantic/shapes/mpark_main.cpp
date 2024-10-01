
#include "shapes_mpark.h"

int main(void)
{
    mpark::Shapes shapes = mpark::makeShapes(1000000);
    mpark::drawAllShapes(shapes);
}

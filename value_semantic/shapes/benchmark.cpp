#include <benchmark/benchmark.h>

#include "shapes_oop.h"
#include "shapes_variant.h"
#include "shapes_mpark.h"

static const int N = 1 * 1000000;

static void BM_drawAllShapesClassicalOop(benchmark::State& state) {
    // Perform setup here
    oop::Shapes shapes = oop::makeShapes(N);

    for (auto _ : state) {
        // This code gets timed
        oop::drawAllShapes(shapes);
    }
}

static void BM_drawAllShapesValueSemantic(benchmark::State& state) {
    // Perform setup here
    variant::Shapes shapes = variant::makeShapes(N);

    for (auto _ : state) {
        // This code gets timed
        variant::drawAllShapes(shapes);
    }
}


static void BM_drawAllShapesMpark(benchmark::State& state) {
    // Perform setup here
    mpark::Shapes shapes = mpark::makeShapes(N);

    for (auto _ : state) {
        // This code gets timed
        mpark::drawAllShapes(shapes);
    }
}

// Register the function as a benchmark

BENCHMARK(BM_drawAllShapesClassicalOop);
BENCHMARK(BM_drawAllShapesValueSemantic);
BENCHMARK(BM_drawAllShapesMpark);

// Run the benchmark
BENCHMARK_MAIN();

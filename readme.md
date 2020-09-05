# interp

Minimal library for running user defined stepwise behaviour over a specific amount of time.

<img src="https://github.com/eschmar/interp/raw/master/img/plot.png" alt="Methods" style="max-width:100%;">

## Requirements

* python
* numpy
* matplotlib
* [`matplotlib-cpp`](https://github.com/lava/matplotlib-cpp)

Some sanity checks might have to be [manually commented out](https://github.com/lava/matplotlib-cpp/blob/70d508fcb7febc66535ba923eac1b1a4e571e4d1/matplotlibcpp.h#L337) in `matplotlib-cpp`.

## Example

Stepwise interpolation from `0.0` to `1.0` using a cubic method over 2 seconds.

```cpp
pew::Interpolator interp([&](double value, uint64_t elapsedMs) mutable {
    // define stepwise behaviour here
    std::cout << "[" << elapsedMs << "\t" << value << "]\n";
    return true; // return false to abort
}, 2000);

interp.setEasing(pew::InterpolatorMethod::cube); // default is linear
interp.setFrequency(120); // default is 60hz
interp.run();
```

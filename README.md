# Fract-ol: Interactive Fractal Renderer

## Overview

The **Fract-ol** project is an introduction to computer graphics using the MiniLibX library. It allows you to explore and render beautiful fractals interactively, such as the **Mandelbrot set** and the **Julia set**. The project combines math, pixel manipulation, and event handling to create a responsive and visually appealing fractal viewer. 🎨🖥️✨

## Features

* Renders different fractals:

  * Mandelbrot set
  * Julia set (with interactive mouse motion)
* Zoom in/out with the mouse wheel for infinite detail.
* Built using **MiniLibX** for lightweight graphics handling.

## Program Details

* **Program Name:** `fractol`
* **Usage:**

  ```bash
  ./fractol mandelbrot
  ./fractol julia
  ./fractol julia <real_part> <imaginary_part>
  ```

  Example:

  ```bash
  ./fractol julia -0.8 0.156
  ```

## Controls

* **Mouse Scroll:** Zoom in/out on fractal.

## Running the Program

1. Clone the repository:

   ```bash
   git clone https://github.com/MohammadHusssein/42-fractol.git
   cd 42-fractol
   ```
2. Compile the program:

   ```bash
   make
   ```
3. Run with a fractal name:

   ```bash
   ./fractol mandelbrot
   ./fractol julia
   ```

## Examples

```bash
./fractol mandelbrot
```

👉 Opens an interactive Mandelbrot set window.
Zoom to explore infinite detail.

```bash
./fractol julia -0.70176 -0.3842
```

👉 Opens a Julia set with given complex parameters.

## Testing

Try different inputs and fractals:

* `./fractol mandelbrot`
* `./fractol julia 0.285 0.01`
* `./fractol julia -0.8 0.156`

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and share with proper attribution. 📜🔓✨

# fract-ol

An interactive fractal visualizer built in C using MiniLibX — part of the 42 Madrid curriculum.

Renders three different fractals in real time, with mouse zoom and keyboard navigation.

---

## Project Structure

```
fract-ol/
├── src/
│   ├── main.c       # Entry point and fractal selection
│   ├── init.c       # Window and image initialization
│   ├── render.c     # Fractal rendering loop
│   ├── draw.c       # Pixel drawing and color mapping
│   └── events.c     # Mouse and keyboard event handling
├── utils/
│   └── utils.c      # Math and helper functions
├── lib/
│   ├── libft/       # Custom C library
│   └── minilibx/    # 42's graphical library
├── makefile
└── README.md
```

---

## Fractals

### Mandelbrot
The classic fractal. Each point on the complex plane is iterated through `z = z² + c` to determine if it escapes to infinity.

```bash
./fractol mandelbrot
```

### Julia
A variation of Mandelbrot where `c` is fixed and the starting point varies. Different `c` values produce wildly different shapes.

```bash
./fractol julia <real> <imaginary>

# Examples
./fractol julia -0.7 0.27
./fractol julia 0.355 0.355
./fractol julia -0.4 0.6
```

### Burning Ship
A variation that uses absolute values in the iteration, producing a fractal that resembles a burning ship from above.

```bash
./fractol burningship
```

---

## Controls

| Input | Action |
|---|---|
| Scroll up | Zoom in |
| Scroll down | Zoom out |
| `W` / `↑` | Move up |
| `S` / `↓` | Move down |
| `A` / `←` | Move left |
| `D` / `→` | Move right |
| `ESC` | Close the window |

---

## Usage

### Requirements

- Linux with X11
- MiniLibX dependencies: `libX11`, `libXext`

### Compilation

```bash
make        # compile
make clean  # remove object files
make fclean # remove object files and binary
make re     # full rebuild
```

### Running

```bash
./fractol mandelbrot
./fractol julia -0.7 0.27
./fractol burningship
```

---

## What I Learned

- Graphics programming with MiniLibX (X11)
- Complex number math and fractal iteration
- Pixel-level image rendering
- Mouse and keyboard event handling
- Zoom and coordinate mapping (screen → complex plane)
- Integrating external libraries in C

---

## Author

**Aitor Alonso Jusdado** — [42 Madrid](https://www.42madrid.com/) — [LinkedIn](https://www.linkedin.com/in/aitor-alonso-jusdado-0ba015153)
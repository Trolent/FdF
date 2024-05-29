# FdF - Wireframe Model Project

Welcome to my FdF project! This project is part of the curriculum at 42 School and involves creating a simple wireframe model of a 3D landscape using the MiniLibX library. The goal is to represent the model in isometric projection by linking various points in space with line segments.

## Objectives

The main objectives of this project are to:

- Get familiar with the MiniLibX library.
- Learn the basics of graphics programming.
- Understand how to place points in space, join them, and view the scene from specific viewpoints.

## Features

- **Isometric Projection**: The program displays the landscape in isometric projection.
- **Smooth Window Management**: The window can be resized, minimized, and changed without issues.
- **User Interaction**: The program allows for various interactions such as zooming, rotating, and translating the model.
- **Clean Exit**: The program exits cleanly when pressing `ESC` or clicking the close button.

## Usage

### Compilation

To compile the project, use the following commands:

```sh
make        # Compiles the library and generates the `fdf` executable.
make clean  # Deletes the compiled object files.
make fclean # Deletes the compiled object files and the executable.
make re     # Fully recompiles the library.
```

## Executing FDF

At execution time, you must specify the path to a .fdf file (some maps are avaiable in the map directory).

```shell
./fdf <map.fdf>
```

Such as

```shell
./fdf maps/MGDS_WHOLE_WORLD_OCEAN1_XL.fdf
```

If the file isn't proprely formated or with the wrong extension name, the program will display ```Error``` and quit. 

## FDF Controls

While fdf is running, the following set of controls are available:

<table>
  <tr><td><strong>Key</strong></td><td><strong>Action</strong></td></tr>
  <tr><td><kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out</td></tr>
  <tr><td><kbd>&nbsp;→&nbsp;</kbd></td><td>Move right</td></tr>
  <tr><td><kbd>&nbsp;←&nbsp;</kbd></td><td>Move left</td></tr>
  <tr><td><kbd>&nbsp;↓&nbsp;</kbd></td><td>Move down</td></tr>
  <tr><td><kbd>&nbsp;↑&nbsp;</kbd></td><td>Move up</td></tr>
  <tr><td><kbd>&nbsp;C&nbsp;</kbd></td><td>Activate/deactivate altitude based color</td></tr>
  <tr><td><kbd>&nbsp;Q&nbsp;</kbd></td><td>Rotate X</td></tr>
  <tr><td><kbd>&nbsp;W&nbsp;</kbd></td><td>Rotate X</td></tr>
  <tr><td><kbd>&nbsp;A&nbsp;</kbd></td><td>Rotate Y</td></tr>
  <tr><td><kbd>&nbsp;S&nbsp;</kbd></td><td>Rotate Y</td></tr>
  <tr><td><kbd>&nbsp;Z&nbsp;</kbd></td><td>Rotate Z</td></tr>
  <tr><td><kbd>&nbsp;X&nbsp;</kbd></td><td>Rotate Z</td></tr>
  <tr><td><kbd>&nbsp;+&nbsp;</kbd></td><td>Increase z range</td></tr>
  <tr><td><kbd>&nbsp;-&nbsp;</kbd></td><td>Decrease z range</td></tr>
  <tr><td><kbd>&nbsp;L&nbsp;</kbd></td><td>Show/hide lines</td></tr>
  <tr><td><kbd>&nbsp;D&nbsp;</kbd></td><td>Show/hide diagonals</td></tr>
  <tr><td><kbd>&nbsp;T&nbsp;</kbd></td><td>View Front</td></tr>
  <tr><td><kbd>&nbsp;I&nbsp;</kbd></td><td>View Iso</td></tr>
  <tr><td><kbd>&nbsp;Y&nbsp;</kbd></td><td>View lateral X</td></tr>
  <tr><td><kbd>&nbsp;G&nbsp;</kbd></td><td>View lateral Y</td></tr>
  <tr><td><kbd>&nbsp;U&nbsp;</kbd></td><td>Reset original Z value</td></tr>
  <tr><td><kbd>&nbsp;R&nbsp;</kbd></td><td>Recenter</td></tr>
  <tr><td><kbd>&nbsp;ESC&nbsp;</kbd></td><td>Quit program</td></tr>
</table>

## Educational Value

This project is crucial for learning:

- **Graphics Programming:** Basics of rendering 3D models and handling user input for graphics applications.
- **Memory Management:** Handling dynamic memory allocation and deallocation efficiently.
- **Modular Programming:** Organizing code into reusable modules.
- **Debugging and Testing:** Developing strong debugging and testing skills to ensure the robustness of the program.

---

Thank you for taking the time to check out this project! I hope it will be useful in your own C projects.

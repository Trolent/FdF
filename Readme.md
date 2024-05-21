# fdf

<p align="center">
  <img src="https://github.com/Trolent/Trolent/blob/e2a84c046e74211bac5266747ef54d4af820baf6/Badges/fdfm.png" alt="FDF badge"/>
Finished: 28/02/2024.

Grade: 125%.
</p>

Fil de Fer (wireframe) also known as FDF is one of the first graphical projects at 42 school. The goal is to develop a program that reads a ".fdf" file containing coordinates of a landscape and displays it as a wireframe model in isometric projection. This specific implementation also allows you to rotate, zoom, change the altitude ratio ...


## Installing and Compiling FDF

Clone the repository, including the embedded MiniLibX repository:
```shell
git clone git@github.com:Trolent/FdF.git && cd FdF && git submodule init && git submodule update
```

make rules are

Compile using ```make```.

## Executing FDF

At execution time, you must specify the path to a .fdf file.

```shell
./fdf [path to .fdf file]
```

Such as

```shell
./fdf maps/MGDS_WHOLE_WORLD_OCEAN1_XL.fdf
```

If the file isn't proprely formated or with the wrong extension name, the program will display ```Error```and quit. 

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

# Screenshots

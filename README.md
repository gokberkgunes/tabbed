# tabbed
Tabbed is a plain tabbed X window container. This fork of tabbed includes a few
patches to bring ease of usage. Patches included in this package are given in
the `patches` along with their original `.diff` files.

Patches and extra functionality included in this fork are given below.
- auto-hide: Hide tab bar if there is only one tab open. There are some other
  ways to approach concealing tabs. For example, it is possible to show tabs
  when a modifier key is pressed down. However, this approach not only requires
  extra code to process key press events but also blocks the user to recognize
  which tabs are open.
- client-number: Show numbers from 1 to n, where n is the last window. This
  helps user to quickly switch between tabs with `CTRL+i` by increasing
  recognition.
- cwd: New spawned tabs will be opened in the same working directory. This
  behavior is a must for terminal windows, in `inactive` folder under `patches`
  directory, one may find an older implementation of this approach. Old
  approach uses shell environmental variable and it alters and tracks `cd`
  command. This approach makes it prone to failure; if a script uses `cd`
  command, the new terminal will mistakenly spawn at that location.

## Configuration
Edit `config.h` for keybindings, colors, function calls and so forth.

## Installation
1. Edit `Makefile` to match your operating system and specific requirements.
   Note that, Xlib header files are required.

2. Run the below command to compile and install tabbed to the system.
```sh
doas make clean install
```

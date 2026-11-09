# cub3D

A first-person maze renderer written in C with MiniLibX, using **raycasting** — the technique behind Wolfenstein 3D. The final graphics project of the 42 Common Core.

## Build

Needs X11 development headers (`libx11-dev`, `libxext-dev`) on Linux.

```bash
make
```

## Run

```bash
./cub3D asset/map/maze.cub
```

Maps included in `asset/map/`: `maze.cub`, `byte.cub`, `krabu.cub`, `wtf.cub`, plus deliberately broken ones under `asset/map/wrong/` to exercise the parser.

### Controls

| Key | Action |
|---|---|
| `W` `A` `S` `D` | move |
| `←` `→` | turn |
| mouse | look around |
| `ESC` | quit |

## The map format

A `.cub` file holds the texture and colour configuration, then the grid:

```
NO ./asset/textures/north.xpm
SO ./asset/textures/south.xpm
WE ./asset/textures/west.xpm
EA ./asset/textures/east.xpm

F 220,100,0
C 225,30,0

1111111111
1000000011
1011000011
1000000N11
1111111111
```

`0` is floor, `1` is wall, and `N` `S` `E` `W` is the player's start position and facing. The grid must be closed: validity is checked with a **flood fill** from the player's position, so any gap leaking to the outside is rejected before rendering starts.

## How the rendering works

For every column of the window, a ray is cast from the player into the scene until it hits a wall. The distance to that hit gives the height of the wall slice to draw, and the exact hit coordinate gives the horizontal offset into the wall texture. Floor and ceiling are filled with their configured colours.

Walls are textured per face, so north, south, east and west walls can use different images.

## Minecraft mode: breaking and placing blocks

The part of this project I went furthest on. Walls are not static — you can mine them and build with them, with the same feel as Minecraft.

**Breaking.** Hold the left mouse button while looking at a wall. A second ray (`raycast_to_pointed_block`) resolves which tile the crosshair is on, and destruction starts on that tile. It runs through 4 stages over `TT_DESTROY` (0.5 s), and each stage draws a heavier crack overlay from `asset/textures/minecraft/destroy/`. Finish it and the wall turns into open floor, and the block goes into your inventory.

Two details make it feel right:

- **releasing early cancels the progress** — the original block is restored, exactly like letting go of the button in Minecraft
- **looking away mid-break resets it too**, so you cannot chip at several blocks in parallel

**Placing.** Right-click an empty tile with at least one block in your inventory and a wall appears there, decrementing the counter. Breaking and placing form a closed loop.

**How the state is stored.** The destruction stage is encoded in the map character itself: the tile is swapped to `'5'` and decremented each stage, down to `'O'` for air. So the renderer needs no extra structure — it reads the stage straight off the map grid, and the saved original character is kept aside to restore it on cancel.

The block textures are a Minecraft-style set: bricks, and the ore family (diamond, emerald, gold, iron, lapis, redstone) including their deepslate variants.

### Other additions beyond the subject

- **mouse look** in addition to keyboard rotation
- a **minimap** overlay
- a **HUD**: block counter, destruction progress bar, reticle, FPS counter and a live key-state display
- several texture sets, including a 4K one

## Layout

```
inc/           headers
src/           parsing, init, raycasting, rendering, hooks, teardown
asset/map/     maps, valid and invalid
asset/textures/ wall textures
lib/libft/     my own C library
```

## Note on repository size

`asset/` is about 136 MB because of the high-resolution texture sets. Cloning takes a while; `git clone --depth 1` helps.

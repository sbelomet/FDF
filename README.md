# 🗺 FDF 🗺

`Wireframe map viewer`

### Useful resources

**📚 [`GITBOOK`](https://42-cursus.gitbook.io/guide/rank-02/fdf) 📚** - Gitbook for fdf

**🖼 [`GITBOOK MLX`](https://42-cursus.gitbook.io/guide/minilibx) 🖼** - Gitbook for MLX

**📈 [`BRESENHAM`](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) 📉** - Line drawing algorithm

**✖️ [`MATRICES DE ROTATIONS`](https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions) ✖️** - Rotation matrices

## 

### What to do

The program should take in a custom map file and show a wireframe rendition of it. A map with the `.fdf` looks like this:

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

and should result in this:

<img width="720" alt="Screen Shot 2024-01-03 at 3 02 41 PM" src="https://github.com/sbelomet/FDF/assets/148435833/2dba8a1c-18d2-49b9-9964-689b3bca8330">

Translation, rotation, zoom and color customization were also added.

##

### Usage

1. `make`
2. `./fdf <map.fdf>` (plenty of maps in `maps/`)

##

### A few images

<img width="720" alt="Screen Shot 2024-01-03 at 3 52 59 PM" src="https://github.com/sbelomet/FDF/assets/148435833/20819ddb-e2dc-4a10-8635-1d0d06d5d0ac">

<img width="720" alt="Screen Shot 2024-01-03 at 3 54 58 PM" src="https://github.com/sbelomet/FDF/assets/148435833/837ddac3-3a9b-47ae-9822-c5be3cbd0cc9">

<img width="720" alt="Screen Shot 2024-01-03 at 3 57 31 PM" src="https://github.com/sbelomet/FDF/assets/148435833/14edd9cf-d642-4765-9508-3d92ccbf1c90">

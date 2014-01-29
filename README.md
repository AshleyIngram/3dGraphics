#3D Graphics
Coursework for  COMP3811 (CR31) Computer Graphics at the University of Leeds. 

##Assignments
There are 5 branches, each corresponding to 1 coursework.

###Coursework 1
Coursework 1 is a basic exercise in OpenGL. It is a rotating, 2D triangle rendered using simple OpenGL primitives. The right mouse button can be used to control rotation speed, the left mouse button can be used to move the triangle around the canvas.

###Coursework 2
Rendering the Platonic Solids (Tetrahedron, Cube, Octahedron, Dodecahedron, Icosahedron) by hard-coding the mesh. The solids can be rendered using either points, lines or triangles, and there is a mode to give each triangle an alternating colour. 

The solids can also be rotated around 3 dimensions. 

###Coursework 3
Rendering various spherical-like objects (Sphere, Cylinder, Cone, Torus). The shapes all have normals computed and can be lit using flat or smooth shading. The sphere is textured to look like the earth.

###Coursework 4
A stick man drawn using a hierarchy of shapes. Animation using keyframing is used to make the man run in a circle. 

##Project
The final assignment was an open-ended project, demonstrating knowledge of 4 'advanced' graphical techniques.

My project is a simple 3D Christmas scene. The following techniques are used in creating the scene.

###L-Systems
A simple L-System is used to describe how the Christmas Tree. A Pseudo-Random Number Generator is used to place baubles at the end of random branches.

###Particle Systems
A Particle System is used for snowfall. Each snowflake is a particle. The snowflakes are also billboards, to reduce the polygon count (as there may be a high number of snowflakes).

###Terrain
Terrain is implemented using a basic grid system. When snow collides with the terrain, the nearest grid point is raised, in order to simulate the snow settling on the ground. The height increase will distribute around nearby grid points in order to prevent 'spiking' behaviour.

###Shadows
Shadows are attempted using the Shadow Mapping technique, implemented using Vertex and Fragment shaders. The shadow is cast from a fixed light source. Unfortunately, shadows are not working correctly, and will flicker between scenes. 

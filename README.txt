Dual Contouring Sample (DCS)
==============================

Objective for this fork of DCS
----------------------------------

Allow Opticks https://bitbucket.org/simoncblyth/opticks to use DualContouringSample
as an optional external to provide adaptive resolution polygonalization of CSG geometry 
defined via implicit signed distance functions.

Specifically:

* remove windows specifics
* remove visualization machinery 
* add interface to flexibly provide different implicit functions based
  on std::function (requiring C++11 compiler)



Original README
-----------------

A sample Dual Contouring implementation. For more info see http://ngildea.blogspot.co.uk/2014/11/implementing-dual-contouring.html

The octree code is based on the original reference code by Tao Ju. The QEF implementation was written by /u/unzret (on reddit.com).
All other code is written by Nicholas Gildea and free for any purpose, assuming that does not conflict with another license.

The sample depends on SDL2, GLM and GLEW. I don't think the particular version matters (beyond the paths in the .vcxproj file). 

Only build materials for VS2013 are provided but it should be easy to move to another environment.

The controls are:
	- hold left mouse and drag to rotate the view
	- use the mouse wheel to zoom in/out
	- press F1 to render a wireframe
	- press F2 to regenerate the octree using a new error threshold (and generate a new mesh)

Send any questions to nick.gildea@gmail.com or @ngildea85 on Twitter


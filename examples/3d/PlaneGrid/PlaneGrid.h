﻿#ifndef PLANE_GRID_INCLUDE
#define PLANE_GRID_INCLUDE

#include<hgl/VectorMath.h>
namespace hgl
{
	namespace graph
	{
		class Renderable;

		class PlaneGrid
		{
			Renderable *grid[3];

		public:

			PlaneGrid(int,int);
			~PlaneGrid();

			void Render(const Matrix4f *,const Matrix4f *);
		};//class PlaneGrid
	}//namespace graph
}//namespace hgl
#endif//PLANE_GRID_INCLUDE

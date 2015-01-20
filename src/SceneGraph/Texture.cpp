﻿#include<hgl/graph/Texture.h>
#include<hgl/Other.h>
#include<hgl/graph/Image.h>
#include<string.h>

namespace hgl
{
	namespace graph
	{
		Texture::Texture()				//请使用CreateTexture()来创建贴图,函数在Render.H中定义
		{
			index=type=video_format=0;

			bitmap_data=0;

			min_filter=mag_filter=HGL_FILTER_LINEAR;
		}
	}//namespace graph

	namespace graph
	{
		Texture2D::Texture2D()
		{
			width=height=wrap_s=wrap_t=0;
		}

		/**
		* 根据位图设置一个贴图
		* @param bmp 位图指针
		* @param vf 显存格式
		* @param ltp 加载贴图处理选项
		* @return 是否创建成功
		*/
		bool Texture2D::SetImage(Bitmap2D *bmp,uint vf,uint ltp)
		{
			if(!bmp)return(false);

			return SetImage(bmp->GetWidth(),						//宽
							bmp->GetHeight(),						//高
							bmp->GetData(),							//数据
							bmp->GetDataLength(),					//数据长度
							bmp->GetFormat(),						//数据格式
							vf,										//显存格式
							ltp);									//加载参数
		}

		bool Texture2D::ChangeImage(Bitmap2D *bmp,uint l,uint t)
		{
			if(!bmp)return(false);

			return ChangeImage(	l,
								t,
								bmp->GetWidth(),
								bmp->GetHeight(),
								bmp->GetData(),
								bmp->GetDataLength(),
								bmp->GetFormat());
		}

		/**
		* 从文件中加载一个贴图
		* @param filename 文件名
		* @param vf 显存格式
		* @param ltp 加载贴图处理选项
		* @return 是否加载成功
		*/
		bool Texture2D::LoadFile(const OSString &filename,uint vf,uint ltp)
		{
			Bitmap2D bmp;

			if(!bmp.LoadFromTextureFile(filename))
				return(false);

			return SetImage(&bmp,vf,ltp);
		}
	}//namespace graph
}//namespace hgl

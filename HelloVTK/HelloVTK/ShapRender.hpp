//
//  ShapRender.hpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/13.
//

#ifndef ShapRender_hpp
#define ShapRender_hpp

#include <stdio.h>
#include <vtkSmartPointer.h>

class vtkProp;
class vtkTexture;

class ShapeRender {
public:
    ShapeRender();
    ~ShapeRender();
    
public:
    //圆柱渲染
    void CylinderRender();
    //正方体渲染
    void CubeRender();
    //直线渲染
    void LineRender();
    //折线渲染
    void PolyLineRender();
    //三角形渲染
    void TriangleRender();
    //正方形渲染
    void SquareRender();
    //圆锥渲染
    void ConeRender();
    //球体渲染
    void SphereRender();
    //文本渲染
    void TextRender();
    //按钮渲染
    void ButtonRender();
    //地球渲染
    void EarthRender();
    
private:
    //VTK渲染
    void VTKRender(vtkProp* actor);
    void init();
    
private:
    vtkSmartPointer<vtkTexture> m_texture;
    
};


#endif /* ShapRender_hpp */

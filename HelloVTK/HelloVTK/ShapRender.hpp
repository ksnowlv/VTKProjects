//
//  ShapRender.hpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/13.
//

#ifndef ShapRender_hpp
#define ShapRender_hpp

#include <stdio.h>

class vtkProp;

class ShapeRender {
public:
    ShapeRender();
    ~ShapeRender();
    
public:
    //圆柱
    void CylinderRender();
    //正方体
    void CubeRender();
    //直线
    void LineRender();
    //折线
    void PolyLineRender();
    //三角形
    void TriangleRender();
    //正方形
    void SquareRender();
    //圆锥
    void ConeRender();
    
private:
    void VTKRender(vtkProp* actor);
    
};


#endif /* ShapRender_hpp */

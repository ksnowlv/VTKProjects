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
    void CylinderRender();
    void CubeRender();
    void LineRender();
    void PolyLineRender();
    
private:
    void VTKRender(vtkProp* actor);
    
};


#endif /* ShapRender_hpp */

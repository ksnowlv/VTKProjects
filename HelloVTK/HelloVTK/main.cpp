//
//  main.cpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/12.
//

#include <iostream>
#include "ShapRender.hpp"


int main() {
    
    std::unique_ptr<ShapeRender> render(std::make_unique<ShapeRender>());

    //render->CylinderRender();
    //render->CubeRenderWithImageCode();
    //render->LineRender();
    //render->PolyLineRender();
    //render->TriangleRender();
   // render->SquareRender();
    //render->ConeRender();
    render->SphereRender();
    

    
    return 0;
}


